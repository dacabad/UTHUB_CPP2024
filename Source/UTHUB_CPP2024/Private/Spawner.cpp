// Fill out your copyright notice in the Description page of Project Settings.


#include "Spawner.h"

#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"


void AEnemy::BeginPlay()
{
	Super::BeginPlay();

	GetCharacterMovement()->MaxWalkSpeed = 100.f;
}

// Sets default values
ASpawner::ASpawner()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

void ASpawner::SpawnEnemy()
{
	if(EnemyClass)
	{
		const FVector Location = GetActorLocation();
		const FRotator Rotation = GetActorRotation();

		GetWorld()->SpawnActor(EnemyClass, &Location, &Rotation);
	}
}

// Called when the game starts or when spawned
void ASpawner::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	
}

