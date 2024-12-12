// Fill out your copyright notice in the Description page of Project Settings.

#include "Subsistemas/ActionSystem/CustomActionSubsystem.h"

#include "Kismet/GameplayStatics.h"
#include "Subsistemas/ActionSystem/CustomActionBase.h"
#include "Subsistemas/ActionSystem/CustomActionComponent.h"


void UCustomActionSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	RegisterActionEnabledActors();

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

UCustomActionSubsystem* UCustomActionSubsystem::GetActionSubsystem(const UObject* WorldContextObject)
{
	if(WorldContextObject)
	{
		return WorldContextObject->GetWorld()->GetSubsystem<UCustomActionSubsystem>();
	}

	return nullptr;
}

void UCustomActionSubsystem::DoAction(AActor* InActor, const TSubclassOf<UCustomActionBase>& InAction)
{
	if(UCustomActionComponent* Comp = GetCustomActionComponent(InActor))
	{
		Comp->DoAction(InAction);
		OnActionStarted.Broadcast(InActor, InAction);
	}
}

void UCustomActionSubsystem::DoActionSequence(AActor* InActor,
	const TArray<TSubclassOf<UCustomActionBase>>& InActionSequence)
{
	
}

void UCustomActionSubsystem::DoActionAndWait(AActor* InActor, const TSubclassOf<UCustomActionBase>& InAction,
	FSingleActionEvent OnActionFinishedSingleEvent)
{
	OnActionFinished.Add(OnActionFinishedSingleEvent);
	DoAction(InActor, InAction);
}

void UCustomActionSubsystem::StopCurrentAction(AActor* InActor)
{
	if(UCustomActionComponent* Comp = GetCustomActionComponent(InActor))
	{
		Comp->StopAction();
		
	}
}

void UCustomActionSubsystem::AddActionToActor(AActor* InActor, const TSubclassOf<UCustomActionBase>& InNewAction)
{
	if(UCustomActionComponent* Comp = GetCustomActionComponent(InActor))
	{
		Comp->AddAction(InNewAction);
	}
}

void UCustomActionSubsystem::RemoveActionFromActor(AActor* InActor, const TSubclassOf<UCustomActionBase>& InNewAction)
{
	if(UCustomActionComponent* Comp = GetCustomActionComponent(InActor))
	{
		Comp->RemoveAction(InNewAction);
	}
}

void UCustomActionSubsystem::ExecuteMassiveAction(const TSubclassOf<UCustomActionBase>& InAction)
{
	for(auto Actor : EnabledActors)
	{
		GetCustomActionComponent(Actor)->DoAction(InAction);
	}
}

void UCustomActionSubsystem::RegisterActionEnabledActors()
{
	TArray<AActor*> OutActors;
	UGameplayStatics::GetAllActorsOfClass(this, AActor::StaticClass(), OutActors);

	for(auto FoundActor : OutActors)
	{
		RegisterActionEnabledActor(FoundActor);
	}
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

#if WITH_EDITOR
void UCustomActionSubsystem::ShowDebugInfo()
{
	for(auto Actor: EnabledActors)
	{
		GetCustomActionComponent(Actor)->ShowDebugInfo();
	}
}
#endif