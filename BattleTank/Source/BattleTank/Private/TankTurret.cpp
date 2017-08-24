// Copyright Francisco Javier Martinez 2017.

#include "TankTurret.h"

void UTankTurret::Rotate(float RelativeSpeed)
{
	// Clamp the speed to -1 and 1
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);

	float RotationChange = RelativeSpeed * MaxDegreesPerSeconds * GetWorld()->DeltaTimeSeconds;

	float RawNewRotation = RelativeRotation.Yaw + RotationChange;
	//Clamp the rotation to the minimum and maximun allowed
	//RawNewRotation = FMath::Clamp<float>(RawNewRotation, -180, 180);
	
	
	SetRelativeRotation(FRotator(0, RawNewRotation, 0));

}