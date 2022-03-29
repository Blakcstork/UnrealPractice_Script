// Fill out your copyright notice in the Description page of Project Settings.


#include "CountDown.h"

// Sets default values
ACountDown::ACountDown()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	CountdownText = CreateDefaultSubobject<UTextRenderComponent>(TEXT("Countdown Text"));
	CountdownText->SetHorizontalAlignment(EHTA_Center);
	CountdownText->SetWorldSize(150.0f);
	RootComponent = CountdownText;

	CountdownTime = 3;
}

// Called when the game starts or when spawned
void ACountDown::BeginPlay()
{
	Super::BeginPlay();

	UpdateTimerDisplay();

	GetWorldTimerManager().SetTimer(CountdownTimerHandle, this, &ACountDown::AdvanceTimer, 1.0f, true);
	
}

void ACountDown::UpdateTimerDisplay() {
	CountdownText->SetText(FString::FromInt(FMath::Max(CountdownTime, 0)));
}


void ACountDown::AdvanceTimer() {
	--CountdownTime;
	UpdateTimerDisplay();

	if (CountdownTime < 1) {
		GetWorldTimerManager().ClearTimer(CountdownTimerHandle);
		CountdownHasFinished();
	}
}

void ACountDown::CountdownHasFinished_Implementation(){
	CountdownText->SetText(TEXT("Go!"));
}