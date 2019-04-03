// Fill out your copyright notice in the Description page of Project Settings.

#include "Pickup.h"
#include "Components/SphereComponent.h"

// Sets default values for this component's properties
UPickup::UPickup()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

//	GetOwner()->GetGenerateOverlapEvents();
}


// Called when the game starts
void UPickup::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UPickup::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	//USphereComponent* s;
	//s->Oncomp

	//OnComponentBeginOverlap.AddDynamic(this, &UPickup::OnOverlapBegin);
}

void UPickup::OnOverlapBegin()
{
	if (player != nullptr)
	{
		GetOwner()->Destroy();
	}
}


