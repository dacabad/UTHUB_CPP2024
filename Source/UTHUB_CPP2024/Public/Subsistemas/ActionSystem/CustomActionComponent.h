// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CustomActionSubsystem.h"
#include "CustomActionComponent.generated.h"



UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class UTHUB_CPP2024_API UCustomActionComponent : public UActorComponent
{
	GENERATED_BODY()

	friend UCustomActionSubsystem;
	
public:
	UCustomActionComponent();

protected:
	
	virtual void BeginPlay() override;

	void DoAction(const TSubclassOf<UCustomActionBase>& ActionClass);
	
private:

	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess = true))
	TArray<TSubclassOf<UCustomActionBase>> Actions;	
};
