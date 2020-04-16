// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController not possessing a tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController possessing: %s"), *(ControlledTank->GetName()));
	}
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
	// UE_LOG(LogTemp, Warning, TEXT("Player controller ticking"));
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }
	
	FVector HitLocation;	// Out parameter
	if (GetSightRayHitLocation(HitLocation))	// Has a "side-effect", is going to line trace
	{
		UE_LOG(LogTemp, Warning, TEXT("Hitlocation: %s"), *HitLocation.ToString());
		// TODO Tell controlled tank to aim at this point
	}
}

// Get world location of linetrace through corsshair, true if hits landscape

bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation) const
{
	HitLocation = FVector(1.0);
	return true;
}