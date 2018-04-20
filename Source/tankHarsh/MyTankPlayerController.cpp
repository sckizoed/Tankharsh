// Fill out your copyright notice in the Description page of Project Settings.

#include "MyTankPlayerController.h"
#include "DrawDebugHelpers.h"
#include "Engine/World.h"
#include "Components/ActorComponent.h"
#include "Components/PrimitiveComponent.h"
#include "GameFramework/PlayerController.h"

void AMyTankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	auto tanki = getControllerTank();  
	if (!tanki) {
		UE_LOG(LogTemp, Warning, TEXT("not possessed"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("%s"), *(tanki->GetName()));
	}
}



void AMyTankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimThrowUIPoint();

}

AFinalTank* AMyTankPlayerController::getControllerTank() const
{
	return Cast<AFinalTank>(GetPawn());
}

void AMyTankPlayerController::AimThrowUIPoint()
{
	if (!getControllerTank()) { return; }
	
	FVector hitLocation; //OUT parameter
	if (GetSightRayHitLocation(hitLocation))
	{
		UE_LOG(LogTemp,Warning,TEXT("LineTrace show location: %s"),*hitLocation.ToString())
	}

}

bool AMyTankPlayerController::GetSightRayHitLocation(FVector& hitLocation) const
{

	return false;
}



const FVector AMyTankPlayerController::getStartTrace()
{
	FVector playerViewPointLocation;
	FRotator playerViewPointRotation;

	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(
		OUT playerViewPointLocation,
		OUT playerViewPointRotation);

	return (playerViewPointLocation);
}

const FVector AMyTankPlayerController::getEndTrace()
{
	FVector playerViewPointLocation;
	FRotator playerViewPointRotation;

	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(
		OUT playerViewPointLocation,
		OUT playerViewPointRotation);

	return (playerViewPointLocation + playerViewPointRotation.Vector());
}
