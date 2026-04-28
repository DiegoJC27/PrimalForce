// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ActorPool.h"
#include "GameFramework/GameModeBase.h"
#include "PrimalForceGameMode.generated.h"

/**
 *  Simple GameMode for a third person game
 */
UCLASS(abstract)
class APrimalForceGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	
	/** Constructor */
	APrimalForceGameMode();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UActorPool* ActorPool_Proyectiles;

protected:
	virtual void BeginPlay() override;
};



