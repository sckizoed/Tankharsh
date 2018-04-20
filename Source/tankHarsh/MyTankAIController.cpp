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
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI deteced the : %s"), *(tanko->GetName()));
	}


}

AFinalTank* AMyTankAIController::getAIControllerTank() const
{
	return Cast<AFinalTank>(GetPawn());
}

AFinalTank * AMyTankAIController::getPlayerTank() const
{
	return Cast<AFinalTank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}
