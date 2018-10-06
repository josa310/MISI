// Fill out your copyright notice in the Description page of Project Settings.

#include "MPlayerController.h"
#include "MPlayer.h"
#include "MInputHandler.h"

AMPlayerController::AMPlayerController()
{
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Crosshairs;
	_input = CreateDefaultSubobject<UMInputHandler>("InputHandler");
}

void AMPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);

	_input->sanitize();
}

void AMPlayerController::SetupInputComponent()
{
	// set up gameplay key bindings
	Super::SetupInputComponent();

	InputComponent->BindAxis("MoveRight", this, &AMPlayerController::moveRight);
	InputComponent->BindAxis("MoveForward", this, &AMPlayerController::moveForward);
	InputComponent->BindAction("Fire", EInputEvent::IE_Pressed, this, &AMPlayerController::onPullTrigger);
	InputComponent->BindAction("Fire", EInputEvent::IE_Released, this, &AMPlayerController::onReleaseTrigger);

	// support touch devices 
}

void AMPlayerController::moveForward(float value)
{
	_input->moveX(value);
}

void AMPlayerController::moveRight(float value)
{
	_input->moveY(value);
}

void AMPlayerController::Possess(APawn* InPawn)
{
	Super::Possess(InPawn);

	AMPlayer* character = Cast<AMPlayer>(InPawn);
	if (character)
	{
		character->setInput(_input);
	}
}

void AMPlayerController::onPullTrigger()
{
	_input->setTrigger(true);
}

void AMPlayerController::onReleaseTrigger()
{
	_input->setTrigger(false);
}