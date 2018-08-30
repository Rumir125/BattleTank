// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"

// Tick
	//Super
	//Aim towards crosshair();
    


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
	UE_LOG(LogTemp, Warning, TEXT("Player is ticking"));
}
