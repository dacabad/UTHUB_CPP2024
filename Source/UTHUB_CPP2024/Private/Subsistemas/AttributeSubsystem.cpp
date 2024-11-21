// Fill out your copyright notice in the Description page of Project Settings.


#include "Subsistemas/AttributeSubsystem.h"

#include "Kismet/GameplayStatics.h"

void UAttributeSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	GetAllAttributeOwners(RegisteredAttrOwners);
	
	// GetWorld()->OnActorSpawned.AddDynamic(this, &ThisClass::RegisterNewActor);
	// GetWorld()->OnActorSpawned.Add(Delegate);
	
	
	// FOnActorSpawned::FDelegate Delegate; // aquí vamos a guardar una función
	// Delegate.BindUObject(this, &ThisClass::RegisterNewActor);
	//
	// GetWorld()->AddOnActorSpawnedHandler(Delegate);
	
	
	FDelegateHandle Handle =
		GetWorld()->AddOnActorSpawnedHandler(FOnActorSpawned::FDelegate::CreateUObject(this, &ThisClass::RegisterNewActor));
	
}

void UAttributeSubsystem::Deinitialize()
{
	Super::Deinitialize();
}

bool UAttributeSubsystem::ShouldCreateSubsystem(UObject* Outer) const
{
	return Super::ShouldCreateSubsystem(Outer);
}

void UAttributeSubsystem::GetActorsWithAttributes(TArray<AActor*>& OutActors)
{
	OutActors = RegisteredAttrOwners;
}

void UAttributeSubsystem::ModifyAttributeFromActor(AActor* InActor, const FName& InAttrName, float InValue)
{
	for(auto* Actor : RegisteredAttrOwners)
	{
		if(Actor == InActor)
		{
			// GetAttributeComponentFromActor(InActor)->
			OnAttributeChanged.Broadcast(InActor, InAttrName);
		}
	}
}

void UAttributeSubsystem::AddAttrToActor(AActor* InActor)
{
	if(!InActor)
		return;

	InActor->AddComponentByClass(UAttributeComponent::StaticClass(), false, FTransform(), false);
	RegisterNewActor(InActor);
}

void UAttributeSubsystem::GetAllAttributeOwners(TArray<AActor*>& AttrOwners)
{
	TArray<AActor*> OutActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AActor::StaticClass(), OutActors);

	for(auto* Actor : OutActors)
	{
		if(Actor->FindComponentByClass<UAttributeComponent>())
		{
			AttrOwners.Add(Actor);
			OnAttrOwnerRegistered.Broadcast(Actor);
		}
	}
}

void UAttributeSubsystem::RegisterNewActor(AActor* InNewActor)
{
	if(GetAttributeComponentFromActor(InNewActor))
	{
		RegisteredAttrOwners.Add(InNewActor);
	}
}

UAttributeComponent* UAttributeSubsystem::GetAttributeComponentFromActor(const AActor* InActor)
{
	return InActor->FindComponentByClass<UAttributeComponent>();
}
