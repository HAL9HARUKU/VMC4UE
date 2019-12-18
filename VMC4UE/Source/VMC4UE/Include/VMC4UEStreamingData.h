// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UEOSC/Include/UEOscElement.h"
#include "VMC4UEStreamingData.generated.h"

/**
 * 
 */
struct VMC4UE_API FVMC4UEStreamingBoneTransform
{
public:
	FVMC4UEStreamingBoneTransform() {}
	~FVMC4UEStreamingBoneTransform() {}

	FVector Location = FVector::ZeroVector;
	FQuat Rotation = FQuat::Identity;
};

/**
 *
 */
UCLASS()
class VMC4UE_API UVMC4UEStreamingSkeletalMeshTransform : public UObject
{
	GENERATED_BODY()

public:
	FRWLock RWLock;
	float Time = 0.0f;
	FVMC4UEStreamingBoneTransform Root;
	TMap<FName, FVMC4UEStreamingBoneTransform> Bones;
	TMap<FName, float> CurrentBlendShapes;
	TMap<FName, float> FutureBlendShapes;

	UFUNCTION()
	void OnReceived(const FName &Address, const TArray<FUEOSCElement> &Data, const FString &SenderIp);
};
