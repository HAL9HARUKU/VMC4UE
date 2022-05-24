// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "Engine/GameInstance.h"
#include "VMC4UEOscManager.generated.h"

class UVMC4UEStreamingSkeletalMeshTransform;
class UUEOSCReceiver;

/**
 * 
 */
UCLASS(BlueprintType)
class VMC4UE_API UVMC4UEOSCManager : public UObject
{
	GENERATED_BODY()
	
public:
    FRWLock RWLock;

	UPROPERTY()
    TMap<int32, UVMC4UEStreamingSkeletalMeshTransform*> StreamingSkeletalMeshTransformMap;

	UPROPERTY()
	TArray<UUEOSCReceiver*> OscReceivers;

	static UVMC4UEOSCManager* GetInstance();

private:
	static UVMC4UEOSCManager* Instance;
};
