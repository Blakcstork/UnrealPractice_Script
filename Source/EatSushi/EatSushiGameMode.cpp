// Copyright Epic Games, Inc. All Rights Reserved.

#include "EatSushiGameMode.h"
#include "EatSushiCharacter.h"
#include "UObject/ConstructorHelpers.h"

AEatSushiGameMode::AEatSushiGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
