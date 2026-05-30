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
	if (enemyTree) {
		spider = Cast<ASpiderEnemy>(GetPawn());
		player = character;

		if (!player) return;
		RunBehaviorTree(enemyTree);
		if (character || player) {
			UBlackboardComponent* blackboardComp = GetBlackboardComponent();
				if (blackboardComp) {
					GetBlackboardComponent()->SetValueAsVector("StartLocation", character->GetActorLocation());
					GetBlackboardComponent()->SetValueAsVector("PlayerLocation", player->GetActorLocation());
				}
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

void ASpiderAI::ActivateBrain()
{
	if (enemyTree)
	{
		RunBehaviorTree(enemyTree);

		if (UBlackboardComponent* BB = GetBlackboardComponent())
		{
			BB->SetValueAsVector("PlayerLocation", PlayerLocation);
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