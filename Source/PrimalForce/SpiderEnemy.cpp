// Fill out your copyright notice in the Description page of Project Settings.


#include "SpiderEnemy.h"

// Sets default values
ASpiderEnemy::ASpiderEnemy()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	health = maxHealth;
}

// Called when the game starts or when spawned
void ASpiderEnemy::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASpiderEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASpiderEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ASpiderEnemy::Attack() {
	if (!isAlive) return;
	if (!attackMontage) return;

	UAnimInstance* animInstance = GetMesh()->GetAnimInstance();
	if (!animInstance) return;

	if (animInstance->Montage_IsPlaying(attackMontage)) return;

	animInstance->Montage_Play(attackMontage);

}

void ASpiderEnemy::RecieveDamage()
{
	if (!isAlive) return;
	if (!recievingDamageMontage) return;

	UAnimInstance* animInstance = GetMesh()->GetAnimInstance();
	if (!animInstance) return;

	if (animInstance->Montage_IsPlaying(recievingDamageMontage)) return;

	animInstance->Montage_Play(recievingDamageMontage);
}
