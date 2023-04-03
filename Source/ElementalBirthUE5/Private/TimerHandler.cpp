// Fill out your copyright notice in the Description page of Project Settings.


#include "TimerHandler.h"
#include "..\Public\TimerHandler.h"

UTimerHandler::UTimerHandler()
{
}

UTimerHandler::UTimerHandler(float _timerMax)
{
	TimerMax = _timerMax;
}

UTimerHandler::~UTimerHandler()
{
}

void UTimerHandler::CalculateTimer(float _deltaTime)
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

void UTimerHandler::LauncheTimer()
{
	IsTimerRunning = true;
	TimerCurrent = 1.f;
}

void UTimerHandler::LauncheTimer(float _timerMax)
{
	IsTimerRunning = true;
	TimerMax = _timerMax;
	TimerCurrent = 1.f;
}

float UTimerHandler::GetRealTime()
{
	return TimerMax * TimerCurrent;
}
