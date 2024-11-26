// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "CustomActionBase.generated.h"


class UCustomActionComponent;

UCLASS(Blueprintable, BlueprintType)
class UTHUB_CPP2024_API UCustomActionBase : public UObject
{
	GENERATED_BODY()

	friend UCustomActionComponent;
	
protected:
		
	virtual void DoAction(AActor* ActionInstigator);
	virtual void EndAction(AActor* ActionInstigator);
	
	UFUNCTION(BlueprintImplementableEvent)
	void ReceiveDoAction(AActor* ActionInstigator);

	UFUNCTION(BlueprintImplementableEvent)
	void ReceiveStopAction();

#if WITH_EDITOR
	UFUNCTION(BlueprintNativeEvent)
	void ShowDebugInfo(const float DeltaSeconds);
#endif
};

