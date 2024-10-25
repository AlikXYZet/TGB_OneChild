// Fill out your copyright notice in the Description page of Project Settings.

// Base:
#include "ThrowableItem.h"

// UE:
#include "Kismet/GameplayStatics.h"

// Interaction:
#include "OC/Core/OC_Character.h"
//--------------------------------------------------------------------------------------



/* ---   Constructors   --- */

AThrowableItem::AThrowableItem()
{
	// Установка вызова функции Tick() в каждом кадре.
	PrimaryActorTick.bCanEverTick = false; // Предварительно

	// Включение событие попадания (задействует NotifyHit)
	Mesh->SetNotifyRigidBodyCollision(true);
}
//--------------------------------------------------------------------------------------



/* ---   Base   --- */

void AThrowableItem::BeginPlay()
{
	Super::BeginPlay();
}
//--------------------------------------------------------------------------------------



/* ---   Collision   --- */

void AThrowableItem::NotifyHit(
	UPrimitiveComponent* MyComp,
	AActor* Other,
	UPrimitiveComponent* OtherComp,
	bool bSelfMoved,
	FVector HitLocation,
	FVector HitNormal,
	FVector NormalImpulse,
	const FHitResult& Hit)
{
	/* ---   Super   --- */
	Super::NotifyHit(
		MyComp,
		Other,
		OtherComp,
		bSelfMoved,
		HitLocation,
		HitNormal,
		NormalImpulse,
		Hit);
	//-------------------------------------------

	if (NormalImpulse.Size() >= SoundSensitivity)
	{
		PlaySound();

		EventWasHeard(HitLocation);
	}
}

void AThrowableItem::PlaySound()
{
	if (HitSound)
	{
		UGameplayStatics::PlaySoundAtLocation(
			GetWorld(),
			HitSound,
			GetActorLocation(),
			1.f, // Default
			1.f, // Default
			0.f, // Default
			SoundAttenuation);
	}
}
//--------------------------------------------------------------------------------------



/* ---   Interaction   --- */

void AThrowableItem::NotifyActorOnClicked(FKey ButtonReleased)
{
	Super::NotifyActorOnClicked(ButtonReleased);

	// Предварительное присвоение
	CurrentCharacter = Cast<AOC_Character>(GetWorld()->GetFirstPlayerController()->GetPawn());
	// Warning: Потребуется переделать, если переделывать на Multiplayer

	if (!CurrentCharacter)
	{
		UE_LOG(LogTemp, Error, TEXT("'%s': CurrentCharacter is NOT"), *GetNameSafe(this));
	}

	PickUp();
}

void AThrowableItem::PickUp()
{
	// Warning: Потребуется переделать, если переделывать проект на Multiplayer

	if (CurrentCharacter)
	{
		EnablingPhysics(false);

		// Привязка данного Актора к Игроку с указанной ротацией
		AttachToComponent(CurrentCharacter->TakenActorLocationPoint, FAttachmentTransformRules::SnapToTargetNotIncludingScale);
		SetActorRelativeRotation(RotationWhenPickedUp);
		// PS: Возможно, следует переделать на FTransform

		// Привязка к управлению игрока
		BindToInput();
	}
}

void AThrowableItem::Throw()
{
	ReleaseActor();

	if (CurrentCharacter)
	{
		FVector lCurrentLocation = CurrentCharacter->TakenActorLocationPoint->GetComponentLocation();
		FVector lCurrentRotation = CurrentCharacter->TakenActorLocationPoint->GetComponentRotation().Vector();

		FVector lCalcImpulse = lCurrentLocation + (lCurrentRotation * ThrowingPower);

		Mesh->AddImpulse(lCalcImpulse);
	}

	CurrentCharacter = nullptr;
}

void AThrowableItem::QuietlyPut()
{
	ReleaseActor();
	CurrentCharacter = nullptr;
}

void AThrowableItem::EnablingPhysics(const bool& bEnable)
{
	Mesh->SetSimulatePhysics(bEnable);
	Mesh->SetEnableGravity(bEnable);
	SetActorEnableCollision(bEnable);
}

void AThrowableItem::ReleaseActor()
{
	EnablingPhysics(true);
	DetachRootComponentFromParent();
}

void AThrowableItem::BindToInput()
{
	// Создание и регистрация компонента Ввода
	InputComponent = NewObject<UInputComponent>(this);
	InputComponent->RegisterComponent();

	if (InputComponent)
	{
		// Выложить данный Актор (тихо положить)
		InputComponent->BindAction("Interaction", IE_Released, this, &AThrowableItem::QuietlyPut);

		// Бросить данный Актор
		InputComponent->BindAction("Throw", IE_Released, this, &AThrowableItem::Throw);

		// Подключение к контроллеру игрока
		EnableInput(GetWorld()->GetFirstPlayerController());
		// Warning: Потребуется переделать, если переделывать проект на Multiplayer
	}
}
//--------------------------------------------------------------------------------------
