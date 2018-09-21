// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MPlayer.generated.h"

UCLASS()
class MISI_API AMPlayer : public ACharacter
{
	GENERATED_BODY()

public:
	AMPlayer();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void setInput(class UMInputHandler* input);

	UFUNCTION()
	void setWeapon();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY()
	class UMInputHandler* _inputHandler;

	UPROPERTY(EditAnywhere, Category = "Weapon")
	TSubclassOf<class AMWeapon> _weaponPrototype;

	UPROPERTY(BlueprintReadOnly, Category = "Weapon")
	class AMWeapon* _weapon;

	void move();
};