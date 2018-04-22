// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FinalTank.h"
#include "AIController.h"
#include "MyTankAIController.generated.h"

/**
 * 
 */
UCLASS()
class TANKHARSH_API AMyTankAIController : public AAIController
{
	GENERATED_BODY()
	
protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

public:
	AFinalTank* getAIControllerTank() const;
	AFinalTank* getPlayerTank() const;

	
	
};
