// Fill out your copyright notice in the Description page of Project Settings.

// Base:
#include "NoisyCoatings.h"

// UE:
#include "Kismet/GameplayStatics.h"
#include "Components/BoxComponent.h"
#include "Perception/AISense_Hearing.h"

// Interaction:
#include "OC/Enemy/Hearing/HearingEnemy.h"
//--------------------------------------------------------------------------------------



/* ---   Constructors   --- */

ANoisyCoatings::ANoisyCoatings()
{
	// Установка вызова функции Tick() в каждом кадре.
	PrimaryActorTick.bCanEverTick = false; // Предварительно



	/* ---   Components   --- */

	// Корневой компонент
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));

	// Меш-компонент данного актора
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(RootComponent);
	Mesh->SetCollisionProfileName(TEXT("OverlapAll"));

	// Компонент коллизии при отсутствии Меша
	BoxTrigger = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Trigger"));
	BoxTrigger->SetupAttachment(RootComponent);
	BoxTrigger->SetRelativeLocation(FVector(0.f, 0.f, 3.f));
	BoxTrigger->SetRelativeScale3D(FVector(1.f, 1.f, 0.1f));
	//-------------------------------------------
}
//--------------------------------------------------------------------------------------



/* ---   Base   --- */

void ANoisyCoatings::BeginPlay()
{
	Super::BeginPlay();

	Checking();
}

void ANoisyCoatings::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);

	Preview();

	// Обновление данных о типах
	GetAllType();
}

void ANoisyCoatings::Preview()
{
	FTypeCoating* lCurrentSettingType = SettingsEachType.Find(CurrentType);

	if (lCurrentSettingType && lCurrentSettingType->CollisionMesh)
	{
		UStaticMesh* lSelectedMesh = lCurrentSettingType->CollisionMesh;

		if (lSelectedMesh != Mesh->GetStaticMesh())
		{
			Mesh->SetStaticMesh(lCurrentSettingType->CollisionMesh);
		}
	}
}

void ANoisyCoatings::Checking()
{
	FTypeCoating* lCurrentSettingType = SettingsEachType.Find(CurrentType);

	if (lCurrentSettingType)
	{
		if (lCurrentSettingType->CollisionMesh)
		{
			BoxTrigger->DestroyComponent();
		}
		else
		{
			Mesh->SetStaticMesh(nullptr);
			UE_LOG(LogTemp, Log, TEXT("'%s' has no Mesh. Custom collision will be enabled."), *GetNameSafe(this));
		}

		if (!lCurrentSettingType->WalkingSound)
		{
			UE_LOG(LogTemp, Error, TEXT("'%s' has no Sound"), *GetNameSafe(this));
		}
	}
}
//--------------------------------------------------------------------------------------



/* ---   Collision   --- */

void ANoisyCoatings::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);

	PlaySoundOfBeginOverlap();

	// Проверка воздействия Врага
	if (!Cast<AHearingEnemy>(OtherActor))
	{
		ReportNoiseOfBeginOverlap();
	}
}

void ANoisyCoatings::PlaySoundOfBeginOverlap()
{
	if (SettingsEachType.Find(CurrentType)->WalkingSound)
	{
		UGameplayStatics::PlaySoundAtLocation(
			GetWorld(),
			SettingsEachType.Find(CurrentType)->WalkingSound,
			GetActorLocation(),
			1.f, // Default
			1.f, // Default
			0.f, // Default
			SoundAttenuation);
	}
}

void ANoisyCoatings::ReportNoiseOfBeginOverlap()
{
	UAISense_Hearing::ReportNoiseEvent(
		GetWorld(),
		GetActorLocation(),
		1.f, // Default
		this);
}
//--------------------------------------------------------------------------------------



/* ---   Type   --- */

TArray<FString>& ANoisyCoatings::GetAllType()
{
	SettingsEachType.GetKeys(AllType);

	return AllType;
}
//--------------------------------------------------------------------------------------
