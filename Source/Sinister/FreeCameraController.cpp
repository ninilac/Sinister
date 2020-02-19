// Fill out your copyright notice in the Description page of Project Settings.

#include "FreeCameraController.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/Pawn.h"
#include "Kismet/KismetMathLibrary.h"
#include "SinisterGameMode.h"
#include "SinisterCharacter.h"


AFreeCameraController::AFreeCameraController()
{
	bShowMouseCursor = true;
}

void AFreeCameraController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAxis("MoveRight", this, &AFreeCameraController::OnMoveRight);
	InputComponent->BindAxis("MoveForward", this, &AFreeCameraController::OnMoveForward);

	InputComponent->BindAction("SwitchCameraMode", IE_Pressed, this, &AFreeCameraController::OnSwitchCameraMode);
}

void AFreeCameraController::OnMoveRight(float scale)
{
	APawn* pawn = GetPawn();

	if (pawn) {
		if (scale > 0.3 || scale < -0.3) {
			FTransform pawnTransform = pawn->GetActorTransform();
			FVector direction(0, 1, 0);
			direction *= scale;
			FVector newPawnLocation = pawnTransform.GetLocation() + UKismetMathLibrary::TransformDirection(pawnTransform, direction);
			FTransform newPawnTransform(pawnTransform.GetRotation(), newPawnLocation, pawnTransform.GetScale3D());
			pawn->SetActorTransform(newPawnTransform);
		}
	}
}

void AFreeCameraController::OnMoveForward(float scale)
{
	APawn* pawn = GetPawn();

	if (pawn) {
		if (scale > 0.3 || scale < -0.3) {
			FTransform pawnTransform = pawn->GetActorTransform();
			FVector direction(1, 0, 0);
			direction *= scale;
			FVector newPawnLocation = pawnTransform.GetLocation() + UKismetMathLibrary::TransformDirection(pawnTransform, direction);
			FTransform newPawnTransform(pawnTransform.GetRotation(), newPawnLocation, pawnTransform.GetScale3D());
			pawn->SetActorTransform(newPawnTransform);
		}
	}
}

void AFreeCameraController::OnSwitchCameraMode()
{
	UWorld* world = GetWorld();
	ASinisterGameMode* gameMode = Cast<ASinisterGameMode>(world->GetAuthGameMode());
	ASinisterCharacter* pawn = gameMode->PlayerCharacter;

	gameMode->SwapPlayerControllers(this, gameMode->ThirdPersonController);
	UnPossess();

	gameMode->ThirdPersonController->Possess(pawn);
}
