// Fill out your copyright notice in the Description page of Project Settings.


#include "Predicates/PredicateActor.h"

#include <functional>

#include "Engine/TargetPoint.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"
#include "Predicates/GenericUtils.h"


class FSingleDelegate
{
	void(*Functor)(void) = nullptr;

public:
	void Bind(void(*InFunctor)(void));

	bool Execute()
	{
		Functor();
		return true;
	};
};



APredicateActor::APredicateActor()
{
}

void APredicateActor::InitInput(UWorld* World, const FString& String)
{
	
}

void Algo::SortActors(TArray<AActor*>& InActorsToSort)
{
}



void APredicateActor::BeginPlay()
{
	Super::BeginPlay();
	



	
	

	
}

void APredicateActor::PrintAfterTime()
{
}

void SomeStuff()
{
	
}

void APredicateActor::TestFunction()
{
	TArray<int32> NumArr{10, 2, 5, 4, 3};
	
	UGenericUtils::SortArray<int32>(NumArr, [](int32 LHS, int32 RHS)
	{
		return LHS < RHS;
	});

	UGenericUtils::SortArray<int32>(NumArr, [](int32 LHS, int32 RHS)
	{
		return LHS > RHS;
	});

	
	// coger todos los actores del nivel y ordenarlos en base a la distancia a este actor
	TArray<AActor*> OutActors;
	UGameplayStatics::GetAllActorsOfClass(this, ATargetPoint::StaticClass(), OutActors);

	UGenericUtils::SortArray<AActor*>(OutActors, [this](AActor* LHS, AActor* RHS)
	{
		return this->GetDistanceTo(LHS) > this->GetDistanceTo(RHS);
	});
		
}

void APredicateActor::SomeActorStuff()
{
}

void APredicateActor::DoSomething(TFunction<void()> Func)
{
	Func();
}

