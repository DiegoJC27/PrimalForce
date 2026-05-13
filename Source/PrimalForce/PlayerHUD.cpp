// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerHUD.h"

void UPlayerHUD::SetHealthPercent(float value)
{
	if (value > 0.0f && value < 1.0f) {
		HealthBar->SetPercent(value);
	}
}
