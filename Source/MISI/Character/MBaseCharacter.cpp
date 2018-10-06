// Fill out your copyright notice in the Description page of Project Settings.

#include "MBaseCharacter.h"


// Sets default values
AMBaseCharacter::AMBaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMBaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMBaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMBaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

