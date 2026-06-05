// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ActorPool.h"
#include "IPooled.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BrainComponent.h"
#include "SpiderAI.h"
#include "TowerDefense.h"
#include "Kismet/GameplayStatics.h"
#include "PrimalForceCharacter.h"
#include "GameFramework/Actor.h"
#include "SpiderSpawneer.generated.h"

UCLASS()
class PRIMALFORCE_API ASpiderSpawneer : public AActor
{
	GENERATED_BODY()
	
public:	
	UPROPERTY(VisibleAnywhere)
	ASpiderAI* currentAISPIDER;
	ASpiderSpawneer();
	UPROPERTY(VisibleAnywhere)
	UActorPool* ActorPool_Spider;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<AActor*> SpawnPoints;
	TSubclassOf<ASpiderAI*> spiderAIBlueprint;
	UFUNCTION(BlueprintCallable)
	void SpawnSpider();
	UFUNCTION(BlueprintCallable)
	void DisableSpiderIA(AActor* spider);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	APrimalForceCharacter* playerRef;

	UPROPERTY(VisibleAnywhere)
	TArray<AActor*> towers;
protected:
	virtual void BeginPlay() override;
	UPROPERTY()
	TArray<ASpiderAI*> ActiveSpiders;

public:	
	virtual void Tick(float DeltaTime) override;
	UFUNCTION()
	void UpdatePlayerLocation(ASpiderAI* spider);
	void UpdateTowerLocation(ASpiderAI* spider);
};
