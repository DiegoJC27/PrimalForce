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
	APawn* Pawn = Cast<APawn>(Spider);
	if (Pawn) currentAISPIDER = Pawn->GetController<ASpiderAI>();
	
	if (!currentAISPIDER || !playerRef) {
		UE_LOG(LogTemp, Warning, TEXT("No Encontro una arania"));
		return;
	}
	currentAISPIDER->StartBehaiviourTree(playerRef);
	//SpiderAI->SetPlayerLocation(playerRef->GetActorLocation());
	

	//SpiderAI->ActivateBrain();

	ActiveSpiders.Add(currentAISPIDER);

	if (Spider->Implements<UIPooled>())
	{
		IIPooled::Execute_OnSpawn(Spider, this->GetOwner());
	}

}

void ASpiderSpawneer::DeSpawnSpider(AActor* spider)
{
	if (!spider) return;
	ActorPool_Spider->HideActor(spider,true);
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
	if (APawn* PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn())
	{
		playerRef = Cast<APrimalForceCharacter>(PlayerPawn);
		//UE_LOG(LogTemp, Warning, TEXT("Encontro player"));
	}
	if(playerRef)	UE_LOG(LogTemp, Warning, TEXT("Encontro player"));

	if (ActorPool_Spider != nullptr) {
		UE_LOG(LogTemp, Warning, TEXT("No es nulo"));
		//ActorPool_Spider->ForceInitialize();
	}

	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ATowerDefense::StaticClass(), towers);
}

void ASpiderSpawneer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	for (ASpiderAI* spider : ActiveSpiders) {
		UpdateTowerLocation(spider);
		UpdateFirePlaceLocation(spider);
		//UpdatePlayerLocation(spider);
	}

	//Lógica del spawn de las arañas
	timeSinceLastSpawn += DeltaTime;

	if (timeSinceLastSpawn >= spawnRate && canSpawn) {
		SpawnSpider();
		spawnRate -= normalTimeReduction;
		
		spawnRate = spawnRate < minimumSpawnRate ? minimumSpawnRate : spawnRate;
		timeSinceLastSpawn = 0.f;
	}

}

void ASpiderSpawneer::UpdatePlayerLocation(ASpiderAI* spider)
{
		if (!playerRef) return;
		if (spider->firePlace) return;
		FVector playerlocation = playerRef->GetActorLocation();
		spider->player = playerRef;
		spider->SetPlayerLocation(playerRef->GetActorLocation());
}

void ASpiderSpawneer::UpdateFirePlaceLocation(ASpiderAI* spider)
{
	if (!firePlace) return;
	FVector firePlaceLocation = firePlace->GetActorLocation();
	spider->firePlace = firePlace;
	spider->SetFirePlaceLocation(firePlace->GetActorLocation());
}

void ASpiderSpawneer::UpdateTowerLocation(ASpiderAI* spider)
{

		//spider->SetTowerLocation(playerRef->GetActorLocation());
		if (towers.Num() == 0) {
			return;
		}
		if (spider->targetTower && IsValid(spider->targetTower)) return;

		AActor* ClosestTower = nullptr;
		float MinDistance = FLT_MAX;

		for (AActor* Tower : towers)
		{
			if (!IsValid(Tower)) continue;

			float Distance = FVector::Dist(spider->GetPawn()->GetActorLocation(), Tower->GetActorLocation());

			if (Distance < MinDistance)
			{
				MinDistance = Distance;
				ClosestTower = Tower;
			}
		}
		if (IsValid(ClosestTower))
		{
			spider->SetTowerLocation(ClosestTower->GetActorLocation());
			spider->targetTower = ClosestTower;
		}
		else
		{
			spider->ClearTowersValue();
		}
	
}

void ASpiderSpawneer::SetCanSpawn(bool can)
{
	canSpawn = can;
}



