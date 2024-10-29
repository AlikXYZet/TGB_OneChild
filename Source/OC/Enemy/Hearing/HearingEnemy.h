// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

// Base:
#include "CoreMinimal.h"
#include "GameFramework/Character.h"

// Generated:
#include "HearingEnemy.generated.h"
//--------------------------------------------------------------------------------------



/* ---   Pre-declaration of classes   --- */
//--------------------------------------------------------------------------------------



UCLASS()
class OC_API AHearingEnemy : public ACharacter
{
	GENERATED_BODY()

public:

	/* ---   Constructors   --- */

	// Sets default values for this character's properties
	AHearingEnemy();
	//-------------------------------------------



protected:

	/* ---   Base   --- */

	// Вызывается при запуске игры или при запуске spawn
	virtual void BeginPlay() override;
	//-------------------------------------------



public:
private:
};
