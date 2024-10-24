// Fill out your copyright notice in the Description page of Project Settings.

// Base:
#include "InteractiveActor.h"

// UE:
#include "Kismet/GameplayStatics.h"
//--------------------------------------------------------------------------------------



/* ---   Constructors   --- */

AInteractiveActor::AInteractiveActor()
{
	// Установка вызова функции Tick() в каждом кадре.
	PrimaryActorTick.bCanEverTick = false; // Предварительно



	/* ---   Components   --- */

	// Меш-компонент данного актора (Корневой компонент)
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = Mesh;
	Mesh->SetCollisionProfileName("IgnoreOnlyPawn");
	Mesh->SetSimulatePhysics(true);
	Mesh->SetEnableGravity(true);
	//-------------------------------------------
}
//--------------------------------------------------------------------------------------



/* ---   Interaction   --- */

void AInteractiveActor::NotifyActorBeginCursorOver()
{
	Super::NotifyActorBeginCursorOver();

	Mesh->SetRenderCustomDepth(true);
}

void AInteractiveActor::NotifyActorEndCursorOver()
{
	Super::NotifyActorEndCursorOver();

	Mesh->SetRenderCustomDepth(false);
}
//--------------------------------------------------------------------------------------
