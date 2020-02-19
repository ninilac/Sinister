// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "SinisterGameMode.h"
#include "SinisterPlayerController.h"
#include "SinisterCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "UObject/UObjectHash.h"

ASinisterGameMode::ASinisterGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = ASinisterPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDownCPP/Blueprints/TopDownCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

void ASinisterGameMode::BeginPlay()
{
	Super::BeginPlay();

	UWorld* world = GetWorld();

	TArray<UObject*> results;
	GetObjectsOfClass(CharacterStartClass, results, false);
	FTransform startLocation = Cast<AActor>(results[0])->GetActorTransform();

	PlayerCharacter = world->SpawnActor<ASinisterCharacter>();
	ThirdPersonController = world->SpawnActor<ASinisterPlayerController>();
	FreeCameraController = world->SpawnActor<AFreeCameraController>();
	FreeCameraPawn = world->SpawnActor<AFreeCameraPawn>();
}