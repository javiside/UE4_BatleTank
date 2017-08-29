// Copyright Francisco Javier Martinez 2017.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/Actor.h"
#include "Tank.generated.h"

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

		// Sets default values for this pawn's properties
	ATank();

public:
	// Called by the engine when actor damage is dealt
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const & DamageEvent, class AController * EventInstigator, AActor * DamageCauser) override;

private:
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	int32 StartingHealth = 1000;

	UPROPERTY(VisibleAnywhere, Category = "Health")
	int32 CurrentHealth = StartingHealth;
};
