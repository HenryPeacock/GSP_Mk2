// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "BobSpin.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GSP_MK2_API UBobSpin : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UBobSpin();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	// bobbing & spinning variables
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spin Effect")
		float spinSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Bob Effect")
		float bobSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Bob Effect")
		float bobHeight;

private:
	FVector startPos;
	
};
