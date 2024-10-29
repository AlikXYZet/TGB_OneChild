// Fill out your copyright notice in the Description page of Project Settings.

// Base:
#include "HearingEnemy.h"
//--------------------------------------------------------------------------------------



/* ---   Constructors   --- */

// Sets default values
AHearingEnemy::AHearingEnemy()
{
	// Установка вызова функции Tick() в каждом кадре.
	PrimaryActorTick.bCanEverTick = false; // Предварительно

	// Коррекция Меша:
	GetMesh()->SetRelativeLocation(FVector(0.f, 0.f, -88.f));
	GetMesh()->SetRelativeRotation(FRotator(0.f, -90.f, 0.f));



	/* ---   Components   --- */
	//-------------------------------------------
}
//--------------------------------------------------------------------------------------



/* ---   Base   --- */

void AHearingEnemy::BeginPlay()
{
	Super::BeginPlay();
}
//--------------------------------------------------------------------------------------
