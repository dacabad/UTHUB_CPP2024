// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SingletonTesting.generated.h"


class FSomeClass
{
public:
	void Foo();	
	int32 SomeVariable;
};

// SINGLETON STATIC
class FSingleton
{
public:	
	FSingleton(const FSingleton&) = delete;
	FSingleton& operator=(const FSingleton&) = delete;
	FSingleton(FSingleton&&) = delete;
	FSingleton& operator=(FSingleton&&) = delete;
	
	static FSingleton& Get() 
	{
		return Singleton;
	}

	int SomeInfo;
private:
	FSingleton();
	~FSingleton();
	
	static FSingleton Singleton;
};


// LAZY LOAD
class FGameplayLogger
{
public:	
	FGameplayLogger(const FGameplayLogger&) = delete;
	FGameplayLogger& operator=(const FGameplayLogger&) = delete;
	FGameplayLogger(FGameplayLogger&&) = delete;
	FGameplayLogger& operator=(FGameplayLogger&&) = delete;
	
	static FGameplayLogger& Get() 
	{
		if(!Singleton)
		{
			Singleton = new FGameplayLogger();
		}
		return *Singleton;
	}

	void AddPendingMsg(const FText& InMsg)
	{
		PendingMessages.Enqueue(InMsg);
		if(CurrentCountOfMsgs != MaxMsgOnScreen)
		{
			PublishNextMsg();
		}
		else
		{
			// ScheduleNextMsg();
		}
	}
	
private:
	FGameplayLogger(): CurrentCountOfMsgs(0), MaxMsgOnScreen(0)
	{
	} ;
	~FGameplayLogger() {};

	// esta función se dispara automáticamente cada 2s
	// ciertos sistemas disparan esta función cuando consideren
	void PublishNextMsg()
	{
		FText Msg;
		if(PendingMessages.Dequeue(Msg))
		{
			// publico el mensaje
			if(GEngine) GEngine->AddOnScreenDebugMessage(INDEX_NONE, 2.f, FColor::Cyan, Msg.ToString());
		}
	}
	
	static FGameplayLogger* Singleton;

	// queue
	// TArray<FText> PendingMessages;
	TQueue<FText> PendingMessages;

	int32 CurrentCountOfMsgs;
	int32 MaxMsgOnScreen;
};




UCLASS()
class UTHUB_CPP2024_API ASingletonTesting : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ASingletonTesting();

	UFUNCTION(BlueprintCallable)
	void TestSingletonStuff();
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
