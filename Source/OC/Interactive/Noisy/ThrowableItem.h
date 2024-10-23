// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

// Base:
#include "CoreMinimal.h"
#include "OC/Interactive/InteractiveActor.h"

// Generated:
#include "ThrowableItem.generated.h"
//--------------------------------------------------------------------------------------



/* ---   Pre-declaration of classes   --- */

// Interaction:
class AOC_Character;
//--------------------------------------------------------------------------------------



UCLASS()
class OC_API AThrowableItem : public AInteractiveActor
{
	GENERATED_BODY()

public:

	/* ---   Constructors   --- */

	// Sets default values for this actor's properties
	AThrowableItem();
	//-------------------------------------------



protected:

	/* ---   Base   --- */

	/** Вызывается при запуске игры или при запуске spawn */
	virtual void BeginPlay() override;
	//-------------------------------------------



	/* ---   Collision   --- */

	// Звук удара данного Актора
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USoundBase* HitSound = nullptr;
	//-------------------------------------------



public:

	/* ---   Collision   --- */

	/**	Событие, когда этот Актор соприкасается с другим */
	virtual void NotifyHit(
		class UPrimitiveComponent* MyComp,
		AActor* Other,
		class UPrimitiveComponent* OtherComp,
		bool bSelfMoved,
		FVector HitLocation,
		FVector HitNormal,
		FVector NormalImpulse,
		const FHitResult& Hit) override;
	//-------------------------------------------



	/* ---   Interaction   --- */

	// Ротация, когда Подняли данный актор
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Settings")
	FRotator RotationWhenPickedUp = FRotator(-90.f, 0.f, 0.f);

	// Сила броска (так же зависит от "веса" данного Актора)
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Settings")
	float ThrowingPower = 5000.f;

	// Чувствительность звука: Предел для получаемого импульса при ударе,
	// при привышении которого воспроизводится звук удара
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Settings")
	float SoundSensitivity = 1000.f;

	// Настройка затухания издоваемого звука
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Settings")
	USoundAttenuation* SoundAttenuation = nullptr;

	//

	/** Событие, когда этот субъект находится под мышкой при нажатии клавиши реагирования с помощью интерактивного интерфейса */
	virtual void NotifyActorOnClicked(FKey ButtonReleased) override;
	//-------------------------------------------



private:

	/* ---   Collision   --- */

	/** Воспроизведение звука при каком-либо ударе данного Актора */
	void PlaySound();
	//-------------------------------------------



	/* ---   Interaction   --- */

	// Указатель на текущего игрока
	AOC_Character* CurrentCharacter = nullptr;

	//

	/** Включение физики данного Актора */
	void EnablingPhysics(const bool& bEnable);

	/** Подбор данного предмета */
	void PickUp();

	/** Бросок данного предмета */
	void Throw();

	/** Тихо положить данный предмет */
	void QuietlyPut();

	/** Отпустить Актор */
	void ReleaseActor();

	/** Привязка к управлению игрока */
	void BindToInput();
	//-------------------------------------------
};
