// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent), hidecategories = ("Collision"))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
		
public:
	void ElevateBarrel(float DegreesPerSeconds);

private: 
	UPROPERTY(EditAnywhere, Category = Setup)
		float MaxDegreesPerSeconds = 20;

	UPROPERTY(EditAnywhere, Category = Setup)
		float MaxElevationDegrees = 30;

	UPROPERTY(EditAnywhere, Category = Setup)
		float MinElevationDegrees = 0;
};
