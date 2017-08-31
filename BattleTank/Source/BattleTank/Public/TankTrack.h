// Copyright Francisco Javier Martinez 2017.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
* TankTrack is used to set maximum driving force, and to apply forces to the tank
*/
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;

	void ApplySidewaysForce();

	UFUNCTION(BlueprintCallable, Category = "Input")
		void SetThrottle(float Throttle);

	void DriveTrack();

	//This is max force per track, in newtons
	UPROPERTY(EditDefaultsOnly)
		float TrackMaxDrivingForce = 40000000.0f; // assume 40 tonne tank, and 1ga acceleration

private:
	// Sets default values for this component's properties
	UTankTrack();

	float CurrentThrottle = 0;
};
