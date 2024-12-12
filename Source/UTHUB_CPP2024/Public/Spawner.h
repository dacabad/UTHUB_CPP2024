// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/Character.h"
#include "Spawner.generated.h"







UCLASS()
class AEnemy : public ACharacter
{
	GENERATED_BODY()

public:

	virtual void BeginPlay() override;
	
};

UCLASS()
class UTHUB_CPP2024_API ASpawner : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ASpawner();

	UFUNCTION(BlueprintCallable, CallInEditor)
	void SpawnEnemy();

	UPROPERTY(EditInstanceOnly)
	TSubclassOf<AEnemy> EnemyClass;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	float Health = 100.f;

	float HealthRegen = 1.f;
};
