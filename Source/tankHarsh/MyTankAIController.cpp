// Fill out your copyright notice in the Description page of Project Settings.

#include "MyTankAIController.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"

void AMyTankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto tanko = getPlayerTank();
	if (!tanko) {
		UE_LOG(LogTemp, Warning, TEXT("IA can not detect you"));
	}
}

void AMyTankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	getAIControllerTank()->aimAt(getPlayerTank()->GetActorLocation());

}

AFinalTank* AMyTankAIController::getAIControllerTank() const
{
	return Cast<AFinalTank>(GetPawn());
}

AFinalTank * AMyTankAIController::getPlayerTank() const
{
	return Cast<AFinalTank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}
