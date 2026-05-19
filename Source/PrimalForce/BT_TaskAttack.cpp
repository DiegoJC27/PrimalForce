// Fill out your copyright notice in the Description page of Project Settings.


#include "BT_TaskAttack.h"

UBT_TaskAttack::UBT_TaskAttack()
{
}

EBTNodeResult::Type UBT_TaskAttack::ExecuteTask(UBehaviorTreeComponent& root, uint8* nodeMemory)
{
	Super::ExecuteTask(root, nodeMemory);

	ASpiderAI* controller = Cast<ASpiderAI>(root.GetAIOwner());
	//ASpiderEnemy* character = controller->GetMyCha

	return EBTNodeResult::Failed;
}
