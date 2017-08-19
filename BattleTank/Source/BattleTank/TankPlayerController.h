// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

class ATank;

/**
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

private:
	ATank* GetControlledTank() const;

	/*Start the tank moving the barrel so that a shot
	would hit where the crosshair intersects the world*/
	void AimTowardsCrosshair();

	UPROPERTY(EditDefaultsOnly)
		float CrossHairXLocation = 0.5f;

	UPROPERTY(EditDefaultsOnly)
		float CrossHairYLocation = 0.3333f;
	
	//Return an OUT parameter, true if hit landscape
	bool GetSightRayHitLocation(FVector &OutHitLocation) const;

	bool GetLookDirection(FVector2D ScreenLocation, FVector &LookDirection) const;

	bool GetLookVectorHitLocation(FVector LookDirection, FVector &HitLocation) const;

	UPROPERTY(EditDefaultsOnly)
		float LineTraceRange = 10000000.0f;
};
