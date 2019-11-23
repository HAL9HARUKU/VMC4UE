// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Receive/OscReceiverComponent.h"
#include "VMC4UEBlueprintFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class VMC4UE_API UVMC4UEBlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category = "VMC4UE")
    static void OnReceivedVMC(UVMC4UEStreamingSkeletalMeshTransform *SkeletalMeshTransform, const FName &Address, const TArray<FOscDataElemStruct> &Data, const FString &SenderIp);

	UFUNCTION(BlueprintCallable, Category = "VMC4UE")
	static void CreateObject(UClass *ObjectClass, UObject* &CreatedObject);
};
