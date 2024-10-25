// Fill out your copyright notice in the Description page of Project Settings.

// Base:
#include "HearingAIController.h"

// UE:
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"

// Interaction:
#include "HearingEnemy.h"
//--------------------------------------------------------------------------------------



/* ---   Constructors   --- */

AHearingAIController::AHearingAIController()
{
	//Initialize our components
	BlackboardComp = CreateDefaultSubobject<UBlackboardComponent>(TEXT("BlackboardComp"));
	BehaviorTreeComp = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("BehaviorComp"));

}
//--------------------------------------------------------------------------------------



/* ---   Hearing   --- */

void AHearingAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	//if (InPawn)
	//{
	//	AHearingEnemy* Char = Cast<AHearingEnemy>(InPawn);

	//	//RunBehaviorTree(Char->BehaviorTree);

	//	// ���� ��� �������� �������� ���������� � ����� ���������� ������ ���������, ��
	//	if (Char && Char->BehaviorTree->BlackboardAsset)
	//	{
	//		// �������������� �������� �� �����
	//		BlackboardComp->InitializeBlackboard(*Char->BehaviorTree->BlackboardAsset);

	//		// ��������� ������
	//		BehaviorTreeComp->StartTree(*Char->BehaviorTree);
	//	}
	//}
}

void AHearingAIController::SetSensedTarget(APawn* NewTarget)
{
	// ���������� ���� �������������
	//if (BlackboardComp) BlackboardComp->SetValueAsObject(TargetKey, NewTarget);
}
//--------------------------------------------------------------------------------------
