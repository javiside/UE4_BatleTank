// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Tank.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!GetPlayerTank())
	{
		UE_LOG(LogTemp, Warning, TEXT("Player Tank not found"));
	}
	else
	{
		// TODO move towards the player

		//Aim towards the player
		GetControlledAITank()->AimAt(GetPlayerTank()->GetActorLocation());
		
		// TODO Fire if ready

	}
}

ATank* ATankAIController::GetControlledAITank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}

