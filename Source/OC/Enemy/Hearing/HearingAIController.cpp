// Fill out your copyright notice in the Description page of Project Settings.

// Base:
#include "HearingAIController.h"

// UE:
#include "BehaviorTree/BehaviorTree.h"

// UE | Perception:
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Hearing.h"
#include "Perception/AISenseConfig_Touch.h"

// Interaction:
//#include ""
//--------------------------------------------------------------------------------------



/* ---   Constructors   --- */

AHearingAIController::AHearingAIController()
{
	// Установка вызова функции Tick() в каждом кадре.
	PrimaryActorTick.bCanEverTick = true; // Принудительно!!!
	// Warning: Влияет на поворот области Зрения (Сенсорика)
	// При false не поворачивается область зрения, поэтому держим всегда true



	/* ---   Components   --- */

	// Сенсорика
	AIPerception = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("AI Perception"));

	// Доминантность по типу: 
	//PerceptionComponent->SetDominantSense(UAISenseConfig_Touch::StaticClass());
	// Error: Ошибка доступа к памяти;

	// Добавление Касания
	TouchSense = CreateDefaultSubobject<UAISenseConfig_Touch>(TEXT("Touch Sense"));
	AIPerception->ConfigureSense(*TouchSense);

	// Добавление Слуха
	HearingSense = CreateDefaultSubobject<UAISenseConfig_Hearing>(TEXT("Hearing Sense"));
	AIPerception->ConfigureSense(*HearingSense);
	//-------------------------------------------
}
//--------------------------------------------------------------------------------------



/* ---   Base   --- */

void AHearingAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	// Запуск выбранного Дерева поведения
	RunBehaviorTree(BehaviorTree);

	//UE_LOG(LogTemp, Warning, TEXT("'%s': OnPossess CHECK"), *GetNameSafe(this));
}
//--------------------------------------------------------------------------------------
