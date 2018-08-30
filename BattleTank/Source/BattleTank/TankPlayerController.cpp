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
	AimTowardsCrosshair();
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
	// Find the crosshair position
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto ScreenLocation = FVector2D(ViewportSizeX * CrossHairXLocation, ViewportSizeY * CrossHairYLocation);
	// De-project the screen position of the crosshair to world direction

	FVector LookDirection;
	GetLookDirection(ScreenLocation, LookDirection);

	// Line-trace along that look direction, and see waht we hit
	return true;
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector & LookDirection) const
{
	FVector CameraWorldLocation;

	DeprojectScreenPositionToWorld(ScreenLocation.X,
		ScreenLocation.Y, 
		CameraWorldLocation,
		LookDirection);
	
	return true;
}

