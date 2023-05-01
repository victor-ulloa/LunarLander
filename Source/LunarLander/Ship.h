// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Ship.generated.h"

class UCameraComponent;
class UInputMappingContext;
class UInputAction;
class UCapsuleComponent;
struct FInputActionValue;

UCLASS()
class LUNARLANDER_API AShip : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AShip();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = true))
	UCameraComponent *Camera;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = true))
	UStaticMeshComponent *ShipMesh;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Input)
	UInputMappingContext *ShipMappingContext;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Input)
	UInputAction *ThrustAction;

	void Thrust(const FInputActionValue &Value);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void AddForce(FVector Direction, float Force);

	UPROPERTY(EditAnywhere, Category = "Status")
	bool bIsOnEndPlatform;

private:
	UPROPERTY(EditAnywhere, Category = Input)
	float VerticalThrusterForce;
	UPROPERTY(EditAnywhere, Category = Input)
	float HorizontalThrusterForce;
	UPROPERTY(EditAnywhere, Category = "Health")
	float Health;

	UFUNCTION()    
    void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

};
