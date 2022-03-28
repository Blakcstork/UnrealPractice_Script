// Fill out your copyright notice in the Description page of Project Settings.


#include "FloatingActor.h"

// Sets default values
AFloatingActor::AFloatingActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	FloatingSpeed = FVector(1.0f,1.0f,1.0f);
}

// Called when the game starts or when spawned
void AFloatingActor::BeginPlay()
{
	Super::BeginPlay();
	
	UE_LOG(LogTemp, Log, TEXT("Log Message"));

	FString CharacterName = TEXT("HiWer");
	UE_LOG(LogTemp, Log, TEXT("Character name = %s"), *CharacterName);

	bool isAttackable = true;
	UE_LOG(LogTemp, Log, TEXT("Is Attackable? = %s"), isAttackable ? TEXT("true") : TEXT("false"));
}

// Called every frame
void AFloatingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector NewLocation = GetActorLocation();
	float DeltaX = FMath::Sin(RunningTime.X + DeltaTime * FloatingSpeed.X) - FMath::Sin(RunningTime.X);
	float DeltaY = FMath::Sin(RunningTime.Y + DeltaTime * FloatingSpeed.Y) - FMath::Sin(RunningTime.Y);
	float DeltaZ = FMath::Sin(RunningTime.Z + DeltaTime * FloatingSpeed.Z) - FMath::Sin(RunningTime.Z);
	NewLocation += FVector(DeltaX,DeltaY,DeltaZ) * 20.0f;
	RunningTime += DeltaTime * FloatingSpeed;
	SetActorLocation(NewLocation);
}

