// Fill out your copyright notice in the Description page of Project Settings.


#include "BTServiceDefenseLocation.h"

UBTServiceDefenseLocation::UBTServiceDefenseLocation()
{
	NodeName = TEXT("Update Defense Location");
}

void UBTServiceDefenseLocation::TickNode(UBehaviorTreeComponent& ownerComp, uint8* nodeMemory, float deltaSeconds)
{
	Super::TickNode(ownerComp, nodeMemory, deltaSeconds);

	if(controller == nullptr) controller = Cast<ASpiderAI>(ownerComp.GetAIOwner());
	
	if (!controller) return;
	
	if(spider == nullptr) spider = controller->GetSpiderCharacter();
	if (!spider) return;

	UWorld* World = spider->GetWorld();
	if (!World) return;

	TArray<AActor*> Towers;
	UGameplayStatics::GetAllActorsOfClass(World,ATowerDefense::StaticClass(),Towers);

	if (Towers.Num() == 0) return;

	AActor* ClosestTower = nullptr;
	float MinDistance = FLT_MAX;

	for (AActor* Tower : Towers)
	{
		float Distance = FVector::Dist(spider->GetActorLocation(),Tower->GetActorLocation());

		if (Distance < MinDistance)
		{
			MinDistance = Distance;
			ClosestTower = Tower;
		}
	}
	if (ClosestTower)
	{
		ownerComp.GetBlackboardComponent()->SetValueAsVector("TowerLocation", ClosestTower->GetActorLocation());
	}
}
