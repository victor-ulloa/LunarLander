// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseEffectorActor.h"
#include "PointEffectorComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "Ship.h"

// Sets default values
ABaseEffectorActor::ABaseEffectorActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = Mesh;

	PointEffectorComponent = CreateDefaultSubobject<UPointEffectorComponent>(TEXT("PointEffector"));
	PointEffectorComponent->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ABaseEffectorActor::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ABaseEffectorActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (PointEffectorComponent && PointEffectorComponent->bIsShipInRange)
	{
		FVector Direction = UKismetMathLibrary::GetDirectionUnitVector(PointEffectorComponent->Ship->GetActorLocation(), PointEffectorComponent->GetComponentLocation());
		if (PointEffectorComponent->bIsPush)
		{
			Direction *= -1;
		}
		// UE_LOG(LogTemp, Display, TEXT("%f %f %f"), Direction.X, Direction.Y, Direction.Z);
		PointEffectorComponent->Ship->AddForce(Direction, PointEffectorComponent->Force);
	}
}
