// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

// Base:
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

// Generated:
#include "NoisyCoatings.generated.h"
//--------------------------------------------------------------------------------------



/* ---   Pre-declaration of classes   --- */

// UE:
class UBoxComponent;
//--------------------------------------------------------------------------------------



/* ---   Custom Structs   --- */

//
USTRUCT(BlueprintType)
struct FTypeCoating
{
	GENERATED_BODY()

	// Меш структуры взаимодействия
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMesh* CollisionMesh = nullptr;

	// Звук ходьбы по данному "покрытию"
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USoundBase* WalkingSound = nullptr;
};
//--------------------------------------------------------------------------------------



UCLASS()
class OC_API ANoisyCoatings : public AActor
{
	GENERATED_BODY()

public:

	/* ---   Constructors   --- */

	// Sets default values for this actor's properties
	ANoisyCoatings();
	//-------------------------------------------



	/* ---   Components   --- */

	// Меш-компонент данного Актора
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Components,
		meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* Mesh;

	// Компонент коллизии при отсутствии Меша
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Components,
		meta = (AllowPrivateAccess = "true"))
	UBoxComponent* BoxTrigger = nullptr;
	//-------------------------------------------



protected:

	/* ---   Base   --- */

	// Вызывается при запуске игры или при запуске spawn
	virtual void BeginPlay() override;
	//-------------------------------------------



	/* ---   Type   --- */

	// Выбор текущего типа
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Settings,
		meta = (GetOptions = "GetAllType"))
	FString CurrentType;

	// Настраиваемый тип по имени
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Settings)
	TMap<FString, FTypeCoating> Types;

	//

	/** Получить все типы */
	UFUNCTION()
	TArray<FString> GetAllType() const;
	//-------------------------------------------



public:

	/* ---   Base   --- */

	/** Вызывается при размещении экземпляра данного класса (в редакторе) или его запуске.
	@param	Transform	-- Трансформация данного Актора.
	*/
	virtual void OnConstruction(const FTransform& Transform) override;
	//-------------------------------------------



	/* ---   Collision   --- */

	/**	Событие, когда этот Актор перекрывается с другим */
	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;
	//-------------------------------------------



private:

	/* ---   Base   --- */

	/** Предварительное визуальное отображение */
	void Preview();

	/** Проверка и чистка Актора */
	void Checking();
	//-------------------------------------------



	/* ---   Collision   --- */

	/** Воспроизведение звука, соответствующий выбранному типу */
	void PlaySound();
	//-------------------------------------------
};
