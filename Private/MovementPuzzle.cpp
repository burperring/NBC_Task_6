// Fill out your copyright notice in the Description page of Project Settings.


#include "MovementPuzzle.h"

void AMovementPuzzle::TimelineProgress(float Value)
{
	FVector NewLocation = FMath::Lerp(StartLocation, EndLocation, Value);
	SetActorLocation(NewLocation);
}

void AMovementPuzzle::BeginPlay()
{
	Super::BeginPlay();

	MoveEvent();
}

void AMovementPuzzle::RandomValue()
{
	fOffset_X = FMath::RandRange(0, 800);
	fOffset_Y = FMath::RandRange(0, 800);
	fOffset_Z = FMath::RandRange(0, 800);

	MoveEvent();
}

void AMovementPuzzle::MoveEvent()
{
	if (MoveCurve) {
		FOnTimelineFloat TimelineProgress;
		TimelineProgress.BindUFunction(this, FName("TimelineProgress"));
		MoveTimeline.AddInterpFloat(MoveCurve, TimelineProgress);
		MoveTimeline.SetLooping(true);

		StartLocation = EndLocation = GetActorLocation();
		EndLocation.X += fOffset_X;
		EndLocation.Y += fOffset_Y;
		EndLocation.Z += fOffset_Z;

		MoveTimeline.PlayFromStart();
	}
}

void AMovementPuzzle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	MoveTimeline.TickTimeline(DeltaTime);
}
