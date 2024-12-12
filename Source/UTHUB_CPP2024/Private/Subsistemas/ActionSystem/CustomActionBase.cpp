// Fill out your copyright notice in the Description page of Project Settings.


#include "Subsistemas/ActionSystem/CustomActionBase.h"

void UCustomActionBase::DoAction(AActor* ActionInstigator)
{
	// Inicialización de las acciones
	
	ReceiveDoAction(ActionInstigator);
}

void UCustomActionBase::EndAction(AActor* ActionInstigator)
{
	// End action

	ReceiveStopAction();
}

void UCustomActionBase::ShowDebugInfo_Implementation(const float DeltaSeconds)
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(
			INDEX_NONE,
			DeltaSeconds,
			FColor::White,
			FString::Printf(TEXT("	%s is active"), *GetName()),
			false);
	}
}
