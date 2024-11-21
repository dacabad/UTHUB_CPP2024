// Fill out your copyright notice in the Description page of Project Settings.


#include "TestTemplateActor.h"

#include "Components/CapsuleComponent.h"


//template <typename T>
//Attribute<T>::Attribute() : Value(0)
//{
//}

template <typename T>
Attribute<T>::Attribute(T InValue, FName InAttrName)
{
	Value = InValue;
	AttrName = InAttrName;
}

template <typename T>
T Attribute<T>::GetValue() const
{
	return Value;
}

template <typename T>
void Attribute<T>::SetValue(T InValue)
{
	Value = InValue;
}

template <typename T, typename T2>
T Sum(T ParamA, T2 ParamB)
{
	return ParamA + ParamB;
}


// Sets default values
ATestTemplateActor::ATestTemplateActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

void GetActorInfo(AActor& InActor)
{
	
	
}

void GetActorInfoFromPtr(AActor* InActor)
{

}

template<typename T, int N>
class TAllocExample
{
	TAllocExample()
	{
		Data = new T[N];
		Size = N;
	}
	
public:
	
	TAllocExample(T InitialValue = T());
	
	
	~TAllocExample()
	{
		delete[] Data;
	}

	void AddElement(const T& InValue, SIZE_T Index)
	{
		check(Index <= (Size - 1) && Index >= 0)
		
		*(Data + Index) = InValue;
	}

	T& GetElement(SIZE_T Index) const
	{
		check(Index <= (Size - 1) && Index >= 0)
		
		return *(Data + Index); 
	}

	T& operator[](SIZE_T Index) const
	{
		//return const_cast<TAllocExample<T, N>>(this)[Index];
		
		check(Index <= (Size - 1) && Index >= 0)
		return *(Data + Index);
	}

	T& operator[](SIZE_T Index)
	{
		check(Index <= (Size - 1) && Index >= 0)
		return *(Data + Index);
	}
	
	bool operator==(const TAllocExample& rhs) const
	{
		for(SIZE_T i = 0; i < Size; ++i)
		{
			if(Data[i] != rhs[i])
			{
				return false;
			}
		}

		return true;
	}


	const T* operator*() const
	{
		return Data;
	}
	
private:

	T* Data;
	SIZE_T Size;
};

template <typename T, int N>
TAllocExample<T, N>::TAllocExample(T InitialValue)
{
}


void ATestTemplateActor::DoTest()
{	
	TAllocExample<int, 10> ListOfInts(0);
	ListOfInts.AddElement(20, 3);
	ListOfInts.GetElement(0) = 20;

}

void ATestTemplateActor::CreateAttribute(const FName& InName, float InInitialValue)
{
	// const Attribute<float> NewAttr = Attribute<float>(InInitialValue, InName);
	const Attribute<float> NewAttr(InInitialValue, InName);
	
	FloatAttributes.Add(NewAttr);
}

void ATestTemplateActor::SetAttributeValue(const FName& InName, float Value)
{
	for (Attribute<float>& Attr : FloatAttributes)
	{
		if (Attr.GetAttrName().IsEqual(InName))
		{
			Attr.SetValue(Value);
			return;
		}
	}
}

void ATestTemplateActor::GetAttributeValue(const FName& InName, float& OutValue)
{
	for (const Attribute<float>& Attr : FloatAttributes)
	{
		if (Attr.GetAttrName().IsEqual(InName))
		{
			OutValue = Attr.GetValue();
			return;
		}
	}
}

// Called when the game starts or when spawned
void ATestTemplateActor::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ATestTemplateActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
