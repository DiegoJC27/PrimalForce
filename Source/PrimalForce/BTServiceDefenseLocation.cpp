// Fill out your copyright notice in the Description page of Project Settings.


#include "BTServiceDefenseLocation.h"

UBTServiceDefenseLocation::UBTServiceDefenseLocation()
{
	NodeName = TEXT("Update Defense Location");
}

void UBTServiceDefenseLocation::TickNode(UBehaviorTreeComponent& ownerComp, uint8* nodeMemory, float deltaSeconds)
{
	Super::TickNode(ownerComp, nodeMemory, deltaSeconds);

	ASpiderAI* controller = Cast<ASpiderAI>(ownerComp.GetAIOwner());
	
	if (!controller) return;
	
	UBlackboardComponent* blackboard = controller->GetBlackboardComponent();
	if (!blackboard) return;

	
	blackboard->SetValueAsVector(GetSelectedBlackboardKey(),controller->TowerLocation);
}
