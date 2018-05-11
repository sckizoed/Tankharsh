// Fill out your copyright notice in the Description page of Project Settings.

#include "MyTankPlayerController.h"
#include "DrawDebugHelpers.h"
#include "Engine/World.h"
#include "FinalTank.h"
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
		getControllerTank()->aimAt(hitLocation);
	}

}

bool AMyTankPlayerController::GetSightRayHitLocation(FVector& hitLocation) const
{
	int32 viewPortX, viewPortY;
	GetViewportSize(viewPortX, viewPortY);
	FVector lookDirection;

	FVector2D ScreenLocation = FVector2D(viewPortX * CrossHairLocationX, viewPortY * CrossHairLocationY);

	if (GetLookDirection(ScreenLocation, lookDirection))
	{
		GetLookVectorHitLocation(lookDirection, hitLocation);
		return true;
	}
	
	return false;
}

bool AMyTankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& WorldDirecton) const
{
	FVector WorldLocation;
	return (DeprojectScreenPositionToWorld(
		  ScreenLocation.X
		, ScreenLocation.Y
		, WorldLocation
		, WorldDirecton));
}

bool AMyTankPlayerController::GetLookVectorHitLocation(FVector lookDirecton, FVector& HitLocation) const
{
	FHitResult hitResult;
	FVector startLocation = PlayerCameraManager->GetCameraLocation();
	FVector EndLocation = startLocation + (lookDirecton * FireRange);
	
	if (GetWorld()->LineTraceSingleByChannel(
		hitResult,
		startLocation,
		EndLocation,
		ECollisionChannel::ECC_Visibility))
	{
		HitLocation = hitResult.Location;
		return true;
	}

	HitLocation = FVector(0);
	return false;
}
