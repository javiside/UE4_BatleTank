// Copyright Francisco Javier Martinez 2017.

#include "TankAIController.h"
#include "TankAimingComponent.h"

//Depends on movement component via pathfinding system

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	auto ControlledTank = GetPawn();

	if (!ensure(PlayerTank)) { return; }

	////e.g If not more tanks available
	if (!ControlledTank) { return; }

	// Move towards the player
		MoveToActor(PlayerTank, AcceptanceRadius); //TODO Check radius is in cm

		//Aim towards the player
		auto AimingComponent = ControlledTank->FindComponentByClass<UTankAimingComponent>();
		AimingComponent->AimAt(PlayerTank->GetActorLocation());

		if (AimingComponent->GetFiringState() == EFiringState::Locked || AimingComponent->GetFiringState() == EFiringState::Aiming)
		{
			AimingComponent->Fire();
		}
}
