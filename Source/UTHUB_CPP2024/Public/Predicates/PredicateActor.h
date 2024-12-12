// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PredicateActor.generated.h"

namespace Algo
{
	void SortActors(TArray<AActor*>& InActorsToSort);	
}


UCLASS()
class UTHUB_CPP2024_API APredicateActor : public AActor
{
	GENERATED_BODY()

public:
	
	APredicateActor();

	void InitInput(UWorld* World, const FString& String);

	
	
	virtual void BeginPlay() override;
	
	void PrintAfterTime();

	UFUNCTION(CallInEditor)
	void TestFunction();

	void SomeActorStuff();
	
	void DoSomething(TFunction<void()> Func);

	FTimerHandle OutHandle;

	
};
