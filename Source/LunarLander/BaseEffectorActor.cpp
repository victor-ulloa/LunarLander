// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseEffectorActor.h"
#include "PointEffectorComponent.h"

// Sets default values
ABaseEffectorActor::ABaseEffectorActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = Mesh;

	PointEffector = CreateDefaultSubobject<UPointEffectorComponent>(TEXT("PointEffector"));
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

}

