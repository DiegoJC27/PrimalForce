// Fill out your copyright notice in the Description page of Project Settings.


#include "RaycastGun.h"

ARaycastGun::ARaycastGun()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	//PrimaryActorTick.bCanEverTick = true;

	/*rootComp = CreateDefaultSubobject<USceneComponent>(TEXT("Scene Root"));
	SetRootComponent(rootComp);

	skMeshComp = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh"));
	skMeshComp->SetupAttachment(rootComp);*/
}

void ARaycastGun::PullTrigger()
{
	//Super::PullTrigger();
	if (ownerController) {
		FVector viewPointLocation;
		FRotator viewPointRotation;
		ownerController->GetPlayerViewPoint(viewPointLocation, viewPointRotation);

		DrawDebugCamera(GetWorld(), viewPointLocation, viewPointRotation, 90, 2, FColor::Red, true);

		FVector endPoint = viewPointLocation + (viewPointRotation.Vector() * maxRange);

		FHitResult hit;
		FCollisionQueryParams params;
		params.AddIgnoredActor(GetOwner());
		params.AddIgnoredActor(this);

		bool isHit = GetWorld()->LineTraceSingleByChannel(hit, viewPointLocation, endPoint, ECC_GameTraceChannel2, params);
		if (isHit) {
			DrawDebugSphere(GetWorld(), hit.ImpactPoint, 10, 8, FColor::Blue, true);
		}
	}
}
