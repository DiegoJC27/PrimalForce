// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ActorPool.h"
#include "IPooled.h"
#include "GameFramework/Actor.h"
#include "SpiderSpawneer.generated.h"

UCLASS()
class PRIMALFORCE_API ASpiderSpawneer : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpiderSpawneer();
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UActorPool* ActorPool_Spider;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<AActor*> SpawnPoints;

	UFUNCTION(BlueprintCallable)
	void SpawnSpider();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
