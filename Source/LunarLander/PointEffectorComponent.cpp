// Fill out your copyright notice in the Description page of Project Settings.

#include "PointEffectorComponent.h"

UPointEffectorComponent::UPointEffectorComponent()
{
    OnComponentBeginOverlap.AddDynamic(this, &UPointEffectorComponent::OnBeginOverlap);
    OnComponentEndOverlap.AddDynamic(this, &UPointEffectorComponent::OnEndOverlap);
}

void UPointEffectorComponent::OnBeginOverlap(UPrimitiveComponent *Comp, AActor *OtherActor, UPrimitiveComponent *OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult)
{
    UE_LOG(LogTemp, Display, TEXT("IN"));
}

void UPointEffectorComponent::OnEndOverlap(UPrimitiveComponent *Comp, AActor *OtherActor, UPrimitiveComponent *OtherComp, int32 OtherBodyIndex)
{
    UE_LOG(LogTemp, Display, TEXT("OUT"));
}
