// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"

// Move the barrel the right amount this frame
void UTankBarrel::Elevate(float RelativeSpeed)
{
	// Clamp the speed to -1 and 1
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);
	
	float ElevationChange = RelativeSpeed * MaxDegreesPerSeconds * GetWorld()->DeltaTimeSeconds;
	
	float RawNewElevation = RelativeRotation.Pitch + ElevationChange;
	//Clamp the Elevation to the minimum and maximun allowed
	RawNewElevation = FMath::Clamp<float>(RawNewElevation, MinElevationDegrees, MaxElevationDegrees);
	
	SetRelativeRotation(FRotator(RawNewElevation, 0, 0));
}