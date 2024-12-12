// Fill out your copyright notice in the Description page of Project Settings.


#include "Predicates/GenericUtils.h"

#include "EnhancedInputComponent.h"
#include "Kismet/GameplayStatics.h"

bool UGenericUtils::IsThereAnyActorCloseToMe(AActor* Me, const TArray<AActor*>& InActorList, float Distance)
{
	return InActorList.ContainsByPredicate([Me, Distance](AActor* InActor)
	{
		return InActor->GetDistanceTo(Me) < Distance;
	});
}

bool UGenericUtils::DoesAnyActorHaveComponent(const TArray<AActor*>& InActorList,
	const TSubclassOf<UActorComponent>& InComponentClass)
{
	return InActorList.ContainsByPredicate([InComponentClass](const AActor* InActor)
	{
		return InActor->FindComponentByClass(InComponentClass);
	});
}

bool UGenericUtils::HasAction(AActor* InActorToCheck, UInputAction* InAction)
{
	if(UEnhancedInputComponent* InputComponent = InActorToCheck->FindComponentByClass<UEnhancedInputComponent>())
	{
		return InputComponent->GetActionValueBindings().ContainsByPredicate([InAction](const FEnhancedInputActionValueBinding& Binding)
		{
			return Binding.GetAction() == InAction;
		});
	}
	
	return false;
}

void UGenericUtils::GetAllActorsOfClasses(const UObject* WorldContextObject,
                                          const TArray<TSubclassOf<AActor>>& ActorClasses, TArray<AActor*>& FilteredActors)
{
	if(WorldContextObject && WorldContextObject->GetWorld())
	{
		TArray<AActor*> OutActors;
		UGameplayStatics::GetAllActorsOfClass(WorldContextObject, AActor::StaticClass(), OutActors);

		FilteredActors = OutActors.FilterByPredicate([ActorClasses](AActor* InActor)
		{
			return ActorClasses.Contains(InActor->GetClass());
		});
	}
}

