// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Kismet/GameplayStatics.h"
#include "SpiderEnemy.h"
#include "PrimalForceCharacter.h"
#include "BehaviorTree/blackboardComponent.h"
#include "SpiderAI.generated.h"

/**
 * 
 */
UCLASS()
class PRIMALFORCE_API ASpiderAI : public AAIController
{
	GENERATED_BODY()
	
protected:

	ASpiderEnemy* spider;

	APrimalForceCharacter* player;

	UPROPERTY(EditAnywhere)
	UBehaviorTree* enemyTree;

	virtual void BeginPlay() override;

	virtual void Tick(float deltaSeconds) override;


public:
	UPROPERTY(EditAnywhere)
	float detectionDistance;
	void StartBehaiviourTree(APrimalForceCharacter* character);
	APrimalForceCharacter* GetPlayerCharacter() const { return player; };
	ASpiderEnemy* GetSpiderCharacter() const { return spider; };
};
