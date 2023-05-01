// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SphereComponent.h"
#include "PointEffectorComponent.generated.h"

class AShip;

/**
 *
 */
UCLASS()
class LUNARLANDER_API UPointEffectorComponent : public USphereComponent
{
	GENERATED_BODY()

public:
	UPointEffectorComponent();

	UPROPERTY(EditAnywhere, Category = "Effector")
	bool bIsShipInRange;
	UPROPERTY(EditAnywhere, Category = "Effector")
	AShip *Ship;
	UPROPERTY(EditAnywhere, Category = "Effector")
	float Force;
	UPROPERTY(EditAnywhere, Category = "Effector")
	bool bIsPush;

private:
	UFUNCTION()
	void OnBeginOverlap(UPrimitiveComponent *Comp, AActor *OtherActor, UPrimitiveComponent *OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult);
	UFUNCTION()
	void OnEndOverlap(UPrimitiveComponent *Comp, class AActor *OtherActor, class UPrimitiveComponent *OtherComp, int32 OtherBodyIndex);
};