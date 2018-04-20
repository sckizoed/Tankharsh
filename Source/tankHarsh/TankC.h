// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "TankC.generated.h"

UCLASS()
class TANKHARSH_API ATankC : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATankC();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	UFUNCTION(BlueprintCallable, Category = myTankCategory )
	void setTurretChildActor(UChildActorComponent* TurretFromBP);

	UFUNCTION(BlueprintCallable, Category = myTankCategory)
	void setBarrelChildActor(UChildActorComponent* barrelFromBP);

	UFUNCTION(BlueprintCallable, Category = myTankCategory)
	void setTankChildActor(UChildActorComponent* TankFromBP);
	

private:
	UPROPERTY(editAnyWhere)
	float rotationSpeed = 30.f;

	UPROPERTY(editAnyWhere)
	float distanceSpeed = 30.f;


	//rotate my turret by speed
	UChildActorComponent* ourTurret;
	void rotateTurret(float speed);

	UChildActorComponent* uptBarrel;
	void elevateBarrel(float speed);

	UChildActorComponent* Tank;
	void rotateTank(float speed);
	void moveTank(float speed);
	
};
