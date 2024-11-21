// Fill out your copyright notice in the Description page of Project Settings.

#include "GeneralTesting.h"

#include "GameFramework/Character.h"

// Sets default values
AGeneralTesting::AGeneralTesting()
{
	// Set this actor to call Tick() every frame.  You can turn this off to
	// improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

void AGeneralTesting::SomeFunctionToFire()
{
	UE_LOG(LogTemp, Display, TEXT("I shot the sheriff"))
	
	GetWorld()->GetTimerManager().ClearTimer(TimerHandle_ShotFunction);
}

void AGeneralTesting::DoTest()
{
	GetWorld()->GetTimerManager().SetTimer(TimerHandle_ShotFunction, this, &ThisClass::SomeFunctionToFire, 1.f);	
}

void AGeneralTesting::SpawnProjectile(TSubclassOf<AActor> ProjectileClass)
{
}

// Called when the game starts or when spawned
void AGeneralTesting::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AGeneralTesting::Tick(float DeltaTime) { Super::Tick(DeltaTime); }
