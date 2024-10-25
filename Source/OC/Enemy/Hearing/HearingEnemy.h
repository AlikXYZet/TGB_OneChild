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

	// ��������� ���������, ������������ ��� ������������ ������ �����
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Components,
		meta = (AllowPrivateAccess = "true"))
	UPawnSensingComponent* PawnSensing;

	// ������ ���������
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Components,
		meta = (AllowPrivateAccess = "true"))
	UBehaviorTree* BehaviorTree;
	//-------------------------------------------



protected:

	/* ---   Base   --- */

	// ���������� ��� ������� ���� ��� ��� ������� spawn
	virtual void BeginPlay() override;
	//-------------------------------------------



public:

	/* ---   Hearing   --- */

	/** ������� �� ����
	@param	PawnInstigator	- ����� ������������ ����
	@param	Location		- �������������� ��������� �����
	@param	Volume			- ���� �����
	*/
	UFUNCTION()
	void OnHearNoise(APawn* PawnInstigator, const FVector& Location, float Volume);
	//-------------------------------------------



private:

};
