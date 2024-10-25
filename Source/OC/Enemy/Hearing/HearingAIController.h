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
class UBehaviorTreeComponent;
class UBlackboardComponent;
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



protected:

	/* ---   Components   --- */

	// Компонент дерева поведения, позволяющий вызывать определенные функции, такие как запуск нашего BT
	UBehaviorTreeComponent* BehaviorTreeComp;

	// Компонент Blackboard, который будет использоваться для инициализации наших значений на доске Дерева поведения
	UBlackboardComponent* BlackboardComp;
	//-------------------------------------------



public:

	/* ---   Hearing   --- */

	// Ключ для поиска
	UPROPERTY(EditDefaultsOnly)
	FName TargetKey = "SensedPawn";

	//

	/** Вызывается при подключении к Пешке */
	virtual void OnPossess(APawn* InPawn) override;

	/** Устанавливает новое измеренное целевое значение внутри наших значений на доске */
	void SetSensedTarget(APawn* NewTarget);
	//-------------------------------------------
};
