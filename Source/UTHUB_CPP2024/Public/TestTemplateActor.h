// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TestTemplateActor.generated.h"

// FString
// FName
// FText


template<typename T>
class Attribute
{
public:

	Attribute(T InValue = 0, FName InAttrName = TEXT("NONE"));

	T GetValue() const;
	void SetValue(T InValue);

	const FName& GetAttrName() const
	{
		return AttrName;
	}

private:

	T Value;
	FName AttrName;
};

template<typename T>
void Example()
{
}

template<int N>
class TArrayExample
{
	int Val = N;
};

UCLASS()
class UTHUB_CPP2024_API ATestTemplateActor : public AActor
{
	GENERATED_BODY()

public:

	TSoftObjectPtr<UStaticMesh> ObjSoftRef;
	
	// Sets default values for this actor's properties
	ATestTemplateActor();

	UFUNCTION(CallInEditor)
	void DoTest();

	void DoSomeStuff();

	UPROPERTY(EditAnywhere)
	TArray<AActor*> ListOfActors;

	Attribute<float> SpeedAttribute;

	TArray<Attribute<float>> FloatAttributes;
	
	UFUNCTION(BlueprintCallable) void CreateAttribute(const FName& InName, float InInitialValue);
	UFUNCTION(BlueprintCallable) void SetAttributeValue(const FName& InName, float Value);
	UFUNCTION(BlueprintCallable) void GetAttributeValue(const FName& InName, float& OutValue);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};

