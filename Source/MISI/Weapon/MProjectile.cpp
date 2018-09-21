// Fill out your copyright notice in the Description page of Project Settings.

#include "MProjectile.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"

// Sets default values
AMProjectile::AMProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	_movementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileStart"));

	_collider = CreateDefaultSubobject<USphereComponent>(TEXT("Collider"));
	SetRootComponent(_collider);

	_mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ProjectileMesh"));
	_mesh->AttachTo(RootComponent);
}

// Called when the game starts or when spawned
void AMProjectile::BeginPlay()
{
	Super::BeginPlay();
	
	GetWorldTimerManager().SetTimer(_timer, this, &AMProjectile::kill, 2, false);
}

// Called every frame
void AMProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMProjectile::kill()
{
	Destroy();
}

