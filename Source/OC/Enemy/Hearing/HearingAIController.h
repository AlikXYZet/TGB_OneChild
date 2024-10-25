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

	// ��������� ������ ���������, ����������� �������� ������������ �������, ����� ��� ������ ������ BT
	UBehaviorTreeComponent* BehaviorTreeComp;

	// ��������� Blackboard, ������� ����� �������������� ��� ������������� ����� �������� �� ����� ������ ���������
	UBlackboardComponent* BlackboardComp;
	//-------------------------------------------



public:

	/* ---   Hearing   --- */

	// ���� ��� ������
	UPROPERTY(EditDefaultsOnly)
	FName TargetKey = "SensedPawn";

	//

	/** ���������� ��� ����������� � ����� */
	virtual void OnPossess(APawn* InPawn) override;

	/** ������������� ����� ���������� ������� �������� ������ ����� �������� �� ����� */
	void SetSensedTarget(APawn* NewTarget);
	//-------------------------------------------
};
