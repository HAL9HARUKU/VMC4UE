// Fill out your copyright notice in the Description page of Project Settings.

#include "VMC4UE/Include/VMC4UEOscManager.h"
#include "Engine/Engine.h"
#include "Kismet/GameplayStatics.h"

UVMC4UEOSCManager* UVMC4UEOSCManager::Instance = nullptr;

UVMC4UEOSCManager* UVMC4UEOSCManager::GetInstance()
{
	if (!IsValid(Instance))
	{
		Instance = NewObject< UVMC4UEOSCManager >();
		check(Instance)
		Instance->AddToRoot();
	}
	return Instance;
}
