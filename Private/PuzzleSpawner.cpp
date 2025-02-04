// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/BoxComponent.h"
#include "PuzzleSpawner.h"

// Sets default values
APuzzleSpawner::APuzzleSpawner()
{
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SpawnVolume = CreateDefaultSubobject<UBoxComponent>(TEXT("SpawnVolume"));
	SpawnVolume->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	PrimaryActorTick.bCanEverTick = false;
}

void APuzzleSpawner::SpawnActor()
{
	// Set random puzzle
	int32 iRandNum = FMath::RandRange(0, PA.Num() - 1);

	// Calculate the extends of the box
	FBoxSphereBounds BoxBounds = SpawnVolume->CalcBounds(GetActorTransform());

	// random position within the box bounds
	FVector SpawnLocation = BoxBounds.Origin;
	SpawnLocation.X += -BoxBounds.BoxExtent.X + 2 * BoxBounds.BoxExtent.X * FMath::FRand();
	SpawnLocation.Y += -BoxBounds.BoxExtent.Y + 2 * BoxBounds.BoxExtent.Y * FMath::FRand();
	SpawnLocation.Z += -BoxBounds.BoxExtent.Z + 2 * BoxBounds.BoxExtent.Z * FMath::FRand();

	AActor* SpawnActor = GetWorld()->SpawnActor(PA[iRandNum], &SpawnLocation);
	APuzzleBase* PB = Cast<APuzzleBase>(SpawnActor);
	if (PB != nullptr) {
		PB->RandomValue();
	}
}

// Called when the game starts or when spawned
void APuzzleSpawner::BeginPlay()
{
	Super::BeginPlay();
	
	for (int32 i = 0; i < SpawnCount; i++) {
		SpawnActor();
	}
}

