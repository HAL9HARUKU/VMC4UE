#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "BoneContainer.h"
#include "BonePose.h"
#include "BoneControllers/AnimNode_SkeletalControlBase.h"
#include "AnimNode_VMC4UE.generated.h"

class USkeletalMeshComponent;
class UVMC4UEVRMMapping;
class UVMC4UEStreamingSkeletalMeshTransform;

/**
 *
 */
USTRUCT(BlueprintInternalUseOnly)
struct VMC4UE_API FAnimNode_VMC4UE : public FAnimNode_SkeletalControlBase
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Alpha, meta = (PinShownByDefault))
	TWeakObjectPtr<UVMC4UEVRMMapping> VRMMapping;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Alpha, meta = (PinShownByDefault))
	TWeakObjectPtr<UVMC4UEStreamingSkeletalMeshTransform> StreamingSkeletalMeshTransform;

	FAnimNode_VMC4UE() {}
	FAnimNode_VMC4UE(const class FObjectInitializer &ObjectInitializer) {}

    virtual void Initialize_AnyThread(const FAnimationInitializeContext &Context) override;

    // FAnimNode_Base interface
    virtual void GatherDebugData(FNodeDebugData &DebugData) override;
    virtual void Evaluate(FPoseContext &Output) {}
    // End of FAnimNode_Base interface

    // FAnimNode_SkeletalControlBase interface
    virtual void EvaluateSkeletalControl_AnyThread(FComponentSpacePoseContext &Output, TArray<FBoneTransform> &OutBoneTransforms) override;
    virtual bool IsValidToEvaluate(const USkeleton *Skeleton, const FBoneContainer &RequiredBones) override;
    // End of FAnimNode_SkeletalControlBase interface

private:
    // FAnimNode_SkeletalControlBase interface
    virtual void InitializeBoneReferences(const FBoneContainer &RequiredBones) override;
    // End of FAnimNode_SkeletalControlBase interface

private:
	TMap<FName, FName> BoneMappingSkeletonToVMC;
	TArray<FTransform> InitialBones;
	TArray<FBoneReference> BoneReferences;
};
