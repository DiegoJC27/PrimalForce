// Fill out your copyright notice in the Description page of Project Settings.


#include "SpiderSpawneer.h"

// Sets default values
ASpiderSpawneer::ASpiderSpawneer()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	ActorPool_Spider = CreateDefaultSubobject<UActorPool>(TEXT("Pool Spiders"));
}

void ASpiderSpawneer::SpawnSpider()
{
	if (ActorPool_Spider == nullptr || SpawnPoints.Num() == 0) return;

	AActor* Spider = ActorPool_Spider->GetActorFromPool();

	int rand = FMath::RandRange(0, SpawnPoints.Num() - 1);

	Spider->SetActorLocationAndRotation(SpawnPoints[rand]->GetActorLocation(),SpawnPoints[rand]->GetActorRotation());

	if (Spider->Implements<UIPooled>()) {
		IIPooled::Execute_OnSpawn(Spider, GetOwner());
	}
}

	// Called when the game starts or when spawned
void ASpiderSpawneer::BeginPlay()
{
	Super::BeginPlay();
	if (ActorPool_Spider != nullptr) {
		UE_LOG(LogTemp, Warning, TEXT("No es nulo"));
		//ActorPool_Spider->ForceInitialize();
	}
}

// Called every frame
void ASpiderSpawneer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

