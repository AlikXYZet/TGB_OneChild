// Fill out your copyright notice in the Description page of Project Settings.


#include "OC_Character.h"

// Sets default values
AOC_Character::AOC_Character()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AOC_Character::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AOC_Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AOC_Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

