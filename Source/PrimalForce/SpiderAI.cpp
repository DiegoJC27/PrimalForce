// Fill out your copyright notice in the Description page of Project Settings.


#include "SpiderAI.h"

void ASpiderAI::BeginPlay()
{
	Super::BeginPlay();
	//player = Cast<APrimalForceCharacter>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
	//StartBehaiviourTree(player);
}

void ASpiderAI::Tick(float deltaSeconds)
{
	Super::Tick(deltaSeconds);
	
}


void ASpiderAI::StartBehaiviourTree(APrimalForceCharacter* character)
{
	UE_LOG(LogTemp, Warning, TEXT("Entra behaivour"));
	if (enemyTree) {
		spider = Cast<ASpiderEnemy>(GetPawn());
		player = character;

		if (!player) return;
		RunBehaviorTree(enemyTree);
			UBlackboardComponent* blackboardComp = GetBlackboardComponent();
				if (blackboardComp) {
					GetBlackboardComponent()->SetValueAsVector("StartLocation", spider->GetActorLocation());
					UE_LOG(LogTemp, Warning, TEXT("Inicio de behaivoir Tree"));
				}
		
	}
}

void ASpiderAI::SetPlayerLocation(const FVector& playerPos)
{
	PlayerLocation = playerPos;

	if (UBlackboardComponent* BB = GetBlackboardComponent())
	{
		BB->SetValueAsVector("PlayerLocation", PlayerLocation);
	}
}

void ASpiderAI::SetTowerLocation(const FVector& towerPos)
{
	TowerLocation = towerPos;

	if (UBlackboardComponent* BB = GetBlackboardComponent()) {
		BB->SetValueAsVector("TowerLocation", TowerLocation);
	}
}

void ASpiderAI::SetFirePlaceLocation(const FVector& firePos)
{
	FirePlaceLocation = firePos;

	if (UBlackboardComponent* BB = GetBlackboardComponent()) {
		BB->SetValueAsVector("FirePlaceLocation", FirePlaceLocation);
	}
}

void ASpiderAI::ClearTowersValue()
{
	if (UBlackboardComponent* BB = GetBlackboardComponent())
	{
		BB->ClearValue("TowerLocation");
	}
}

void ASpiderAI::ActivateBrain()
{
	if (enemyTree)
	{
		RunBehaviorTree(enemyTree);

		if (UBlackboardComponent* BB = GetBlackboardComponent())
		{
			BB->SetValueAsVector("PlayerLocation", PlayerLocation);
			BB->SetValueAsVector("TowerLocation", TowerLocation);
			BB->SetValueAsVector("FirePlaceLocation", FirePlaceLocation);
		}
	}
}

void ASpiderAI::DeactivateBrain()
{
	if (UBrainComponent* brain = GetBrainComponent())
	{
		brain->StopLogic(TEXT("Pooled"));
	}
}