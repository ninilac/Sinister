// Fill out your copyright notice in the Description page of Project Settings.

#include "FreeCameraPawn.h"


// Sets default values
AFreeCameraPawn::AFreeCameraPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFreeCameraPawn::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AFreeCameraPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AFreeCameraPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

