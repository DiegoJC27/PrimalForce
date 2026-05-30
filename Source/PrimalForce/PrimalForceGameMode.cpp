// Copyright Epic Games, Inc. All Rights Reserved.

#include "PrimalForceGameMode.h"

APrimalForceGameMode::APrimalForceGameMode()
{
	ActorPool_Proyectiles = CreateDefaultSubobject<UActorPool>(TEXT("PoolRocas"));
	ActorPool_Proyectiles->RegisterComponent();
	
	ActorPool_Decals = CreateDefaultSubobject<UActorPool>(TEXT("PoolDecals"));
	ActorPool_Decals->RegisterComponent();
}

void APrimalForceGameMode::BeginPlay()
{
	Super::BeginPlay();
	if (ActorPool_Proyectiles != nullptr) {
		UE_LOG(LogTemp, Warning, TEXT("No es nulo"));
		ActorPool_Proyectiles->ForceInitialize();
	}
	if (ActorPool_Decals != nullptr) {
		UE_LOG(LogTemp, Warning, TEXT("No es nulo"));
		ActorPool_Decals->ForceInitialize();
	}


}
