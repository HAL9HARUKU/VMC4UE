#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "BoneContainer.h"
#include "BonePose.h"
#include "BoneControllers/AnimNode_SkeletalControlBase.h"
#include "AnimNode_ModifyVMC4UEBones.generated.h"

class USkeletalMeshComponent;
class UVMC4UEVRMMapping;
class UVMC4UEStreamingSkeletalMeshTransform;

/**
 *
 */
USTRUCT(BlueprintInternalUseOnly)
struct VMC4UE_API FAnimNode_ModifyVMC4UEBones : public FAnimNode_SkeletalControlBase
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Alpha, meta = (PinShownByDefault))
	UVMC4UEVRMMapping* VRMMapping;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Alpha, meta = (PinShownByDefault))
	int32 Port;

	FAnimNode_ModifyVMC4UEBones() {}
	FAnimNode_ModifyVMC4UEBones(const class FObjectInitializer &ObjectInitializer) {}

    virtual void Initialize_AnyThread(const FAnimationInitializeContext& Context) override;
	virtual void CacheBones_AnyThread(const FAnimationCacheBonesContext& Context) override;

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
	void BuildMapping();

	UPROPERTY()
	bool bIsInitialized;
	UPROPERTY()
	TMap<FName, FName> BoneMappingSkeletonToVMC;
	UPROPERTY()
	TArray<FTransform> InitialBones;
	UPROPERTY()
	TArray<FBoneReference> BoneReferences;
	UPROPERTY()
	UVMC4UEVRMMapping* PrevVRMMapping;
};
