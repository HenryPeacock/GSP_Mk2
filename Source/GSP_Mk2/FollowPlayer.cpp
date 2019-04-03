// Fill out your copyright notice in the Description page of Project Settings.

#include "FollowPlayer.h"


// Sets default values for this component's properties
UFollowPlayer::UFollowPlayer()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	speed = 1.0f;

	// ...
}


// Called when the game starts
void UFollowPlayer::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UFollowPlayer::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (IsValid(target))
	{
		FVector dir = GetOwner()->GetActorLocation() - target->GetActorLocation();
		dir.Normalize();

		FVector move = -dir * speed * DeltaTime;
		GetOwner()->SetActorLocation(GetOwner()->GetActorLocation() + move);
	}

}

