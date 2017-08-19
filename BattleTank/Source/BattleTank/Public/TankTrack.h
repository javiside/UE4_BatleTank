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
	UFUNCTION(BlueprintCallable, Category = Input)
		void SetThrottle(float Throttle);
	
	//This is max force per track, in newtons
	UPROPERTY(EditDefaultsOnly)
		float TrackMaxDrivingForce = 400000.0f; // assume 40 tonne tank, and 1ga acceleration
	
};
