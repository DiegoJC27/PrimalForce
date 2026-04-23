// Fill out your copyright notice in the Description page of Project Settings.


#include "ActorUtilities.h"

void UActorUtilities::ToggleActorHidden(AActor* actor, bool isHidden)
{
	if (actor == nullptr) { return; }

	actor->SetActorHiddenInGame(isHidden);
	actor->SetActorTickEnabled(!isHidden);
	actor->SetActorEnableCollision(!isHidden);
}
