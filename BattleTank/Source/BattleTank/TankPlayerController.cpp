// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "Engine/World.h"

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

	FVector HitLocation; // OUT parameter
	
	if (GetSightRayHitLocation(HitLocation))
	{
        GetControlledTank()->AimAt(HitLocation);
		// get world location if linetrace through crosshair
		// if it hits landscape
		// tell controlled tank to aim at this point
	} 
}

bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation) const 
{
	// Find the crosshair position
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto ScreenLocation = FVector2D(ViewportSizeX * CrossHairXLocation, ViewportSizeY * CrossHairYLocation);
	// De-project the screen position of the crosshair to world direction

	FVector LookDirection;
	if (GetLookDirection(ScreenLocation, LookDirection))
	{
		GetLookVectorHitLocation(LookDirection, HitLocation);
	}
	



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

bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const
{
	FHitResult HitResult;
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + (LookDirection * LineTraceRange);


	if (GetWorld()->LineTraceSingleByChannel(
		OUT HitResult,
		StartLocation,
		EndLocation,
		ECollisionChannel::ECC_Visibility))
	{
		HitLocation = HitResult.Location;
		
		return true;
	}

	HitLocation = FVector(0);



	return false;
}

