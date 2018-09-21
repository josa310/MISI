// Fill out your copyright notice in the Description page of Project Settings.

#include "MWeapon.h"
#include "MProjectile.h"
#include "Components/ArrowComponent.h"


// Sets default values
AMWeapon::AMWeapon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	_mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("WeaponMesh"));
	SetRootComponent(_mesh);

	_projectileStart = CreateDefaultSubobject<UArrowComponent>(TEXT("ProjectileStart"));
	_projectileStart->AttachTo(RootComponent);

	_firing = false;
	_fireRate = 1;
}

// Called when the game starts or when spawned
void AMWeapon::BeginPlay()
{
	Super::BeginPlay();
	
	pullTrigger();
}

// Called every frame
void AMWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMWeapon::pullTrigger()
{
	if (_firing)
	{
		return;
	}

	GetWorldTimerManager().SetTimer(_timer, this, &AMWeapon::fire, 1.0f / _fireRate, true);
	_firing = true;
	fire();
}

void AMWeapon::releaseTrigger()
{
	if (!_firing)
	{
		return;
	}

	_firing = false;
	GetWorldTimerManager().ClearTimer(_timer);
}

void AMWeapon::fire()
{
	if (_projectileType)
	{
		UWorld* const world = GetWorld();
		if (world)
		{
			FActorSpawnParameters spawnParams;
			spawnParams.Owner = this;
			spawnParams.Instigator = Instigator;


			FTransform transform = _projectileStart->GetComponentTransform();
			world->SpawnActor<AMProjectile>(_projectileType, transform.GetLocation(), transform.GetRotation().Rotator(), spawnParams);
		}
	}
}

USceneComponent* AMWeapon::getRoot()
{
	return RootComponent;
}
