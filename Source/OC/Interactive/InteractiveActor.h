// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

// Base:
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

// Generated:
#include "InteractiveActor.generated.h"
//--------------------------------------------------------------------------------------



UCLASS()
class OC_API AInteractiveActor : public AActor
{
	GENERATED_BODY()

public:

	/* ---   Constructors   --- */

	// Sets default values for this actor's properties
	AInteractiveActor();
	//-------------------------------------------



	/* ---   Components   --- */

	// Меш-компонент данного актора
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Components,
		meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* Mesh;
	//-------------------------------------------



protected:

public:

	/* ---   Interaction   --- */

	/** Событие, когда на него наводят курсор мыши с помощью интерактивного интерфейса */
	virtual void NotifyActorBeginCursorOver() override;

	/** Событие, когда с него убирают курсор мыши с помощью интерактивного интерфейса */
	virtual void NotifyActorEndCursorOver() override;
	//-------------------------------------------
};
