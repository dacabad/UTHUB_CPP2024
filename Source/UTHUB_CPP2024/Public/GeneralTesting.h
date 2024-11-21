// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GeneralTesting.generated.h"




UCLASS()
class UTHUB_CPP2024_API AGeneralTesting : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AGeneralTesting();

	void SomeFunctionToFire();
	UFUNCTION(BlueprintCallable, CallInEditor)
	void DoTest();

	void SpawnProjectile(TSubclassOf<AActor> ProjectileClass);
	
	UPROPERTY(EditAnywhere)
	TSubclassOf<AActor> ActorClass;

	UPROPERTY(EditAnywhere)
	TSubclassOf<ACharacter> CharacterClass;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UClass> MyClass;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UObject> MyObjClass;

	UPROPERTY(EditAnywhere)
	UClass* SomeClass;

	UPROPERTY()
	UObject* a = nullptr;

	TStrongObjectPtr<UObject> ObjPtr;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:

	FTimerHandle TimerHandle_ShotFunction;
};
