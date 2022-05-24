// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "Animation/AnimNodeBase.h"
#include "AnimNode_ModifyVMC4UEMorph.generated.h"

class UVMC4UEStreamingSkeletalMeshTransform;
class UVMC4UEVRMMapping;

UENUM()
enum class EMVC4UEModifyCurveApplyMode : uint8
{
    /** Add new value to input curve value */
    Add,

    /** Scale input value by new value */
    Scale,

    /** Blend input with new curve value, using Alpha setting on the node */
    Blend,

    /** Blend the new curve value with the last curve value using Alpha to determine the weighting (.5 is a moving average, higher values react to new values faster, lower slower) */
    WeightedMovingAverage,

    /** Remaps the new curve value between the CurveValues entry and 1.0 (.5 in CurveValues makes 0.51 map to 0.02) */
    RemapCurve
};

/** Easy way to modify curve values on a pose */
USTRUCT(BlueprintInternalUseOnly)
struct VMC4UE_API FAnimNode_ModifyVMC4UEMorph : public FAnimNode_Base
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, EditFixedSize, BlueprintReadWrite, Category = Links)
    FPoseLink SourcePose;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = ModifyCurve, meta = (PinShownByDefault))
    UVMC4UEVRMMapping* VRMMapping;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ModifyCurve, meta = (PinShownByDefault))
	int32 Port;

	FAnimNode_ModifyVMC4UEMorph() {}
	FAnimNode_ModifyVMC4UEMorph(const class FObjectInitializer &ObjectInitializer) {}

    // FAnimNode_Base interface
    virtual void Initialize_AnyThread(const FAnimationInitializeContext &Context) override;
    virtual void CacheBones_AnyThread(const FAnimationCacheBonesContext &Context) override;
    virtual void Evaluate_AnyThread(FPoseContext &Output) override;
    virtual void Update_AnyThread(const FAnimationUpdateContext &Context) override;
    // End of FAnimNode_Base interface

#if WITH_EDITOR
    /** Add new curve being modified */
    void AddCurve(const FName &InName, float InValue);
    /** Remove a curve from being modified */
    void RemoveCurve(int32 PoseIndex);
#endif // WITH_EDITOR

private:
	void BuildMapping();
	
	bool bIsInitialized;
	TMap<FName, float> MorphStates;

    UVMC4UEVRMMapping* PrevVRMMapping;
};
