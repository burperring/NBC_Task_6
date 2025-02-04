// Fill out your copyright notice in the Description page of Project Settings.


#include "RotatePuzzle.h"

void ARotatePuzzle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FRotator NewRotation = FRotator(PitchValue, YawValue, RollValue);
	
	FQuat QuatRotation = FQuat(NewRotation);

	AddActorLocalRotation(QuatRotation, false, 0, ETeleportType::None);
}

void ARotatePuzzle::RandomValue()
{
	PitchValue = FMath::FRandRange(0.f, 1.f);
	YawValue = FMath::FRandRange(0.f, 1.f);
	RollValue = FMath::FRandRange(0.f, 1.f);
}
