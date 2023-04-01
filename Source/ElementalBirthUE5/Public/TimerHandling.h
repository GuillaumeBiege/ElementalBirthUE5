// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "TimerHandling.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class ELEMENTALBIRTHUE5_API UTimerHandling : public UObject
{
	GENERATED_BODY()
	
public:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		float TimerCurrent = 0.f;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
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
