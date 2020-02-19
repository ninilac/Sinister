// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "FreeCameraController.generated.h"

/**
 * 
 */
UCLASS()
class SINISTER_API AFreeCameraController : public APlayerController
{
	GENERATED_BODY()

public:
	AFreeCameraController();

protected:
	virtual void SetupInputComponent() override;

	void OnMoveRight(float scale);
	void OnMoveForward(float scale);
	
	void OnSwitchCameraMode();

};
