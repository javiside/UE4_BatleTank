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

void UTankTrack::SetThrottle(float Throttle)
{
	CurrentThrottle = FMath::Clamp<float>(CurrentThrottle + Throttle, -1, 1);
		DriveTrack();
		ApplySidewaysForce();
		CurrentThrottle = 0;
}

void UTankTrack::DriveTrack()
{
	auto ForceApplied = GetForwardVector() * CurrentThrottle * TrackMaxDrivingForce;

	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	auto ForceLocation = TankRoot->GetSocketLocation(*GetName());
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}

void UTankTrack::ApplySidewaysForce()
{
	auto SlippageSpeed = FVector::DotProduct(GetComponentVelocity(), GetRightVector());
	auto DeltaTime = GetWorld()->GetDeltaSeconds();
	auto CorrectionAcceletation = -SlippageSpeed / DeltaTime *GetRightVector();

	auto TankRoot = Cast<UStaticMeshComponent>(GetOwner()->GetRootComponent());
	auto CorrectionForce = (TankRoot->GetMass() *CorrectionAcceletation) / 2; //Two Tracks
	TankRoot->AddForce(CorrectionForce);
}