// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "tankBarrel.h"

// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UTankAimingComponent::setBarrelRefrece(UTankBarrel* BarrelToSet)
{
	Barrel = BarrelToSet;
}

void UTankAimingComponent::aimAt(FVector TankLocation, float lunchSpeed)
{	
	if (!Barrel) { return; }
	
	FVector OutLunchVelocity;
	FVector StartLocation = Barrel->GetSocketLocation(FName("FireSocket"));
	
	if (UGameplayStatics::SuggestProjectileVelocity(
		this,
		OutLunchVelocity,
		StartLocation,
		TankLocation,
		lunchSpeed,
		false,0,0,
		ESuggestProjVelocityTraceOption::DoNotTrace)) {

		auto aimDIrection = OutLunchVelocity.GetSafeNormal();
		MoveBarrel(aimDIrection);
		UE_LOG(LogTemp, Warning, TEXT("aiming at : %s"), *(aimDIrection.ToString()));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("No Solution found"));
	}
}

void UTankAimingComponent::MoveBarrel(FVector aimDirection) {
	FRotator BarrelRotator= Barrel->GetForwardVector().Rotation();
	FRotator AimAsRotator = aimDirection.Rotation();
	FRotator DeltaRotator = AimAsRotator - BarrelRotator;

	Barrel->Elevate(5);
}