// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

// Forward Declarations
class ATank;

/**
 * 
 */
UCLASS()
class BATTLETANKS_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
private:
	void BeginPlay() override;

	virtual void Tick(float DeltaSeconds) override;

	ATank* GetControlledTank() const;

	ATank* GetPlayerTank() const;
	
	
};
