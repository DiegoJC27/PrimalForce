// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "SpiderAI.h"
#include "BT_TaskAttack.generated.h"

/**
 * 
 */
UCLASS()
class PRIMALFORCE_API UBT_TaskAttack : public UBTTaskNode
{
	GENERATED_BODY()

public:

	UBT_TaskAttack();

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& root, uint8* nodeMemory) override;
};
