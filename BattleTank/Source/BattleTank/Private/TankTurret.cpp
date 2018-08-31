// Fill out your copyright notice in the Description page of Project Settings.

#include "Public/TankTurret.h"
#include "Engine/World.h"

void UTankTurret::RotateTurret(float RelativeYawSpeed)
{
	RelativeYawSpeed = FMath::Clamp(RelativeYawSpeed, -1.f, 1.f);
	auto YawRotationChange = RelativeYawSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto YawNewRotation = RelativeRotation.Yaw + YawRotationChange;

	SetRelativeRotation(FRotator(0.f, YawNewRotation, 0.f));
}
