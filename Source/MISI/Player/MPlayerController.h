// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MPlayerController.generated.h"

/**
*
*/
UCLASS()
class MISI_API AMPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AMPlayerController();

protected:

	UPROPERTY()
		class UMInputHandler* _input;

	// Begin PlayerController interface
	virtual void PlayerTick(float DeltaTime) override;
	virtual void SetupInputComponent() override;

	/** Input handlers for SetDestination action. */
	void moveRight(float value);
	void moveForward(float value);

	void turnX(float x);
	void turnY(float y);

	void onPullTrigger();
	void onReleaseTrigger();

	virtual void Possess(APawn* InPawn) override;
};