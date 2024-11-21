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


// Called when the game starts
void UCustomActionComponent::BeginPlay()
{
	Super::BeginPlay();
	
}

void UCustomActionComponent::DoAction(const TSubclassOf<UCustomActionBase>& ActionClass)
{
	if(Actions.Contains(ActionClass))
	{
		ActionClass->GetDefaultObject<UCustomActionBase>()->DoAction(GetOwner());
	}
}


