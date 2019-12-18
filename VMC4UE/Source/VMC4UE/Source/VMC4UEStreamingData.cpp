// Fill out your copyright notice in the Description page of Project Settings.

#include "VMC4UE/Include/VMC4UEStreamingData.h"
#include "VMC4UE/Include/VMC4UEBlueprintFunctionLibrary.h"
#include "UEOSC/Include/UEOSCElement.h"

void UVMC4UEStreamingSkeletalMeshTransform::OnReceived(const FName &Address, const TArray<FUEOSCElement> &Data, const FString &SenderIp)
{
	UVMC4UEBlueprintFunctionLibrary::OnReceivedVMC(this, Address, Data, SenderIp);
}
