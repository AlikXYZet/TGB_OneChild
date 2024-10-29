// Fill out your copyright notice in the Description page of Project Settings.

// Base:
#include "OC_Character.h"

// UE:
#include "Components/CapsuleComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/PawnNoiseEmitterComponent.h"
//--------------------------------------------------------------------------------------



/* ---   Constructors   --- */

AOC_Character::AOC_Character()
{
	// Установка вызова функции Tick() в каждом кадре.
	PrimaryActorTick.bCanEverTick = false; // Предварительно


	/* ---   Components   --- */

	// Камера от первого лица
	FirstPersonCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("First Person Camera"));
	FirstPersonCameraComponent->SetupAttachment(GetMesh(), FName(TEXT("head")));
	FirstPersonCameraComponent->SetRelativeLocation(FVector(0.f, 10.f, 0.f));
	FirstPersonCameraComponent->SetRelativeRotation(FRotator(0.f, 90.f, -90.f));
	FirstPersonCameraComponent->bUsePawnControlRotation = true;

	// Точка местоположения Подобранного Актора
	TakenActorLocationPoint = CreateDefaultSubobject<USceneComponent>(TEXT("Taken Actor Location Point"));;
	TakenActorLocationPoint->SetupAttachment(FirstPersonCameraComponent);
	TakenActorLocationPoint->SetRelativeLocation(FVector(40.f, 25.f, -30.f));
	//-------------------------------------------


	//Cleaning();
}
//--------------------------------------------------------------------------------------



/* ---   Base   --- */

void AOC_Character::BeginPlay()
{
	Super::BeginPlay();
}

//void AOC_Character::Cleaning()
//{
//	// Резерв
//}
//--------------------------------------------------------------------------------------



/* ---   Input Action   --- */

void AOC_Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// Прыжок:
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AOC_Character::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &AOC_Character::StopJumping);

	// Присед:
	PlayerInputComponent->BindAction("Crouch", IE_Pressed, this, &AOC_Character::ChangingCrouch);

	// Перемещение:
	PlayerInputComponent->BindAxis("MoveForward", this, &AOC_Character::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AOC_Character::MoveRight);

	// Поворот мышью:
	PlayerInputComponent->BindAxis("TurnRate", this, &AOC_Character::TurnAtRate);
	PlayerInputComponent->BindAxis("LookUpRate", this, &AOC_Character::LookUpAtRate);
}

void AOC_Character::Jump()
{
	Super::Jump();
}

void AOC_Character::StopJumping()
{
	Super::StopJumping();
}

void AOC_Character::MoveForward(float Value)
{
	if (Value != 0.0f)
	{
		// add movement in that direction
		AddMovementInput(GetActorForwardVector(), Value);
	}
}

void AOC_Character::MoveRight(float Value)
{
	if (Value != 0.0f)
	{
		// add movement in that direction
		AddMovementInput(GetActorRightVector(), Value);
	}
}

void AOC_Character::TurnAtRate(float Rate)
{
	// Вычисление дельты для текущего кадра на основе информации о скорости
	AddControllerYawInput(Rate * BaseTurnRate);
}

void AOC_Character::LookUpAtRate(float Rate)
{
	// Вычисление дельты для текущего кадра на основе информации о скорости
	AddControllerPitchInput(-Rate * BaseLookUpRate);
}

void AOC_Character::ChangingCrouch()
{
	if (bCrouchEnabled)
	{
		bCrouchEnabled = false;

		// Предварительно: Из стандартного кода UE
		Super::UnCrouch();
		// Remark: Желательно заменить на плавный присед персонажа
	}
	else
	{
		bCrouchEnabled = true;
		// Предварительно: Из стандартного кода UE
		Super::Crouch();
		// Remark: Желательно заменить на плавный присед персонажа
	}
}
//--------------------------------------------------------------------------------------
