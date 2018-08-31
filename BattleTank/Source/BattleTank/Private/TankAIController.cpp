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
	UE_LOG(LogTemp, Warning, TEXT("AI controller begin play"));

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
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FVector PlayerLocation = GetPlayerTank()->GetActorLocation();
	GetControlledTank()->AimAt(PlayerLocation);

	// move towards the player

	// aim towards the player

	// fire if ready

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