// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

// Base:
#include "CoreMinimal.h"
#include "GameFramework/Character.h"

// Generated:
#include "HearingEnemy.generated.h"
//--------------------------------------------------------------------------------------



/* ---   Pre-declaration of classes   --- */

// UE:
class UPawnSensingComponent;
class UBehaviorTree;
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



	/* ---   Components   --- */

	// Компонент Сенсорики, используемый для отслеживания других Пешек
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Components,
		meta = (AllowPrivateAccess = "true"))
	UPawnSensingComponent* PawnSensing;

	// Дерево поведения
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Components,
		meta = (AllowPrivateAccess = "true"))
	UBehaviorTree* BehaviorTree;
	//-------------------------------------------



protected:

	/* ---   Base   --- */

	// Вызывается при запуске игры или при запуске spawn
	virtual void BeginPlay() override;
	//-------------------------------------------



public:

	/* ---   Hearing   --- */

	/** Реакции на звук
	@param	PawnInstigator	- Пешка инициирующая звук
	@param	Location		- Местоположение источника звука
	@param	Volume			- Сила звука
	*/
	UFUNCTION()
	void OnHearNoise(APawn* PawnInstigator, const FVector& Location, float Volume);
	//-------------------------------------------



private:

};
