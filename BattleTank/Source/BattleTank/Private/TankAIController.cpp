// Fill out your copyright notice in the Description page of Project Settings.


#include "Public/TankAIController.h"
#include "Engine/World.h"

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}



void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("Player controller begin play"));

	ATank* Tiger = GetPlayerTank();
	if (Tiger)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI controller found %s"), *Tiger->GetName());
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI controller cant find player "));
	}

}

ATank * ATankAIController::GetPlayerTank() const
{
	if (GetWorld()->GetFirstPlayerController())
	{
		return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	}
	else
		return nullptr;
}