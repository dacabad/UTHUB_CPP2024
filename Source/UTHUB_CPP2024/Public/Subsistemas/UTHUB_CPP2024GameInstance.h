// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "UTHUB_CPP2024GameInstance.generated.h"


UCLASS()
class UTHUB_CPP2024_API UUTHUB_CPP2024GameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void SomeFunction(AActor* RegActor);
	virtual void Init() override;
};
