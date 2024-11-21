// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AttributeSubsystem.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAttrOwnerRegistered, AActor*, RegActor);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnAttributeChanged, AActor*, AttrOwner, const FName&, InAttrName);


class IAttribute
{
public:
	FName AttrName;
};

template<typename T>
class AttributeBase : public IAttribute
{
public:
	

	T Value;
	
};




UCLASS(meta=(BlueprintSpawnableComponent))
class UAttributeComponent : public UActorComponent
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintAssignable)
	FOnAttributeChanged OnAttributeChanged;
};

UCLASS()
class UTHUB_CPP2024_API UAttributeSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

protected:

	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	virtual bool ShouldCreateSubsystem(UObject* Outer) const override;

	AttributeBase<float> Health;
	AttributeBase<FString> Name;

	TArray<IAttribute*> AttributeList;

	template<typename T>
	void SetAttribute(T Value, const FName& InName)
	{
		for(auto* Attribute : AttributeList)
		{
			if(Attribute->AttrName == InName)
			{
				AttributeBase<T>* Attr = dynamic_cast<AttributeBase<T>*>(AttributeList[0]);
				if(Attr)
				{
					Attr->Value = Value;
				}
			}
		}
	}

	
	
public:

	UFUNCTION(BlueprintCallable)
	void GetActorsWithAttributes(TArray<AActor*>& OutActors);

	UFUNCTION(BlueprintCallable)
	void ModifyAttributeFromActor(AActor* InActor, const FName& InAttrName, float InValue);

	UFUNCTION(BlueprintCallable)
	void AddAttrToActor(AActor* InActor);
	
	UPROPERTY(BlueprintAssignable)
	FOnAttrOwnerRegistered OnAttrOwnerRegistered;

	UPROPERTY(BlueprintAssignable)
	FOnAttributeChanged OnAttributeChanged;
	
private:

	void GetAllAttributeOwners(TArray<AActor*>& AttrOwners);
	void RegisterNewActor(AActor* InNewActor);

	UAttributeComponent* GetAttributeComponentFromActor(const AActor* InActor);
	
	UPROPERTY(VisibleAnywhere)
	TArray<AActor*> RegisteredAttrOwners;
};
