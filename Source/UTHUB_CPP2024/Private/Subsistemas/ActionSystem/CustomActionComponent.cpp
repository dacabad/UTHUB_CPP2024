// Fill out your copyright notice in the Description page of Project Settings.


#include "Subsistemas/ActionSystem/CustomActionComponent.h"

#include "Subsistemas/ActionSystem/CustomActionBase.h"


// Sets default values for this component's properties
UCustomActionComponent::UCustomActionComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UCustomActionComponent::TickComponent(float DeltaTime, ELevelTick TickType,
	FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

#if WITH_EDITOR
	ShowDebugInfo();
#endif
	
}


// Called when the game starts
void UCustomActionComponent::BeginPlay()
{
	Super::BeginPlay();
	
}

void UCustomActionComponent::DoAction(const TSubclassOf<UCustomActionBase>& ActionClass)
{
	if(Actions.Contains(ActionClass))
	{
		CurrentAction = ActionClass;
		ActionClass->GetDefaultObject<UCustomActionBase>()->DoAction(GetOwner());
	}
}

void UCustomActionComponent::StopAction()
{
	if(CurrentAction)
	{
		CurrentAction->GetDefaultObject<UCustomActionBase>()->EndAction(GetOwner());
		CurrentAction = nullptr;
	}
}

void UCustomActionComponent::AddAction(const TSubclassOf<UCustomActionBase>& InNewAction)
{
	if(InNewAction)
	{
		Actions.AddUnique(InNewAction);
		// aviso a la peñuqui de que acabo de obtener una acción nueva 
	}
	// Además puedo hacer otras cosas
}

void UCustomActionComponent::RemoveAction(const TSubclassOf<UCustomActionBase>& InActionToRemove)
{
	if(InActionToRemove)
	{
		Actions.Remove(InActionToRemove);
		// aviso a quien quiera enterarse de esto
	}
}

void UCustomActionComponent::ShowDebugInfo()
{
	if(CurrentAction)
	{
		// Muestra el componente que eres para que pueda visualizar de quién es la acción
		if(GEngine)
		{
			GEngine->AddOnScreenDebugMessage(
				INDEX_NONE,
				GetWorld()->GetDeltaSeconds(),
				FColor::Green,
				FString::Printf(TEXT("Action owner: %s"), *GetOwner()->GetName()),
				false);
		}
		CurrentAction->GetDefaultObject<UCustomActionBase>()->ShowDebugInfo(GetWorld()->GetDeltaSeconds());
	}
}


