// Fill out your copyright notice in the Description page of Project Settings.

// Base:
#include "HearingEnemy.h"

// UE:
#include "Perception/PawnSensingComponent.h"
#include "BehaviorTree/BehaviorTree.h"
//--------------------------------------------------------------------------------------



/* ---   Constructors   --- */

// Sets default values
AHearingEnemy::AHearingEnemy()
{
	// ��������� ������ ������� Tick() � ������ �����.
	PrimaryActorTick.bCanEverTick = false; // ��������������

	// ��������� ����:
	GetMesh()->SetRelativeLocation(FVector(0.f, 0.f, -88.f));
	GetMesh()->SetRelativeRotation(FRotator(0.f, -90.f, 0.f));


	/* ---   Components   --- */

	// ��������� ���������
	PawnSensing = CreateDefaultSubobject<UPawnSensingComponent>(TEXT("Pawn Sensing"));
	PawnSensing->bOnlySensePlayers = false;
	PawnSensing->bSeePawns = false;
	PawnSensing->HearingThreshold = 6000.f;
	PawnSensing->LOSHearingThreshold = 6001.f;
	PawnSensing->HearingMaxSoundAge;
	PawnSensing->SensingInterval = 0.2f;

	// ������ ���������
	BehaviorTree = CreateDefaultSubobject<UBehaviorTree>(TEXT("Behavior Tree"));
	//-------------------------------------------
}
//--------------------------------------------------------------------------------------



/* ---   Base   --- */

void AHearingEnemy::BeginPlay()
{
	Super::BeginPlay();

	if (PawnSensing)
	{
		//Registering the delegate which will fire when we hear something
		PawnSensing->OnHearNoise.AddDynamic(this, &AHearingEnemy::OnHearNoise);
	}

}



/* ---   Hearing   --- */

void AHearingEnemy::OnHearNoise(APawn* PawnInstigator, const FVector& Location, float Volume)
{
	// ����������: �� "�������" ������ ����
	if (PawnInstigator != this)
	{
		UE_LOG(LogTemp, Error, TEXT("Sound"));
	}
}
//--------------------------------------------------------------------------------------
