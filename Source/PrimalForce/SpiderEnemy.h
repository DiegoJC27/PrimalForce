// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SpiderEnemy.generated.h"

UCLASS()
class PRIMALFORCE_API ASpiderEnemy : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ASpiderEnemy();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float health;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float damage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float maxHealth = 100;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool isAlive = true;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	UAnimMontage* attackMontage;
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	UAnimMontage* recievingDamageMontage;

	void Attack();
	UFUNCTION(BlueprintCallable)
	void RecieveDamage();
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
