// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PuzzleBase.h"
#include "RotatePuzzle.generated.h"

/**
 * 
 */
UCLASS()
class NBC_TASK_6_API ARotatePuzzle : public APuzzleBase
{
	GENERATED_BODY()
	
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void RandomValue() override;

	UPROPERTY(EditAnywhere, Category = "Puzzle|Movement")
	float PitchValue;
	UPROPERTY(EditAnywhere, Category = "Puzzle|Movement")
	float YawValue;
	UPROPERTY(EditAnywhere, Category = "Puzzle|Movement")
	float RollValue;
};
