// Fill out your copyright notice in the Description page of Project Settings.

// Base:
#include "OC_Character.h"

// UE:
#include "Components/CapsuleComponent.h"
#include "Camera/CameraComponent.h"
//--------------------------------------------------------------------------------------



/* ---   Constructors   --- */

AOC_Character::AOC_Character()
{
	// Установка вызова функции Tick() в каждом кадре.
	PrimaryActorTick.bCanEverTick = false; // Предварительно


	/* ---   Components   --- */

	// Create a CameraComponent	
	FirstPersonCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	FirstPersonCameraComponent->SetupAttachment(GetCapsuleComponent());
	FirstPersonCameraComponent->SetRelativeLocation(FVector(-39.56f, 1.75f, 64.f)); // Position the camera
	FirstPersonCameraComponent->bUsePawnControlRotation = true;

	GetMesh()->SetupAttachment(FirstPersonCameraComponent);
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
	PlayerInputComponent->BindAction("Crouch", IE_Pressed, this, &AOC_Character::StartCrouch);
	PlayerInputComponent->BindAction("Crouch", IE_Released, this, &AOC_Character::StopCrouch);

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
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void AOC_Character::LookUpAtRate(float Rate)
{
	// Вычисление дельты для текущего кадра на основе информации о скорости
	AddControllerPitchInput(-Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

void AOC_Character::StartCrouch()
{
	// Предваарительно: Из стандартного кода UE
	Super::Crouch();
	// Remark: Желательно заменить на плавный присед персонажа
}

void AOC_Character::StopCrouch()
{
	// Предваарительно: Из стандартного кода UE
	Super::UnCrouch();
	// Remark: Желательно заменить на плавный присед персонажа
}
//--------------------------------------------------------------------------------------
