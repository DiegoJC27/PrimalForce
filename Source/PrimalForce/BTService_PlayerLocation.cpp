// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_PlayerLocation.h"

UBTService_PlayerLocation::UBTService_PlayerLocation()
{
	NodeName = TEXT("Update Player Location");
}

void UBTService_PlayerLocation::TickNode(UBehaviorTreeComponent& ownerComp, uint8* nodeMemory, float deltaSeconds)
{
	Super::TickNode(ownerComp, nodeMemory, deltaSeconds);

	ASpiderAI* controller = Cast<ASpiderAI>(ownerComp.GetAIOwner());
	if (!controller) return;

	APrimalForceCharacter* player = controller->GetPlayerCharacter();
	if (!player) return;

	UBlackboardComponent* blackboard = controller->GetBlackboardComponent();
	if (!blackboard) return;
	
	float distance = FVector::Dist(controller->GetPawn()->GetActorLocation(), player->GetActorLocation());

	if (distance <= controller->detectionDistance) {
		controller->SetFocus(player);
		blackboard->SetValueAsVector(GetSelectedBlackboardKey(), player->GetActorLocation());
	}
	else {
		controller->ClearFocus(EAIFocusPriority::Gameplay);
		blackboard->ClearValue(GetSelectedBlackboardKey());
	}
}
