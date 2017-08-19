// Copyright Francisco Javier Martinez 2017.

#include "TankTrack.h"

void UTankTrack::SetThrottle(float Throttle)
{
	auto TrackName = GetName();
	UE_LOG(LogTemp, Warning, TEXT("%s Throttle: %f"), *TrackName, Throttle);
	// TODO clamp throttle value to: -1 and 1
}


