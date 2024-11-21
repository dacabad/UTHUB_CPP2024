// Copyright Epic Games, Inc. All Rights Reserved.

#include "UTHUB_CPP2024GameMode.h"
#include "UTHUB_CPP2024Character.h"
#include "UObject/ConstructorHelpers.h"

AUTHUB_CPP2024GameMode::AUTHUB_CPP2024GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
