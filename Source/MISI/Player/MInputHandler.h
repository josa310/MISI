// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MInputHandler.generated.h"

/**
*
*/
UCLASS()
class MISI_API UMInputHandler : public UObject
{
	GENERATED_BODY()

protected:
	FVector2D _rawMovement;
	FVector2D _sanitizedMovement;
	FVector2D _rawRotation;
	FVector2D _sanitizedRotation;

	bool _trigger;
	float _rawMovementSize;
	float _rawRotationSize;

public:
	UMInputHandler();

	void sanitize();
	void moveX(float x);
	void moveY(float y);

	void turnX(float x);
	void turnY(float y);

	void setTrigger(bool pulled);

	FVector2D getMovement();
	FVector2D getRotation();

	bool isInMovementDeadZone(float deadZone);
	bool isInRotationDeadZone(float deadZone);

	float getRotationAngle();

	bool triggerPulled();
};