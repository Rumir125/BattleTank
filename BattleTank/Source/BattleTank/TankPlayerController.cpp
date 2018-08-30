// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"

// Tick
	//Super
	//Aim towards crosshair();
#define OUT


ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("Player controller begin play"));

	ATank* Tiger =  Cast<ATank>(GetPawn());
	UE_LOG(LogTemp, Warning, TEXT("You are possessing %s"), *Tiger->GetName());

}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }

	FVector HitLocation = FVector(0,0,0); // OUT parameter
	
	if (GetSightRayHitLocation(HitLocation))
	{
		UE_LOG(LogTemp, Warning, TEXT("HitLocation: %S"), *HitLocation.ToString());


		// get world location if linetrace through crosshair
		// if it hits landscape
		// tell controlled tank to aim at this point
	}
}

bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const 
{


	return false;
}

