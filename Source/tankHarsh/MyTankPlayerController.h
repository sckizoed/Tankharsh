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

	UPROPERTY(editAnyWhere)
	float CrossHairLocationX = 0.5f;
	UPROPERTY(editAnyWhere)
	float CrossHairLocationY = 0.3333f;
	UPROPERTY(editAnyWhere)
	float FireRange = 1000000.f;

	void AimThrowUIPoint();
	bool GetSightRayHitLocation(FVector& hitLocation) const;	
	bool GetLookDirection(FVector2D ScreenLocation, FVector& WorldDirecton) const;
	bool GetLookVectorHitLocation(FVector WorldDirecton, FVector& HitLocation) const;
};
