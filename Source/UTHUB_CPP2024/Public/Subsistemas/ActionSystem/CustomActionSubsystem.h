// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/LocalPlayer.h"
#include "CustomActionSubsystem.generated.h"

class UCustomActionComponent;
class UCustomActionBase;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnActionEvent, AActor*, ActionInstigator, TSubclassOf<UCustomActionBase>, Action);




// Delegate single
// Delegate multicast

template<typename FunctorType>
class FCustomMulticastDelegate
{	
	class FSingleDelegate
	{
		TFunction<void()> Functor;

	public:
		void Bind(TFunction<void()> InFunction);

		bool Execute()
		{
			Functor();
			return true;
		};
	};
	
	// TArray<TFunction<void()>> FunctionList;
	TArray<FSingleDelegate> FunctionList;
	
public:
	
	FCustomMulticastDelegate();

	void AddFunction(TFunctionRef<void()> InFunction); // REGISTRO LOS OBSERVADORES
	void Add(FSingleDelegate InDelegate);
	
	void Broadcast()
	{
		for(auto Func : FunctionList)
		{
			Func.Execute();
		}
	};
};

UCLASS()
class UTHUB_CPP2024_API UCustomActionSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

protected:

	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	virtual bool ShouldCreateSubsystem(UObject* Outer) const override;

public:

	UFUNCTION(BlueprintPure)
	static UCustomActionSubsystem* GetActionSubsystem(const UObject* WorldContextObject);
	
	UFUNCTION(BlueprintCallable)
	void DoAction(AActor* InActor, const TSubclassOf<UCustomActionBase>& InAction);
	
	UFUNCTION(BlueprintCallable)
	void DoActionSequence(AActor* InActor, const TArray<TSubclassOf<UCustomActionBase>>& InActionSequence);

	DECLARE_DYNAMIC_DELEGATE_TwoParams(FSingleActionEvent, AActor*, ActionInstigator, TSubclassOf<UCustomActionBase>, Action);
	UFUNCTION(BlueprintCallable)
	void DoActionAndWait(AActor* InActor, const TSubclassOf<UCustomActionBase>& InAction, FSingleActionEvent OnActionFinishedSingleEvent);
	
	// void DoActionAndWait(AActor* InActor, const TSubclassOf<UCustomActionBase>& InAction, TBaseDynamicDelegate<AActor*, TSubclassOf<UCustomActionBase>> OnActionFinished);
	void DoActionAndWait(AActor* InActor, const TSubclassOf<UCustomActionBase>& InAction, FOnActionEvent::FDelegate OnActionFinished);
	
	UFUNCTION(BlueprintCallable)
	void StopCurrentAction(AActor* InActor);
	
	UFUNCTION(BlueprintCallable)
	void AddActionToActor(AActor* InActor, const TSubclassOf<UCustomActionBase>& InNewAction);

	UFUNCTION(BlueprintCallable)
	void RemoveActionFromActor(AActor* InActor, const TSubclassOf<UCustomActionBase>& InNewAction);

	UFUNCTION(BlueprintCallable)
	void ExecuteMassiveAction(const TSubclassOf<UCustomActionBase>& InAction);

	UPROPERTY(BlueprintAssignable)
	FOnActionEvent OnActionStarted;

	UPROPERTY(BlueprintAssignable)
	FOnActionEvent OnActionFinished;
	
private:

	void RegisterActionEnabledActors();
	void RegisterActionEnabledActor(AActor* InActor);

	UCustomActionComponent* GetCustomActionComponent(AActor* InActor) const;
	
	UPROPERTY()
	TArray<AActor*> EnabledActors;

	
#if WITH_EDITOR
	void ShowDebugInfo();
#endif

public:
};
