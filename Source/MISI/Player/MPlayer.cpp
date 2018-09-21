// Fill out your copyright notice in the Description page of Project Settings.

#include "MPlayer.h"
#include "MInputHandler.h"
#include "Weapon/MWeapon.h"
#include "Engine/World.h"

// Sets default values
AMPlayer::AMPlayer()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AMPlayer::BeginPlay()
{
	Super::BeginPlay();

	setWeapon();
}

// Called every frame
void AMPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	move();
}

// Called to bind functionality to input
void AMPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void AMPlayer::setInput(UMInputHandler* input)
{
	_inputHandler = input;
}

void AMPlayer::move()
{
	bool canMove = (_inputHandler != NULL) && (!_inputHandler->isInMovementDeadZone(0.2));
	if (!canMove)
	{
		return;
	}

	AddMovementInput(FVector(1, 0, 0), _inputHandler->getMovement().X);
	AddMovementInput(FVector(0, 1, 0), _inputHandler->getMovement().Y);
}

void AMPlayer::setWeapon()
{
	if (_weaponPrototype)
	{
		UWorld* const world = GetWorld();
		if (world)
		{
			FActorSpawnParameters spawnParams;
			spawnParams.Owner = this;
			spawnParams.Instigator = Instigator;

			FVector location = FVector::ZeroVector;
			FRotator rotation = FRotator::ZeroRotator;

			_weapon = world->SpawnActor<AMWeapon>(_weaponPrototype, location, rotation, spawnParams);
			
			_weapon->getRoot()->AttachTo(GetMesh(), "weapon");
		}
	}
}