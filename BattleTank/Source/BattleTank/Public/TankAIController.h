// Copyright Francisco Javier Martinez 2017.
#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

/**
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override; 

protected:
	//How close can the AI tank get to the player
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
		float AcceptanceRadius = 8000.0f;

private:
	virtual void SetPawn(APawn* InPawn) override;

	UFUNCTION()
		void OnPossessedTankDeath();
};
