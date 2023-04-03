// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TimerHandler.generated.h"

/**
 * 
 */
UCLASS(config = Game)
class ELEMENTALBIRTHUE5_API UTimerHandler : public UObject
{
	GENERATED_BODY()
public:
	UTimerHandler();
	UTimerHandler(float _TimerMax);
	~UTimerHandler();

	UPROPERTY(VisibleAnywhere)
		float TimerCurrent = 0.f;

	UPROPERTY(VisibleAnywhere)
		float TimerMax = 0.f;

	UPROPERTY(VisibleAnywhere)
		bool IsTimerRunning = false;

	UPROPERTY(VisibleAnywhere)
		bool HasEndEventBeenCalled = false;

	void CalculateTimer(float _deltaTime);

	void LauncheTimer();
	void LauncheTimer(float _timerMax);

	float GetRealTime();
};
