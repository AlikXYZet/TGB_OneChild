﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

// Base:
#include "CoreMinimal.h"
#include "GameFramework/Character.h"

// Generated:
#include "OC_Character.generated.h"
//--------------------------------------------------------------------------------------



/* ---   Pre-declaration of classes   --- */

// UE:
class UCameraComponent;
//--------------------------------------------------------------------------------------



UCLASS()
class OC_API AOC_Character : public ACharacter
{
	GENERATED_BODY()

public:

	/* ---   Constructors   --- */

	// Устанавливает значения по умолчанию для свойств этого персонажа
	AOC_Character();
	//-------------------------------------------



	/* ---   Components   --- */

	// Камера от первого лица
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Components,
		meta = (AllowPrivateAccess = "true"))
	UCameraComponent* FirstPersonCameraComponent;

	// Точка местоположения Подобранного Актора
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Components, 
		meta = (AllowPrivateAccess = "true"))
	USceneComponent* TakenActorLocationPoint = nullptr;

	// Подобранный Актор
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Components, 
		meta = (AllowPrivateAccess = "true"))
	UChildActorComponent* TakenActor = nullptr;
	//-------------------------------------------



protected:

	/* ---   Base   --- */

	// Вызывается при запуске игры или при запуске spawn
	virtual void BeginPlay() override;
	//-------------------------------------------



	/* ---   Input Action   --- */

	/** Вызывается для привязки функциональности к входным данным */
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	/** Запуск Прыжка */
	virtual void Jump() override;

	/** Прекращение Прыжка */
	virtual void StopJumping() override;

	/** Перемещение вперёд/назад */
	void MoveForward(float Val);

	/** Перемещение влево/вправо */
	void MoveRight(float Val);

	/**	Поворот с заданной скоростью */
	void TurnAtRate(float Rate);

	/**	Обзор вверх/вниз с заданной скоростью */
	void LookUpAtRate(float Rate);

	/** Начало Приседа */
	void ChangingCrouch();

	/** */
	UFUNCTION(BlueprintImplementableEvent, Category = "Hearing",
		meta = (DisplayName = "PlayAnimCrouch"))
	void EventPlayAnimCrouch();
	//-------------------------------------------



public:

	/* ---   Input Action   --- */

	// Базовая скорость поворота, град/сек
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Camera)
	float BaseTurnRate = 1.f;

	// Базовая скорость обзора вверх/вниз в градусах в секунду
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Camera)
	float BaseLookUpRate = 1.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement|State Control")
	bool bCrouchEnabled = false;
	//-------------------------------------------



private:

	/* ---   Base   --- */

	/**	Удаление пустых элементов текущего Актора */
	//void Cleaning();
	//-------------------------------------------
};
