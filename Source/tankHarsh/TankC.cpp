// Fill out your copyright notice in the Description page of Project Settings.

#include "TankC.h"
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

}

void ATankC::rotateTurret() {
	ourTurret->SetRelativeRotation(FRotator(0, -45.f, 0));

}

void ATankC::invertRotateTurret(){
	ourTurret->SetRelativeRotation(FRotator(0, 45.f , 0));
}


// Called to bind functionality to input
void ATankC::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	UE_LOG(LogTemp, Warning, TEXT("Setup player input component"));
	InputComponent->BindAction("Turret_clockwise", IE_Pressed, this, &ATankC::rotateTurret);
	InputComponent->BindAction("Turret_nonclockwise", IE_Pressed, this, &ATankC::invertRotateTurret);
}

void ATankC::setTurretChildActor(UChildActorComponent * TurretFromBP)
{
	UE_LOG(LogTemp, Warning, TEXT("Child component being used "));
	ourTurret = TurretFromBP;
}