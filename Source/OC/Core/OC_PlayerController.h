﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

// Base:
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"

// Generated:
#include "OC_PlayerController.generated.h"
//--------------------------------------------------------------------------------------



UCLASS()
class OC_API AOC_PlayerController : public APlayerController
{
	GENERATED_BODY()

public:

	/* ---   Constructors   --- */

	// Sets default values for this actor's properties
	AOC_PlayerController();
	//-------------------------------------------



	/* ---   Base   --- */

	/** Функция, вызываемая каждый кадр в этом Акторе */
	virtual void Tick(float DeltaSeconds) override;
	//-------------------------------------------



private:

	/* ---   Mouse   --- */

	// Текущая позиция мыши по оси X
	float MousePositionX = 0;

	// Текущая позиция мыши по оси Y
	float MousePositionY = 0;

	// Текущий центр экрана по оси X
	int32 SizeCenterX = 0;

	// Текущий центр экрана по оси Y
	int32 SizeCenterY = 0;

	//

	/** Установить Мышь в центр экрана */
	void SetMouseToCenter();
	//-------------------------------------------
};
