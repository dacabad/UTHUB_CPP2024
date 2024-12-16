// Fill out your copyright notice in the Description page of Project Settings.


#include "Async/AsyncTestActor.h"


// Sets default values
AAsyncTestActor::AAsyncTestActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Worker = new FAsyncTask<FAsyncTaskExample>();
}

void AAsyncTestActor::TestAsyncStuff()
{	
	
	Worker->StartBackgroundTask();
	
}

// Called when the game starts or when spawned
void AAsyncTestActor::BeginPlay()
{
	Super::BeginPlay();
	
}

void AAsyncTestActor::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	delete Worker;
	Worker = nullptr;
}

// Called every frame
void AAsyncTestActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

