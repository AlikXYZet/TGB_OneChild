// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

// Base:
#include "CoreMinimal.h"
#include "AIController.h"

// Generated:
#include "HearingAIController.generated.h"
//--------------------------------------------------------------------------------------



/* ---   Pre-declaration of classes   --- */

// UE:
class UBehaviorTree;

// UE | Perception:
class UAIPerceptionComponent;
class UAISenseConfig_Touch;
class UAISenseConfig_Hearing;
//--------------------------------------------------------------------------------------



UCLASS()
class OC_API AHearingAIController : public AAIController
{
	GENERATED_BODY()



public:

	/* ---   Constructors   --- */

	// Sets default values for this character's properties
	AHearingAIController();
	//-------------------------------------------



	/* ---   Components   --- */

	// Компонент Сенсорики, используемый для отслеживания других Пешек
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Components,
		meta = (AllowPrivateAccess = "true"))
	UAIPerceptionComponent* AIPerception;
	//-------------------------------------------



protected:

	/* ---   AI   --- */

	// Дерево поведения, используемое в AI
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Settings")
	UBehaviorTree* BehaviorTree;
	//-------------------------------------------



public:

	/* ---   Base   --- */

	/** Вызывается при подключении к Пешке */
	virtual void OnPossess(APawn* InPawn) override;
	//-------------------------------------------



	/* ---   Perception   --- */

	// Касание
	UAISenseConfig_Touch* TouchSense;

	// Слух
	UAISenseConfig_Hearing* HearingSense;
	//-------------------------------------------



private:

};
