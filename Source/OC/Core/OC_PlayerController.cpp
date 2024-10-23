// Fill out your copyright notice in the Description page of Project Settings.

// Base:
#include "OC_PlayerController.h"
//--------------------------------------------------------------------------------------



/* ---   Constructors   --- */

AOC_PlayerController::AOC_PlayerController()
{
	// Установка вызова функции Tick() в каждом кадре.
	PrimaryActorTick.bCanEverTick = true;
	//-------------------------------------------


	/* ---   Mouse   --- */

	// Дистанция подбора предмета (трассировки наведения Мыши)
	HitResultTraceDistance = 200.f;

	// Включение реакций от наведения мыши данным контроллером
	bEnableMouseOverEvents = true;

	// Включение реакций от нажатия мыши данным контроллером
	bEnableClickEvents = true;

	// Очистка и Добавление клавиши взаимодействия: E
	ClickEventKeys.Empty();
	ClickEventKeys.Add(EKeys::E);
	//-------------------------------------------
}
//--------------------------------------------------------------------------------------



/* ---   Base   --- */

void AOC_PlayerController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	SetMouseToCenter();
}
//--------------------------------------------------------------------------------------



/* ---   Mouse   --- */

void AOC_PlayerController::SetMouseToCenter()
{
	if (!IsPaused())
	{
		if (GetMousePosition(MousePositionX, MousePositionY))
		{
			GetViewportSize(SizeCenterX, SizeCenterY);

			SizeCenterX /= 2;
			SizeCenterY /= 2;

			if (MousePositionX != SizeCenterX || MousePositionY != SizeCenterY)
			{
				SetMouseLocation(SizeCenterX, SizeCenterY);
			}
		}
	}
}
//--------------------------------------------------------------------------------------
