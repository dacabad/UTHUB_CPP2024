// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "TestingSubsystem.generated.h"

/**
 * 
 */
UCLASS()
class UTHUB_CPP2024_API UTestingSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:

	void DoSomething();
	
protected:
		
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	virtual bool ShouldCreateSubsystem(UObject* Outer) const override;
};


