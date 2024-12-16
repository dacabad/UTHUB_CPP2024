// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AsyncTestActor.generated.h"


class FAsyncTaskExample : public FNonAbandonableTask
{
	friend FAsyncTask<FAsyncTaskExample>;
	
	FAsyncTaskExample(){};

	void DoWork()
	{
		for(int i = 0; i < 10; ++i)
		{
			UE_LOG(LogTemp, Display, TEXT("%d"), i)
			FPlatformProcess::Sleep(0.1f);
		}		
	};

	FORCEINLINE TStatId GetStatId() const
	{
		RETURN_QUICK_DECLARE_CYCLE_STAT(FAsyncTaskExample, STATGROUP_ThreadPoolAsyncTasks);
	}
};

UCLASS()
class UTHUB_CPP2024_API AAsyncTestActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AAsyncTestActor();

	UFUNCTION(CallInEditor)
	void TestAsyncStuff();
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	
	// FAsyncTask<FAsyncTaskExample>* Worker;
	TSharedPtr<FAsyncTask<FAsyncTaskExample>> Worker;
};
