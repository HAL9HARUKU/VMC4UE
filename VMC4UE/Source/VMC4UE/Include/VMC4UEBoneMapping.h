// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "VMC4UEBoneMapping.generated.h"

USTRUCT()
struct FVMC4UEBoneMappingText
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY()
	FName Hips = TEXT("");

	UPROPERTY()
	FName LeftUpperLeg = TEXT("");

	UPROPERTY()
	FName RightUpperLeg = TEXT("");

	UPROPERTY()
	FName LeftLowerLeg = TEXT("");

	UPROPERTY()
	FName RightLowerLeg = TEXT("");

	UPROPERTY()
	FName LeftFoot = TEXT("");

	UPROPERTY()
	FName RightFoot = TEXT("");

	UPROPERTY()
	FName Spine = TEXT("");

	UPROPERTY()
	FName Chest = TEXT("");

	UPROPERTY()
	FName Neck = TEXT("");

	UPROPERTY()
	FName Head = TEXT("");

	UPROPERTY()
	FName LeftShoulder = TEXT("");

	UPROPERTY()
	FName RightShoulder = TEXT("");

	UPROPERTY()
	FName LeftUpperArm = TEXT("");

	UPROPERTY()
	FName RightUpperArm = TEXT("");

	UPROPERTY()
	FName LeftLowerArm = TEXT("");

	UPROPERTY()
	FName RightLowerArm = TEXT("");

	UPROPERTY()
	FName LeftHand = TEXT("");

	UPROPERTY()
	FName RightHand = TEXT("");

	UPROPERTY()
	FName LeftToes = TEXT("");

	UPROPERTY()
	FName RightToes = TEXT("");

	UPROPERTY()
	FName LeftEye = TEXT("");

	UPROPERTY()
	FName RightEye = TEXT("");

	UPROPERTY()
	FName Jaw = TEXT("");

	UPROPERTY()
	FName LeftThumbProximal = TEXT("");

	UPROPERTY()
	FName LeftThumbIntermediate = TEXT("");

	UPROPERTY()
	FName LeftThumbDistal = TEXT("");

	UPROPERTY()
	FName LeftIndexProximal = TEXT("");

	UPROPERTY()
	FName LeftIndexIntermediate = TEXT("");

	UPROPERTY()
	FName LeftIndexDistal = TEXT("");

	UPROPERTY()
	FName LeftMiddleProximal = TEXT("");

	UPROPERTY()
	FName LeftMiddleIntermediate = TEXT("");

	UPROPERTY()
	FName LeftMiddleDistal = TEXT("");

	UPROPERTY()
	FName LeftRingProximal = TEXT("");

	UPROPERTY()
	FName LeftRingIntermediate = TEXT("");

	UPROPERTY()
	FName LeftRingDistal = TEXT("");

	UPROPERTY()
	FName LeftLittleProximal = TEXT("");

	UPROPERTY()
	FName LeftLittleIntermediate = TEXT("");

	UPROPERTY()
	FName LeftLittleDistal = TEXT("");

	UPROPERTY()
	FName RightThumbProximal = TEXT("");

	UPROPERTY()
	FName RightThumbIntermediate = TEXT("");

	UPROPERTY()
	FName RightThumbDistal = TEXT("");

	UPROPERTY()
	FName RightIndexProximal = TEXT("");

	UPROPERTY()
	FName RightIndexIntermediate = TEXT("");

	UPROPERTY()
	FName RightIndexDistal = TEXT("");

	UPROPERTY()
	FName RightMiddleProximal = TEXT("");

	UPROPERTY()
	FName RightMiddleIntermediate = TEXT("");

	UPROPERTY()
	FName RightMiddleDistal = TEXT("");

	UPROPERTY()
	FName RightRingProximal = TEXT("");

	UPROPERTY()
	FName RightRingIntermediate = TEXT("");

	UPROPERTY()
	FName RightRingDistal = TEXT("");

	UPROPERTY()
	FName RightLittleProximal = TEXT("");

	UPROPERTY()
	FName RightLittleIntermediate = TEXT("");

	UPROPERTY()
	FName RightLittleDistal = TEXT("");
};

/**
 *
 */
UCLASS()
class VMC4UE_API UVMC4UEBoneMapping : public UObject
{
    GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, Category = "Bone Mapping")
    FName Hips = TEXT("");

    UPROPERTY(EditAnywhere, Category = "Bone Mapping")
    FName LeftUpperLeg = TEXT("");

    UPROPERTY(EditAnywhere, Category = "Bone Mapping")
    FName RightUpperLeg = TEXT("");

    UPROPERTY(EditAnywhere, Category = "Bone Mapping")
    FName LeftLowerLeg = TEXT("");

    UPROPERTY(EditAnywhere, Category = "Bone Mapping")
    FName RightLowerLeg = TEXT("");

    UPROPERTY(EditAnywhere, Category = "Bone Mapping")
    FName LeftFoot = TEXT("");

    UPROPERTY(EditAnywhere, Category = "Bone Mapping")
    FName RightFoot = TEXT("");

    UPROPERTY(EditAnywhere, Category = "Bone Mapping")
    FName Spine = TEXT("");

    UPROPERTY(EditAnywhere, Category = "Bone Mapping")
    FName Chest = TEXT("");

    UPROPERTY(EditAnywhere, Category = "Bone Mapping")
    FName Neck = TEXT("");

    UPROPERTY(EditAnywhere, Category = "Bone Mapping")
    FName Head = TEXT("");

    UPROPERTY(EditAnywhere, Category = "Bone Mapping")
    FName LeftShoulder = TEXT("");

    UPROPERTY(EditAnywhere, Category = "Bone Mapping")
    FName RightShoulder = TEXT("");

    UPROPERTY(EditAnywhere, Category = "Bone Mapping")
    FName LeftUpperArm = TEXT("");

    UPROPERTY(EditAnywhere, Category = "Bone Mapping")
    FName RightUpperArm = TEXT("");

    UPROPERTY(EditAnywhere, Category = "Bone Mapping")
    FName LeftLowerArm = TEXT("");

    UPROPERTY(EditAnywhere, Category = "Bone Mapping")
    FName RightLowerArm = TEXT("");

    UPROPERTY(EditAnywhere, Category = "Bone Mapping")
    FName LeftHand = TEXT("");

    UPROPERTY(EditAnywhere, Category = "Bone Mapping")
    FName RightHand = TEXT("");

    UPROPERTY(EditAnywhere, Category = "Bone Mapping")
    FName LeftToes = TEXT("");

    UPROPERTY(EditAnywhere, Category = "Bone Mapping")
    FName RightToes = TEXT("");

    UPROPERTY(EditAnywhere, Category = "Bone Mapping")
    FName LeftEye = TEXT("");

    UPROPERTY(EditAnywhere, Category = "Bone Mapping")
    FName RightEye = TEXT("");

    UPROPERTY(EditAnywhere, Category = "Bone Mapping")
    FName Jaw = TEXT("");

    UPROPERTY(EditAnywhere, Category = "Bone Mapping")
    FName LeftThumbProximal = TEXT("");

    UPROPERTY(EditAnywhere, Category = "Bone Mapping")
    FName LeftThumbIntermediate = TEXT("");

    UPROPERTY(EditAnywhere, Category = "Bone Mapping")
    FName LeftThumbDistal = TEXT("");

    UPROPERTY(EditAnywhere, Category = "Bone Mapping")
    FName LeftIndexProximal = TEXT("");

    UPROPERTY(EditAnywhere, Category = "Bone Mapping")
    FName LeftIndexIntermediate = TEXT("");

    UPROPERTY(EditAnywhere, Category = "Bone Mapping")
    FName LeftIndexDistal = TEXT("");

    UPROPERTY(EditAnywhere, Category = "Bone Mapping")
    FName LeftMiddleProximal = TEXT("");

    UPROPERTY(EditAnywhere, Category = "Bone Mapping")
    FName LeftMiddleIntermediate = TEXT("");

    UPROPERTY(EditAnywhere, Category = "Bone Mapping")
    FName LeftMiddleDistal = TEXT("");

    UPROPERTY(EditAnywhere, Category = "Bone Mapping")
    FName LeftRingProximal = TEXT("");

    UPROPERTY(EditAnywhere, Category = "Bone Mapping")
    FName LeftRingIntermediate = TEXT("");

    UPROPERTY(EditAnywhere, Category = "Bone Mapping")
    FName LeftRingDistal = TEXT("");

    UPROPERTY(EditAnywhere, Category = "Bone Mapping")
    FName LeftLittleProximal = TEXT("");

    UPROPERTY(EditAnywhere, Category = "Bone Mapping")
    FName LeftLittleIntermediate = TEXT("");

    UPROPERTY(EditAnywhere, Category = "Bone Mapping")
    FName LeftLittleDistal = TEXT("");

    UPROPERTY(EditAnywhere, Category = "Bone Mapping")
    FName RightThumbProximal = TEXT("");

    UPROPERTY(EditAnywhere, Category = "Bone Mapping")
    FName RightThumbIntermediate = TEXT("");

    UPROPERTY(EditAnywhere, Category = "Bone Mapping")
    FName RightThumbDistal = TEXT("");

    UPROPERTY(EditAnywhere, Category = "Bone Mapping")
    FName RightIndexProximal = TEXT("");

    UPROPERTY(EditAnywhere, Category = "Bone Mapping")
    FName RightIndexIntermediate = TEXT("");

    UPROPERTY(EditAnywhere, Category = "Bone Mapping")
    FName RightIndexDistal = TEXT("");

    UPROPERTY(EditAnywhere, Category = "Bone Mapping")
    FName RightMiddleProximal = TEXT("");

    UPROPERTY(EditAnywhere, Category = "Bone Mapping")
    FName RightMiddleIntermediate = TEXT("");

    UPROPERTY(EditAnywhere, Category = "Bone Mapping")
    FName RightMiddleDistal = TEXT("");

    UPROPERTY(EditAnywhere, Category = "Bone Mapping")
    FName RightRingProximal = TEXT("");

    UPROPERTY(EditAnywhere, Category = "Bone Mapping")
    FName RightRingIntermediate = TEXT("");

    UPROPERTY(EditAnywhere, Category = "Bone Mapping")
    FName RightRingDistal = TEXT("");

    UPROPERTY(EditAnywhere, Category = "Bone Mapping")
    FName RightLittleProximal = TEXT("");

    UPROPERTY(EditAnywhere, Category = "Bone Mapping")
    FName RightLittleIntermediate = TEXT("");

    UPROPERTY(EditAnywhere, Category = "Bone Mapping")
    FName RightLittleDistal = TEXT("");
};
