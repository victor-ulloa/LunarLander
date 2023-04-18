// Fill out your copyright notice in the Description page of Project Settings.

#include "Ship.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/CapsuleComponent.h"
#include "BaseObstacle.h"

// Sets default values
AShip::AShip()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ShipMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("ShipMesh"));
	RootComponent = ShipMesh;
	ShipMesh->SetSimulatePhysics(true);
	ShipMesh->SetCollisionObjectType(ECollisionChannel::ECC_Pawn);
	
	CapsuleCollider = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CapsuleCollider"));
	CapsuleCollider->SetupAttachment(RootComponent);

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(RootComponent);
	Camera->SetRelativeLocation(FVector(-10.f, 0.f, 60.f));
	Camera->bUsePawnControlRotation = true;
}

// Called when the game starts or when spawned
void AShip::BeginPlay()
{
	Super::BeginPlay();

	if (APlayerController *PlayerController = Cast<APlayerController>(GetController()))
	{
		if (UEnhancedInputLocalPlayerSubsystem *Subsystem = ULocalPlayer::GetSubsystem<
				UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(ShipMappingContext, 0);
		}
	}
	ShipMesh->OnComponentHit.AddDynamic(this, &AShip::OnHit);
}

// Called every frame
void AShip::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AShip::SetupPlayerInputComponent(UInputComponent *PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	if (UEnhancedInputComponent *EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EnhancedInputComponent->BindAction(ThrustAction, ETriggerEvent::Triggered, this, &AShip::Thrust);
	}
}

void AShip::Thrust(const FInputActionValue &Value)
{
	const FVector2D ThrustValue = Value.Get<FVector2D>();

	// UE_LOG(LogTemp, Display, TEXT("X: %f     Y: %f"), ThrustValue.X, ThrustValue.Y);

	FVector VerticalForce = FVector(0, HorizontalThrusterForce * ThrustValue.X, VerticalThrusterForce * ThrustValue.Y);
	ShipMesh->AddForce(VerticalForce, NAME_None, true);
}

void AShip::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	UE_LOG(LogTemp, Display, TEXT("TEST"));
	if(ABaseObstacle *Obstacle = Cast<ABaseObstacle>(OtherActor)) {
		UE_LOG(LogTemp, Warning, TEXT("got it"));
	}
}
