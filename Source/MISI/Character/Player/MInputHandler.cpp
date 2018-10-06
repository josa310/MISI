// Fill out your copyright notice in the Description page of Project Settings.

#include "MInputHandler.h"

UMInputHandler::UMInputHandler(): _trigger(false)
{

}

void UMInputHandler::sanitize()
{
	_sanitizedMovement = _rawMovement.ClampAxes(-1.0f, 1.0f);
	_sanitizedRotation = _rawRotation.ClampAxes(-1.0f, 1.0f);

	_rawMovementSize = _sanitizedMovement.Size();
	_rawRotationSize = _sanitizedRotation.Size();

	if (_sanitizedRotation.X > 0 || _sanitizedRotation.Y > 0)
	{
		_sanitizedRotation = _rawRotation.GetSafeNormal();
	}

	_rawMovement.Set(0.0f, 0.0f);
	_rawRotation.Set(0.0f, 0.0f);
}

// GETTERS

void UMInputHandler::moveY(float y)
{
	_rawMovement.Y = y;
}

void UMInputHandler::moveX(float x)
{
	_rawMovement.X = x;
}

FVector2D UMInputHandler::getMovement()
{
	return _sanitizedMovement;
}

void UMInputHandler::turnX(float x)
{
	_rawRotation.X = x;
}

void UMInputHandler::turnY(float y)
{
	_rawRotation.Y = y;
}

void UMInputHandler::setTrigger(bool pulled)
{
	_trigger = pulled;
}


// SETTERS
FVector2D UMInputHandler::getRotation()
{
	return _sanitizedRotation;
}

bool UMInputHandler::isInMovementDeadZone(float deadZone)
{
	return  deadZone > _rawMovementSize;
}

bool UMInputHandler::isInRotationDeadZone(float deadZone)
{
	return deadZone > _rawRotationSize;
}

float UMInputHandler::getRotationAngle()
{
	float rad = FMath::Atan2(_sanitizedRotation.X, -_sanitizedRotation.Y);
	float angle = FMath::RadiansToDegrees(rad);

	return angle;
}

bool UMInputHandler::triggerPulled()
{
	return _trigger;
}