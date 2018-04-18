// Fill out your copyright notice in the Description page of Project Settings.

#include "TankC.h"
#include "Engine/World.h"
#include "Components/ActorComponent.h"
#include "Components/PrimitiveComponent.h"
#include "Components/InputComponent.h"

// Sets default values
ATankC::ATankC()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATankC::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATankC::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//
}

void ATankC::rotateTurret(float speed) {
	if (!ourTurret) {return;}
	float rotation = GetWorld()->DeltaTimeSeconds * speed* rotationSpeed;
	ourTurret->AddRelativeRotation(FRotator(0, rotation, 0));
}

void ATankC::elevateBarrel(float speed)
{
	if (!uptBarrel) {return;}
	float rotation = GetWorld()->DeltaTimeSeconds * speed* rotationSpeed;
		uptBarrel->AddRelativeRotation(FRotator(rotation, 0, 0));
}

void ATankC::rotateTank(float speed)
{
	if (!Tank) {return;}
	float rotation = GetWorld()->DeltaTimeSeconds * speed* rotationSpeed;
	Tank->AddRelativeRotation(FRotator(0, rotation,0));

}

void ATankC::moveTank(float speed)
{
	if (!Tank) { return; }
	float distance = GetWorld()->DeltaTimeSeconds * speed* distanceSpeed;
	Tank->AddRelativeLocation(Tank->GetForwardVector() * distance);

}

// Called to bind functionality to input
void ATankC::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	InputComponent->BindAxis("RotateTurret",this, &ATankC::rotateTurret);
	InputComponent->BindAxis("upTurret", this, &ATankC::elevateBarrel);
	InputComponent->BindAxis("moveTank", this, &ATankC::moveTank);
	InputComponent->BindAxis("rotateTank", this, &ATankC::rotateTank);
}

void ATankC::setTurretChildActor(UChildActorComponent * TurretFromBP)
{
	if (!TurretFromBP) { return; }
	ourTurret = TurretFromBP;
}

void ATankC::setBarrelChildActor(UChildActorComponent * barrelFromBP)
{
	if (!barrelFromBP) { return; }
	uptBarrel = barrelFromBP;
}


void ATankC::setTankChildActor(UChildActorComponent * TankFromBP)
{
	if (!TankFromBP) { return; }
	Tank = TankFromBP;
}