// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MWeapon.generated.h"

UCLASS()
class MISI_API AMWeapon : public AActor
{
	GENERATED_BODY()

	DECLARE_EVENT(AMWeapon, FireEvent);
	
public:	
	// Sets default values for this actor's properties
	AMWeapon();

	//FireEvent& onFire() {return }

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Mesh")
	class USkeletalMeshComponent* _mesh;

	UPROPERTY(EditAnywhere, Category = "Projectile")
	class UArrowComponent* _projectileStart;

	UPROPERTY(EditAnywhere, Category = "Projectile")
	TSubclassOf<class AMProjectile> _projectileType;

	UPROPERTY(EditAnywhere, Category = "Projectile")
	class AMProjectile* _projectile;

	UPROPERTY(EditAnywhere, Category = "Weapon")
	uint32 _fireRate;

	uint32 _firing;

	FTimerHandle _timer;

	void fire();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void pullTrigger();
	
	UFUNCTION()
	void releaseTrigger();

	UFUNCTION(BlueprintCallable)
	class USceneComponent* getRoot();
};
