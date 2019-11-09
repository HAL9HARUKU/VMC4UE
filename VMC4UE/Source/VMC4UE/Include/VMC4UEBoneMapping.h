// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "VMC4UEBoneMapping.generated.h"

/**
 *
 */
UCLASS()
class VMC4UE_API UVMC4UEBoneMapping : public UObject
{
    GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Bone Mapping")
    FName Hips = TEXT("");

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Bone Mapping")
    FName LeftUpperLeg = TEXT("");

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Bone Mapping")
    FName RightUpperLeg = TEXT("");

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Bone Mapping")
    FName LeftLowerLeg = TEXT("");

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Bone Mapping")
    FName RightLowerLeg = TEXT("");

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Bone Mapping")
    FName LeftFoot = TEXT("");

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Bone Mapping")
    FName RightFoot = TEXT("");

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Bone Mapping")
    FName Spine = TEXT("");

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Bone Mapping")
    FName Chest = TEXT("");

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Bone Mapping")
    FName Neck = TEXT("");

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Bone Mapping")
    FName Head = TEXT("");

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Bone Mapping")
    FName LeftShoulder = TEXT("");

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Bone Mapping")
    FName RightShoulder = TEXT("");

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Bone Mapping")
    FName LeftUpperArm = TEXT("");

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Bone Mapping")
    FName RightUpperArm = TEXT("");

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Bone Mapping")
    FName LeftLowerArm = TEXT("");

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Bone Mapping")
    FName RightLowerArm = TEXT("");

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Bone Mapping")
    FName LeftHand = TEXT("");

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Bone Mapping")
    FName RightHand = TEXT("");

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Bone Mapping")
    FName LeftToes = TEXT("");

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Bone Mapping")
    FName RightToes = TEXT("");

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Bone Mapping")
    FName LeftEye = TEXT("");

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Bone Mapping")
    FName RightEye = TEXT("");

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Bone Mapping")
    FName Jaw = TEXT("");

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Bone Mapping")
    FName LeftThumbProximal = TEXT("");

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Bone Mapping")
    FName LeftThumbIntermediate = TEXT("");

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Bone Mapping")
    FName LeftThumbDistal = TEXT("");

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Bone Mapping")
    FName LeftIndexProximal = TEXT("");

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Bone Mapping")
    FName LeftIndexIntermediate = TEXT("");

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Bone Mapping")
    FName LeftIndexDistal = TEXT("");

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Bone Mapping")
    FName LeftMiddleProximal = TEXT("");

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Bone Mapping")
    FName LeftMiddleIntermediate = TEXT("");

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Bone Mapping")
    FName LeftMiddleDistal = TEXT("");

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Bone Mapping")
    FName LeftRingProximal = TEXT("");

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Bone Mapping")
    FName LeftRingIntermediate = TEXT("");

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Bone Mapping")
    FName LeftRingDistal = TEXT("");

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Bone Mapping")
    FName LeftLittleProximal = TEXT("");

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Bone Mapping")
    FName LeftLittleIntermediate = TEXT("");

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Bone Mapping")
    FName LeftLittleDistal = TEXT("");

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Bone Mapping")
    FName RightThumbProximal = TEXT("");

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Bone Mapping")
    FName RightThumbIntermediate = TEXT("");

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Bone Mapping")
    FName RightThumbDistal = TEXT("");

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Bone Mapping")
    FName RightIndexProximal = TEXT("");

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Bone Mapping")
    FName RightIndexIntermediate = TEXT("");

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Bone Mapping")
    FName RightIndexDistal = TEXT("");

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Bone Mapping")
    FName RightMiddleProximal = TEXT("");

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Bone Mapping")
    FName RightMiddleIntermediate = TEXT("");

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Bone Mapping")
    FName RightMiddleDistal = TEXT("");

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Bone Mapping")
    FName RightRingProximal = TEXT("");

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Bone Mapping")
    FName RightRingIntermediate = TEXT("");

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Bone Mapping")
    FName RightRingDistal = TEXT("");

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Bone Mapping")
    FName RightLittleProximal = TEXT("");

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Bone Mapping")
    FName RightLittleIntermediate = TEXT("");

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Bone Mapping")
    FName RightLittleDistal = TEXT("");
};
