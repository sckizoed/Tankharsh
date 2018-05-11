// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class TANKHARSH_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public: 
	void Elevate(float RelativeSpeed);
private:
	UPROPERTY(EditAnyWhere, Category = setup)
	float maxDegreesPerSeconds = 20;

    UPROPERTY(EditAnyWhere)
	float maxElevationDegrees= 40;

	UPROPERTY(EditAnyWhere)
	float minElevationDegrees= 0;

};
