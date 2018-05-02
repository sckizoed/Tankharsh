// Fill out your copyright notice in the Description page of Project Settings.

#include "FinalTank.h"


// Sets default values
AFinalTank::AFinalTank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	aimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aim Component"));
}

// Called when the game starts or when spawned
void AFinalTank::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AFinalTank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AFinalTank::aimAt(FVector TankLocation)
{
	aimingComponent->aimAt(TankLocation, lunchSpeed);
}

void AFinalTank::setBarrelRefrece(UStaticMeshComponent * BarrelToSet)
{

	aimingComponent->setBarrelRefrece(BarrelToSet);
}

// Called to bind functionality to input
void AFinalTank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}