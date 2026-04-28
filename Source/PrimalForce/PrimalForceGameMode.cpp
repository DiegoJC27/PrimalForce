// Copyright Epic Games, Inc. All Rights Reserved.

#include "PrimalForceGameMode.h"

APrimalForceGameMode::APrimalForceGameMode()
{
	ActorPool_Proyectiles = CreateDefaultSubobject<UActorPool>(TEXT("PoolRocas"));
	ActorPool_Proyectiles->RegisterComponent();
}

void APrimalForceGameMode::BeginPlay()
{
	if (ActorPool_Proyectiles != nullptr) {
		UE_LOG(LogTemp, Warning, TEXT("No es nulo"));
		ActorPool_Proyectiles->ForceInitialize();
	}


}
