// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "TankAimingComponent.h"
#include "FinalTank.generated.h"

UCLASS()
class TANKHARSH_API AFinalTank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AFinalTank();
	void aimAt(FVector TankLocation);

	UFUNCTION(BlueprintCallable, category = barrel)
	void setBarrelRefrece(UStaticMeshComponent* BarrelToSet);

	UPROPERTY(EditAnyWhere, Category = firing)
	float lunchSpeed = 10000;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UTankAimingComponent* aimingComponent = nullptr;
};