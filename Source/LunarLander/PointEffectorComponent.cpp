// Fill out your copyright notice in the Description page of Project Settings.

#include "PointEffectorComponent.h"
#include "Ship.h"

UPointEffectorComponent::UPointEffectorComponent()
{

    OnComponentBeginOverlap.AddDynamic(this, &UPointEffectorComponent::OnBeginOverlap);
    OnComponentEndOverlap.AddDynamic(this, &UPointEffectorComponent::OnEndOverlap);

    PrimaryComponentTick.bCanEverTick = true;
    bTickInEditor = true;
}

void UPointEffectorComponent::OnBeginOverlap(UPrimitiveComponent *Comp, AActor *OtherActor, UPrimitiveComponent *OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult)
{
    Ship = Cast<AShip>(OtherActor);
    if (Ship)
    {
        // FVector Direction = UKismetMathLibrary::GetDirectionUnitVector(Ship->GetActorLocation(), GetComponentLocation());
        UE_LOG(LogTemp, Display, TEXT("IN"));
        bIsShipInRange = true;
    }
}

void UPointEffectorComponent::OnEndOverlap(UPrimitiveComponent *Comp, AActor *OtherActor, UPrimitiveComponent *OtherComp, int32 OtherBodyIndex)
{
    if (OtherActor->IsA(AShip::StaticClass()))
    {
        UE_LOG(LogTemp, Display, TEXT("OUT"));
        Ship = nullptr;
        bIsShipInRange = false;
    }
}

