// Fill out your copyright notice in the Description page of Project Settings.

#include "Subsistemas/SingletonTesting.h"

#include "AssetRegistry/IAssetRegistry.h"

FGameplayLogger* FGameplayLogger::Singleton = nullptr;


// Sets default values
ASingletonTesting::ASingletonTesting()
{
	// Set this actor to call Tick() every frame.  You can turn this off to
	// improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

void ASingletonTesting::TestSingletonStuff()
{
	FGameplayLogger::Get().AddPendingMsg(FText::FromString(TEXT("Paquito se ha cargado a Jose Luis")));
	FGameplayLogger::Get().AddPendingMsg(FText::FromString(TEXT("Paquito se ha cargado a Jose Luis")));
	FGameplayLogger::Get().AddPendingMsg(FText::FromString(TEXT("Paquito se ha cargado a Jose Luis")));
	FGameplayLogger::Get().AddPendingMsg(FText::FromString(TEXT("Paquito se ha cargado a Jose Luis")));
	FGameplayLogger::Get().AddPendingMsg(FText::FromString(TEXT("Paquito se ha cargado a Jose Luis")));
	FGameplayLogger::Get().AddPendingMsg(FText::FromString(TEXT("Paquito se ha cargado a Jose Luis")));
	FGameplayLogger::Get().AddPendingMsg(FText::FromString(TEXT("Paquito se ha cargado a Jose Luis")));
	
}

// Called when the game starts or when spawned
void ASingletonTesting::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ASingletonTesting::Tick(float DeltaTime) { Super::Tick(DeltaTime); }
