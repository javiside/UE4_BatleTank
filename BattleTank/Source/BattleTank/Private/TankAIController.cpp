// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Engine/World.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	if(!GetPlayerTank())
	{
		UE_LOG(LogTemp, Warning, TEXT("Player Tank not found"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Player Tank Founded! : %s"), *(GetPlayerTank()->GetName()));
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