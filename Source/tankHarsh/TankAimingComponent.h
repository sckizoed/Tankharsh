// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Components/SceneComponent.h"
#include "TankAimingComponent.generated.h"

class UTankBarrel;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TANKHARSH_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();
	void setBarrelRefrece(UTankBarrel* BarrelToSet);
	void aimAt(FVector TankLocation,float lunchSpeed);

private:
	UTankBarrel* Barrel = nullptr;
	void MoveBarrel(FVector aimDirection);
};
