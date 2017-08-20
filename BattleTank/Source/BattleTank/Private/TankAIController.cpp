// Copyright Francisco Javier Martinez 2017.

#include "TankAIController.h"
#include "Tank.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Player Tank not found"));
	}
	else
	{
		// Move towards the player
		MoveToActor(PlayerTank, AcceptanceRadius); //TODO Check radius is in cm

		auto AITank = Cast<ATank>(GetPawn());
		//Aim towards the player
		AITank->AimAt(PlayerTank->GetActorLocation());
		AITank->Fire();
	}
}
