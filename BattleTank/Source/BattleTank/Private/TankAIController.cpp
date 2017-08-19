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

	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Player Tank not found"));
	}
	else
	{
		// TODO move towards the player

		auto AITank = Cast<ATank>(GetPawn());
		//Aim towards the player
		AITank->AimAt(PlayerTank->GetActorLocation());
		AITank->Fire();
	}
}
