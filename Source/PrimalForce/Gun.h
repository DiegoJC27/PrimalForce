// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "IPooled.h"
#include "GameFramework/Actor.h"
#include "Gun.generated.h"

UCLASS()
class PRIMALFORCE_API AGun : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGun();
	UPROPERTY(VisibleAnywhere)
	USceneComponent* rootComp;

	UPROPERTY(VisibleAnywhere)
	USkeletalMeshComponent* skMeshComp;

	AController* ownerController;

	UFUNCTION(BlueprintCallable)
	virtual void PullTrigger();
	UPROPERTY(VisibleAnywhere)
	USceneComponent* muzzle;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//void SetUp();
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
