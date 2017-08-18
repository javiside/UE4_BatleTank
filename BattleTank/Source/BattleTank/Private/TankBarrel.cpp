// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"


void UTankBarrel::ElevateBarrel(float DegreesPerSeconds)
{
	UE_LOG(LogTemp, Warning, TEXT("Elevate Barrel called, at speed : %f"), DegreesPerSeconds);
	// Move the barrel the right amount this frame
	// Given a max elevation speed, and the frame time
}