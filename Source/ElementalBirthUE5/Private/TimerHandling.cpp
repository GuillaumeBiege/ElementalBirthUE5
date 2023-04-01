// Fill out your copyright notice in the Description page of Project Settings.


#include "TimerHandling.h"

void UTimerHandling::CalculateTimer(float _deltaTime)
{
	TimerCurrent -= _deltaTime / TimerMax;

	if (HasEndEventBeenCalled)
		HasEndEventBeenCalled = false;

	if (TimerCurrent <= 0.f && IsTimerRunning)
	{
		TimerCurrent = 0.f;
		HasEndEventBeenCalled = true;
	}

}

void UTimerHandling::LauncheTimer()
{
	TimerCurrent = 1.f;
}

void UTimerHandling::LauncheTimer(float _timerMax)
{
	TimerMax = _timerMax;
	TimerCurrent = 1.f;
}

float UTimerHandling::GetRealTime()
{
	return TimerMax * TimerCurrent;
}
