// Fill out your copyright notice in the Description page of Project Settings.

#include "PickupActor.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
APickupActor::APickupActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	BobSpin = CreateDefaultSubobject<UBobSpin>("BobSpin");
	CollisionSphere = CreateDefaultSubobject<USphereComponent>("Collision Sphere");
}

// Called when the game starts or when spawned
void APickupActor::BeginPlay()
{
	Super::BeginPlay();
	
	CollisionSphere->OnComponentBeginOverlap.AddDynamic(this, &APickupActor::OnOverlapBegin);

	//player = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
}

// Called every frame
void APickupActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APickupActor::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (CollideTestActor != nullptr && OtherActor == CollideTestActor && this != nullptr)
	{
		Destroy();
	}
}