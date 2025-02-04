// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PuzzleBase.h"
#include "Components/TimelineComponent.h"
#include "MovementPuzzle.generated.h"

/**
 * 
 */
class UCurveFloat;

UCLASS()
class NBC_TASK_6_API AMovementPuzzle : public APuzzleBase
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void TimelineProgress(float Value);

protected:
	virtual void BeginPlay() override;

	virtual void RandomValue() override;

	void MoveEvent();

	FTimeline MoveTimeline;
	UPROPERTY(EditAnywhere, Category = "Puzzle|Timeline")
	UCurveFloat* MoveCurve;

	UPROPERTY()
	FVector StartLocation;
	UPROPERTY()
	FVector EndLocation;
	UPROPERTY(EditAnywhere, Category = "Puzzle|Timeline")
	float fOffset_X;
	UPROPERTY(EditAnywhere, Category = "Puzzle|Timeline")
	float fOffset_Y;
	UPROPERTY(EditAnywhere, Category = "Puzzle|Timeline")
	float fOffset_Z;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;


};
