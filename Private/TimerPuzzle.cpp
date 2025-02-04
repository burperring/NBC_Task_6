// Fill out your copyright notice in the Description page of Project Settings.


#include "TimerPuzzle.h"


void ATimerPuzzle::BeginPlay()
{
	FTimerHandle Timer;
	GetWorldTimerManager().SetTimer(Timer, this, &ATimerPuzzle::PuzzleVisibility, fDestroyTime, true, fStartTime);
}

void ATimerPuzzle::RandomValue()
{
	fDestroyTime = FMath::RandRange(3, 6);
	fStartTime = FMath::RandRange(3, 6);
}

void ATimerPuzzle::PuzzleVisibility()
{
	isVisible = !isVisible;
	this->SetActorHiddenInGame(isVisible);
}
