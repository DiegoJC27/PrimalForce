// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Services/BTService_BlackboardBase.h"
#include "Kismet/GameplayStatics.h"
#include "SpiderEnemy.h"
#include "SpiderAI.h"
#include "TowerDefense.h"
#include "BTServiceDefenseLocation.generated.h"

/**
 * 
 */
UCLASS()
class PRIMALFORCE_API UBTServiceDefenseLocation : public UBTService_BlackboardBase
{
	GENERATED_BODY()
	
public:
	UBTServiceDefenseLocation();

	virtual void TickNode(UBehaviorTreeComponent& ownerComp, uint8* nodeMemory, float deltaSeconds) override;

	UPROPERTY()
	ASpiderAI* controller;
	UPROPERTY()
	ASpiderEnemy* spider;
};
