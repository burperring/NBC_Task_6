// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PuzzleBase.h"
#include "TimerPuzzle.generated.h"

/**
 * 
 */
UCLASS()
class NBC_TASK_6_API ATimerPuzzle : public APuzzleBase
{
	GENERATED_BODY()
	
public:
	virtual void BeginPlay() override;

	virtual void RandomValue() override;

	void PuzzleVisibility();

	UPROPERTY(EditAnywhere, Category = "Puzzle|Timer")
	float fDestroyTime = 5;
	UPROPERTY(EditAnywhere, Category = "Puzzle|Timer")
	float fStartTime = 5;

protected:
	bool isVisible;
};
