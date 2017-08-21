// Copyright Francisco Javier Martinez 2017.

#include "TankTrack.h"

UTankTrack::UTankTrack()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UTankTrack::BeginPlay()
{
	Super::BeginPlay();
}

void UTankTrack::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
	auto SlippageSpeed = FVector::DotProduct(GetComponentVelocity(), GetRightVector());

	auto CorrectionAcceletation = -SlippageSpeed / DeltaTime *GetRightVector();

	auto TankRoot = Cast<UStaticMeshComponent>(GetOwner()->GetRootComponent());
	auto CorrectionForce = (TankRoot->GetMass() *CorrectionAcceletation) / 2; //Two Tracks
	TankRoot->AddForce(CorrectionForce);
}

void UTankTrack::SetThrottle(float Throttle)
{
	// TODO clamp throttle value to: -1 and 1
	auto ForceApplied = GetForwardVector() * Throttle * TrackMaxDrivingForce;
	auto ForceLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}


