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
	if (!controller || !controller->GetPawn() || !controller->player) return;

	UBlackboardComponent* blackboard = controller->GetBlackboardComponent();
	if (!blackboard) return;

	FVector currentPlayerLoc = controller->player->GetActorLocation();
	float distance = FVector::Dist(controller->GetPawn()->GetActorLocation(), currentPlayerLoc);

	if (distance <= controller->detectionDistance) {
		controller->SetFocus(controller->player);
		blackboard->SetValueAsVector(GetSelectedBlackboardKey(), currentPlayerLoc);
	}
	else {
		controller->ClearFocus(EAIFocusPriority::Gameplay);
		blackboard->ClearValue(GetSelectedBlackboardKey()); // Ahora sí se mantendrá limpio
	}
}
