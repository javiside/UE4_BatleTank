// Copyright Francisco Javier Martinez 2017.

#include "TankTrack.h"

void UTankTrack::SetThrottle(float Throttle)
{
	// TODO clamp throttle value to: -1 and 1
	auto ForceApplied = GetForwardVector() * Throttle * TrackMaxDrivingForce;
	auto ForceLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}


