// Fill out your copyright notice in the Description page of Project Settings.


#include "BulletGun.h"

void ABulletGun::PullTrigger()
{
	UE_LOG(LogTemp, Display, TEXT("Se llama PullTrigger"));
	AActor* rock = myRockPool->GetActorFromPool();
	rock->SetActorLocation(muzzle->GetComponentLocation());
	if (rock->Implements<UIPooled>()) {
		IIPooled::Execute_OnSpawn(rock, GetOwner());
		IIPooled::Execute_LifeTime(rock, 5.0f);
	}
}

void ABulletGun::BeginPlay()
{
	Super::BeginPlay();
	APrimalForceGameMode* gameMode = Cast<APrimalForceGameMode>(GetWorld()->GetAuthGameMode());
	if (gameMode == nullptr) {
		return;
	}
	myRockPool = gameMode->ActorPool_Proyectiles;
}
