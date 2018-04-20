// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "FinalTank.h"
#include "GameFramework/PlayerController.h"
#include "MyTankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class TANKHARSH_API AMyTankPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

public:
	AFinalTank* getControllerTank() const;

private:
	void AimThrowUIPoint();
	bool GetSightRayHitLocation(FVector hitLocation);

	const FVector getEndTrace();

	const FVector getStartTrace();
	
};
