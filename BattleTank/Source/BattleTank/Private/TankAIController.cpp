// Fill out your copyright notice in the Description page of Project Settings.


#include "Public/TankAIController.h"

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("Player controller begin play"));

	ATank* Tiger = Cast<ATank>(GetPawn());
	UE_LOG(LogTemp, Warning, TEXT("AI is possessing %s"), *Tiger->GetName());

}