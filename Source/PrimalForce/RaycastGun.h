// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Gun.h"
#include "HealthComp.h"
#include "RaycastGun.generated.h"

/**
 * 
 */
UCLASS()
class PRIMALFORCE_API ARaycastGun : public AGun
{
	GENERATED_BODY()
public:
	ARaycastGun();

	UPROPERTY(EditAnywhere)
	float maxRange = 800.0f;
	UPROPERTY(EditAnywhere)
	float damage = 35.f;
	virtual void PullTrigger() override;

};
