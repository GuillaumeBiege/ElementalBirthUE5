// Copyright Epic Games, Inc. All Rights Reserved.

#include "ElementalBirthUE5GameMode.h"
#include "ElementalBirthUE5Character.h"
#include "UObject/ConstructorHelpers.h"

AElementalBirthUE5GameMode::AElementalBirthUE5GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
