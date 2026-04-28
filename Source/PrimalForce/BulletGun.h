// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ActorPool.h"
#include "PrimalForceGameMode.h"
#include "Gun.h"
#include "BulletGun.generated.h"

/**
 * 
 */
UCLASS()
class PRIMALFORCE_API ABulletGun : public AGun
{
	GENERATED_BODY()
public:

	virtual void PullTrigger() override;
	
	UPROPERTY(VisibleAnywhere)
	UActorPool* myRockPool;

protected:
	virtual void BeginPlay() override;
};
