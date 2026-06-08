// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Services/BTService_BlackboardBase.h"
#include "SpiderAI.h"
#include "BTService_FirePlaceLocation.generated.h"

/**
 * 
 */
UCLASS()
class PRIMALFORCE_API UBTService_FirePlaceLocation : public UBTService_BlackboardBase
{
	GENERATED_BODY()
public:
	UBTService_FirePlaceLocation();

	virtual void TickNode(UBehaviorTreeComponent& ownerComp, uint8* nodeMemory, float deltaSeconds) override;
};
