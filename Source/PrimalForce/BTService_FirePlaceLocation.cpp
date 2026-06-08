// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_FirePlaceLocation.h"

UBTService_FirePlaceLocation::UBTService_FirePlaceLocation()
{
	NodeName = TEXT("Update FirePlace Location");
}

void UBTService_FirePlaceLocation::TickNode(UBehaviorTreeComponent& ownerComp, uint8* nodeMemory, float deltaSeconds)
{
	Super::TickNode(ownerComp, nodeMemory, deltaSeconds);

	ASpiderAI* controller = Cast<ASpiderAI>(ownerComp.GetAIOwner());

	if (!controller) return;

	UBlackboardComponent* blackboard = controller->GetBlackboardComponent();
	if (!blackboard) return;


	blackboard->SetValueAsVector(GetSelectedBlackboardKey(), controller->FirePlaceLocation);
}
