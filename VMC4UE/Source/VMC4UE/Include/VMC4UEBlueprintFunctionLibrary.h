// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "UEOSC/Include/UEOSCElement.h"
#include "VMC4UEBlueprintFunctionLibrary.generated.h"

class UVMC4UEStreamingSkeletalMeshTransform;

/**
 * 
 */
UCLASS(Blueprintable)
class VMC4UE_API UVMC4UEBlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:
    static void OnReceivedVMC(UVMC4UEStreamingSkeletalMeshTransform *SkeletalMeshTransform, const FName &Address, const TArray<FUEOSCElement> &Data, const FString &SenderIp);
	static UVMC4UEStreamingSkeletalMeshTransform* GetStreamingSkeletalMeshTransform(int32 Port);
    
    UFUNCTION(BlueprintCallable, Category = "VMC4UE")
    static void RefreshConnection(float Seconds);
};
