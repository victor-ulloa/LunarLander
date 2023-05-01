// Fill out your copyright notice in the Description page of Project Settings.

#include "EndPlatform.h"
#include "Components/BoxComponent.h"
#include "Ship.h"

// Sets default values
AEndPlatform::AEndPlatform()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PlatformMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PlatformMesh"));
	RootComponent = PlatformMesh;

	EndArea = CreateDefaultSubobject<UBoxComponent>(TEXT("EndArea"));
    EndArea->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void AEndPlatform::BeginPlay()
{
	Super::BeginPlay();
	EndArea->OnComponentBeginOverlap.AddDynamic(this, &AEndPlatform::OnBeginOverlap);
	EndArea->OnComponentEndOverlap.AddDynamic(this, &AEndPlatform::OnEndOverlap);
}

// Called every frame
void AEndPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AEndPlatform::OnBeginOverlap(UPrimitiveComponent *Comp, AActor *OtherActor, UPrimitiveComponent *OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult)
{
	if (AShip *Ship = Cast<AShip>(OtherActor))
    {
		Ship->bIsOnEndPlatform = true;
    }
}

void AEndPlatform::OnEndOverlap(UPrimitiveComponent *Comp, AActor *OtherActor, UPrimitiveComponent *OtherComp, int32 OtherBodyIndex)
{
	if (AShip *Ship = Cast<AShip>(OtherActor))
    {
        Ship->bIsOnEndPlatform = false;
    }
}
