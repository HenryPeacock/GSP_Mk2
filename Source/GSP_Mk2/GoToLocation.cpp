// Fill out your copyright notice in the Description page of Project Settings.

#include "GoToLocation.h"

// Sets default values for this component's properties
UGoToLocation::UGoToLocation()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGoToLocation::BeginPlay()
{
	Super::BeginPlay();
	if (IsValid(target)) 
	{ 
		position = target->GetActorLocation(); 
	}

	APawn* p = Cast<APawn>(GetOwner());
	p->SpawnDefaultController();
	ai = Cast<AAIController>(p->GetController());

	path = UNavigationSystemV1::FindPathToLocationSynchronously(this, p->GetActorLocation(), position, ai);
	
	FAIMoveRequest req;
	//req.SetGoalLocation(position);
	req.SetAcceptanceRadius(10.0f);
	req.SetUsePathfinding(true);
	//ai->MoveTo(req);
	
	ai->RequestMove(req, path->GetPath());
	
	
}


// Called every frame
void UGoToLocation::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
}

