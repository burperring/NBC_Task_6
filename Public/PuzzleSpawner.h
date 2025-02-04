// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PuzzleBase.h"
#include "GameFramework/Actor.h"
#include "PuzzleSpawner.generated.h"

UCLASS()
class NBC_TASK_6_API APuzzleSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APuzzleSpawner();

	void SpawnActor();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Puzzle|Spawn")
	int32 SpawnCount = 10;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Puzzle|Spawn")
	TArray<TSubclassOf<APuzzleBase>> PA;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Puzzle")
	class UBoxComponent* SpawnVolume;
};
