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

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
protected:
	
	virtual void BeginPlay() override;

	void DoAction(const TSubclassOf<UCustomActionBase>& ActionClass);
	void StopAction();

	void AddAction(const TSubclassOf<UCustomActionBase>& InNewAction);
	void RemoveAction(const TSubclassOf<UCustomActionBase>& InActionToRemove);

#if WITH_EDITOR
	void ShowDebugInfo();
#endif
	
private:

	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess = true))
	TArray<TSubclassOf<UCustomActionBase>> Actions;

	TSubclassOf<UCustomActionBase> CurrentAction;
};
