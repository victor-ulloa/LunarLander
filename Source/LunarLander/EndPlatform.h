// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EndPlatform.generated.h"

class UBoxComponent;

UCLASS()
class LUNARLANDER_API AEndPlatform : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AEndPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Components", meta = (AllowPrivateAccess = true))
	UStaticMeshComponent *PlatformMesh;
	UPROPERTY(EditAnywhere, Category = "Components", meta = (AllowPrivateAccess = true))
	UBoxComponent *EndArea;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UFUNCTION()
	void OnBeginOverlap(UPrimitiveComponent *Comp, AActor *OtherActor, UPrimitiveComponent *OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult);
	UFUNCTION()
	void OnEndOverlap(UPrimitiveComponent *Comp, class AActor *OtherActor, class UPrimitiveComponent *OtherComp, int32 OtherBodyIndex);
};
