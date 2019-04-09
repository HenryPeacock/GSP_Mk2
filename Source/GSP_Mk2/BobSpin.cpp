// Fill out your copyright notice in the Description page of Project Settings.

#include "BobSpin.h"


// Sets default values for this component's properties
UBobSpin::UBobSpin()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
	bobHeight = 1.0f;
	bobSpeed = 1.0f;
	spinSpeed = 1.0f;
}


// Called when the game starts
void UBobSpin::BeginPlay()
{
	Super::BeginPlay();

	// ...
	startPos = GetOwner()->GetActorLocation();
}


// Called every frame
void UBobSpin::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// apply rotation motion to actor
	GetOwner()->AddActorLocalRotation(FRotator(0.0f, spinSpeed * DeltaTime, 0.0f));

	FVector Offset = FVector(0, 0, sin(GetWorld()->GetTimeSeconds()*bobSpeed) * DeltaTime * bobHeight);

	// apply bobbing motion offset to actor
	GetOwner()->SetActorLocation(startPos + Offset);
}

