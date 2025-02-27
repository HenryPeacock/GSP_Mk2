// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AIController.h"
#include "Runtime/NavigationSystem/Public/NavigationPath.h"
#include "NavigationSystem.h"


#include "GoToLocation.generated.h"




UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GSP_MK2_API UGoToLocation : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGoToLocation();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Target")
		AActor* target;
	AAIController* ai;
	UNavigationPath* path;
	

protected:
	// Called when the game starts
	virtual void BeginPlay() override;	
	FVector position;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;


		
	
};
