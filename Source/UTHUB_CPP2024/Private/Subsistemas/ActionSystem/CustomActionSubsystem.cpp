// Fill out your copyright notice in the Description page of Project Settings.

#include "Subsistemas/ActionSystem/CustomActionSubsystem.h"

#include "Kismet/GameplayStatics.h"
#include "Subsistemas/ActionSystem/CustomActionBase.h"
#include "Subsistemas/ActionSystem/CustomActionComponent.h"


void UCustomActionSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	TArray<AActor*> OutActors;
	UGameplayStatics::GetAllActorsOfClass(this, AActor::StaticClass(), OutActors);

	for(auto FoundActor : OutActors)
	{
		if(FoundActor->FindComponentByClass<UCustomActionComponent>())
		{
			EnabledActors.AddUnique(FoundActor);
		}
	}

	GetWorld()->AddOnActorSpawnedHandler(FOnActorSpawned::FDelegate::CreateUObject(this, &ThisClass::RegisterActionEnabledActor));
	// TODO - Detectar actores nuevos que se crean
}

void UCustomActionSubsystem::Deinitialize()
{
	Super::Deinitialize();
}

bool UCustomActionSubsystem::ShouldCreateSubsystem(UObject* Outer) const
{
	return Super::ShouldCreateSubsystem(Outer);
}

void UCustomActionSubsystem::DoAction(AActor* InActor, const TSubclassOf<UCustomActionBase>& InAction)
{
	if(UCustomActionComponent* Comp = GetCustomActionComponent(InActor))
	{
		Comp->DoAction(InAction);
	}
}

void UCustomActionSubsystem::DoActionSequence(AActor* InActor,
	const TArray<TSubclassOf<UCustomActionBase>>& InActionSequence)
{
}

void UCustomActionSubsystem::StopCurrentAction(AActor* InActor)
{
}

void UCustomActionSubsystem::AddActionToActor(AActor* InActor, const TSubclassOf<UCustomActionBase>& InNewAction)
{
}

void UCustomActionSubsystem::RemoveActionFromActor(AActor* InActor, const TSubclassOf<UCustomActionBase>& InNewAction)
{
}

void UCustomActionSubsystem::ExecuteMassiveAction(const TSubclassOf<UCustomActionBase>& InAction)
{
}

void UCustomActionSubsystem::RegisterActionEnabledActors()
{
}

void UCustomActionSubsystem::RegisterActionEnabledActor(AActor* InActor)
{
	if(InActor && InActor->FindComponentByClass<UCustomActionComponent>())
	{
		EnabledActors.AddUnique(InActor);
	}
}

UCustomActionComponent* UCustomActionSubsystem::GetCustomActionComponent(AActor* InActor) const
{
	if(InActor && EnabledActors.Contains(InActor))
	{
		return InActor->FindComponentByClass<UCustomActionComponent>();
	}
	
	return nullptr;

	// return InActor && EnabledActor.Contains(InActor) ?
	// 	InActor->FindComponentByClass<UCustomActionComponent>() : nullptr;
}

void UCustomActionSubsystem::ShowDebugInfo()
{
}
