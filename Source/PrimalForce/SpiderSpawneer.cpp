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
	AActor* Spider = ActorPool_Spider->GetActorFromPool();
	if (!Spider) return;

	int rand = FMath::RandRange(0, SpawnPoints.Num() - 1);
	Spider->SetActorLocationAndRotation(SpawnPoints[rand]->GetActorLocation(),SpawnPoints[rand]->GetActorRotation());

	ASpiderAI* SpiderAI = Cast<ASpiderAI>(Spider);
	if (!SpiderAI || !playerRef) return;

	SpiderAI->SetPlayerLocation(playerRef->GetActorLocation());

	SpiderAI->ActivateBrain();

	ActiveSpiders.Add(SpiderAI);

	if (Spider->Implements<UIPooled>())
	{
		IIPooled::Execute_OnSpawn(Spider, this->GetOwner());
	}

}

void ASpiderSpawneer::DisableSpiderIA(AActor* spider)
{
	if (!spider) return;

	APawn* Pawn = Cast<APawn>(spider);
	if (!Pawn) return;

	AAIController* iaSpider = Cast<AAIController>(Pawn->GetController());
	if (!iaSpider) return;

	ASpiderAI* SpiderAI = Cast<ASpiderAI>(spider);
	if (SpiderAI)
	{
		ActiveSpiders.Remove(SpiderAI);
		SpiderAI->DeactivateBrain();
	}
}

void ASpiderSpawneer::BeginPlay()
{
	Super::BeginPlay();
	playerRef = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (ActorPool_Spider != nullptr) {
		UE_LOG(LogTemp, Warning, TEXT("No es nulo"));
		//ActorPool_Spider->ForceInitialize();
	}
	for (AActor* Spider : ActorPool_Spider->actorPool)
	{
		if (Spider->Implements<UIPooled>()) {
			IIPooled::Execute_OnDeSpawn(Spider, this->GetOwner());
		}
	}
}

void ASpiderSpawneer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASpiderSpawneer::UpdatePlayerLocation()
{
	if (!playerRef) return;
	FVector playerlocation = playerRef->GetActorLocation();

	for (ASpiderAI* spider : ActiveSpiders) {
		spider->SetPlayerLocation(playerRef->GetActorLocation());
	}
}

