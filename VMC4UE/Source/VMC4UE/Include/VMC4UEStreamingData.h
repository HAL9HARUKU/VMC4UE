// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
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

UCLASS(BlueprintType)
class VMC4UE_API UVMC4UEStreamingSkeletalMeshTransform : public UObject
{
	GENERATED_BODY()

public:
	FVMC4UEStreamingBoneTransform Root;
	TMap<FName, FVMC4UEStreamingBoneTransform> Bones;
};
