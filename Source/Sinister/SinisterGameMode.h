// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GameFramework/PlayerStart.h"
#include "SinisterCharacter.h"
#include "SinisterPlayerController.h"
#include "FreeCameraController.h"
#include "SinisterGameMode.generated.h"

UCLASS(minimalapi, blueprintable)
class ASinisterGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ASinisterGameMode();
	virtual void BeginPlay();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Player, meta = (AllowPrivateAccess = "true"))
	UClass* CharacterStartClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Player, meta = (AllowPrivateAccess = "true"))
	UClass* PlayerCharacterClass;

	ASinisterCharacter* PlayerCharacter;
	ASinisterPlayerController* ThirdPersonController;
	AFreeCameraController* FreeCameraController;
	AFreeCameraPawn* FreeCameraPawn;
};