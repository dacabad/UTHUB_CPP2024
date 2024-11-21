// Fill out your copyright notice in the Description page of Project Settings.


#include "TestingSubsystem.h"

void UTestingSubsystem::DoSomething()
{
}

void UTestingSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

void UTestingSubsystem::Deinitialize()
{
	Super::Deinitialize();
	
}

bool UTestingSubsystem::ShouldCreateSubsystem(UObject* Outer) const
{
	return Super::ShouldCreateSubsystem(Outer);
}