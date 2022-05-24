//#include "MySandbox.h"
#include "../Include/AnimNode_ModifyVMC4UEBones.h"
#include "BoneControllers/AnimNode_ModifyBone.h"
#include "AnimationRuntime.h"
#include "Animation/AnimInstanceProxy.h"
#include "Misc/EngineVersionComparison.h"
#include "../Include/VMC4UEStreamingData.h"
#include "../Include/VMC4UEBoneMapping.h"
#include "../Include/VMC4UEBlueprintFunctionLibrary.h"
#include "Engine.h"

// ----------------------------------------------------------------------------
void FAnimNode_ModifyVMC4UEBones::Initialize_AnyThread(const FAnimationInitializeContext& Context)
{
	Super::Initialize_AnyThread(Context);

	InitializeBoneReferences(Context.AnimInstanceProxy->GetRequiredBones());

	this->bIsInitialized = true;
}

void FAnimNode_ModifyVMC4UEBones::CacheBones_AnyThread(const FAnimationCacheBonesContext& Context)
{
	//Super::CacheBones_AnyThread(Context);
	
	//InitializeBoneReferences(Context.AnimInstanceProxy->GetRequiredBones());
	ComponentPose.CacheBones(Context);
}

void FAnimNode_ModifyVMC4UEBones::GatherDebugData(FNodeDebugData &DebugData)
{
    FString DebugLine = DebugData.GetNodeName(this);

    DebugLine += "(";
    AddDebugNodeData(DebugLine);
    DebugData.AddDebugItem(DebugLine);

    ComponentPose.GatherDebugData(DebugData);
}

void FAnimNode_ModifyVMC4UEBones::EvaluateSkeletalControl_AnyThread(FComponentSpacePoseContext &Output, TArray<FBoneTransform> &OutBoneTransforms)
{
    check(OutBoneTransforms.Num() == 0);

	// Watch VRMMapping
	if (this->PrevVRMMapping != this->VRMMapping)
	{
		this->bIsInitialized = true;
	}
	this->PrevVRMMapping = this->VRMMapping;
	
	// Build Mapping
	if (this->bIsInitialized)
	{
		this->bIsInitialized = false;

		BuildMapping();
	}
	
	// Get SkeletamMesh Transform
	auto StreamingSkeletalMeshTransform = UVMC4UEBlueprintFunctionLibrary::GetStreamingSkeletalMeshTransform(this->Port);
	if (!IsValid(StreamingSkeletalMeshTransform))
	{
		return;
	}

	FRWScopeLock RWScopeLock(StreamingSkeletalMeshTransform->RWLock, FRWScopeLockType::SLT_ReadOnly);
	
	// Root
    FTransform RootTransform;
    {
		FVMC4UEStreamingBoneTransform &StreamingData = StreamingSkeletalMeshTransform->Root;
		RootTransform.SetTranslation(StreamingData.Location);
		RootTransform.SetRotation(StreamingData.Rotation);
		RootTransform.SetScale3D(FVector(1.0f, 1.0f, 1.0f));
    }

	// Bones
	const auto& BoneContainer = Output.Pose.GetPose().GetBoneContainer();
	auto &Pose = Output.Pose.GetPose();
    for (const auto &BoneIndex : Pose.ForEachBoneIndex())
    {
        FTransform BoneNewTransform = FTransform::Identity;

		// Bone Local
        auto &BoneReference = BoneReferences[BoneIndex.GetInt()];
        const FName &SkeletonBoneName = BoneReference.BoneName;
		bool bHasMatchBone = false;
		if (BoneMappingSkeletonToVMC.Contains(SkeletonBoneName))
		{
			const FName& VMCBoneName = BoneMappingSkeletonToVMC[SkeletonBoneName];
			if (StreamingSkeletalMeshTransform->Bones.Contains(VMCBoneName))
			{
				const auto& StreamingData = StreamingSkeletalMeshTransform->Bones[VMCBoneName];

				BoneNewTransform *= FTransform(StreamingData.Rotation, StreamingData.Location, FVector(1.0f, 1.0f, 1.0f));
				bHasMatchBone = true;
			}
		}
		if (!bHasMatchBone)
		{
			BoneNewTransform *= this->InitialBones[BoneIndex.GetInt()];
		}
		
		// Parent
        int32 ParentBoneIndex = BoneContainer.GetParentBoneIndex(BoneIndex.GetInt());
        if (ParentBoneIndex >= 0)
        {
            BoneNewTransform *= OutBoneTransforms[ParentBoneIndex].Transform;
        }
        else
        {
            BoneNewTransform *= RootTransform;
        }

		// Register Bone Transform
		OutBoneTransforms.Emplace(FBoneTransform(BoneIndex, BoneNewTransform));
    }
}

bool FAnimNode_ModifyVMC4UEBones::IsValidToEvaluate(const USkeleton *Skeleton, const FBoneContainer &RequiredBones)
{
    for (auto& BoneReference : this->BoneReferences)
    {
        if (BoneReference.IsValidToEvaluate(RequiredBones))
        {
            return true;
        }
    }
    return false;
}

void FAnimNode_ModifyVMC4UEBones::InitializeBoneReferences(const FBoneContainer &RequiredBones)
{
	// Build Bone BoneReference
	this->BoneReferences.SetNum(0);
	const auto& ReferenceSkeleton = RequiredBones.GetReferenceSkeleton();
	for (int32 BoneIndex = 0; BoneIndex < ReferenceSkeleton.GetNum(); ++BoneIndex)
	{
		this->BoneReferences.Emplace(ReferenceSkeleton.GetBoneName(BoneIndex));
		
		auto& BoneReference = this->BoneReferences.Last();
		BoneReference.Initialize(RequiredBones);
	}
	
	// Get Initial Bone Transform
#if UE_VERSION_OLDER_THAN(5,0,0)
	this->InitialBones = RequiredBones.GetRefPoseCompactArray();
#else
	this->InitialBones = RequiredBones.GetRefPoseArray();
#endif
}

void FAnimNode_ModifyVMC4UEBones::BuildMapping()
{
	// Build BoneMappingSkeletonToVMC
	BoneMappingSkeletonToVMC.Empty();
	if (!IsValid(VRMMapping))
	{
		UE_LOG(LogTemp, Error, TEXT("[AnimNode_VMC4UE] BoneMapping is None"));
		return;
	}
	FVMC4UEBoneMapping& BoneMapping = VRMMapping->VRMMapping.BoneMapping;
	if (BoneMapping.Hips.Compare("None") != 0)
		BoneMappingSkeletonToVMC.Emplace(BoneMapping.Hips, TEXT("Hips"));
	if (BoneMapping.LeftUpperLeg.Compare("None") != 0)
		BoneMappingSkeletonToVMC.Emplace(BoneMapping.LeftUpperLeg, TEXT("LeftUpperLeg"));
	if (BoneMapping.RightUpperLeg.Compare("None") != 0)
		BoneMappingSkeletonToVMC.Emplace(BoneMapping.RightUpperLeg, TEXT("RightUpperLeg"));
	if (BoneMapping.LeftLowerLeg.Compare("None") != 0)
		BoneMappingSkeletonToVMC.Emplace(BoneMapping.LeftLowerLeg, TEXT("LeftLowerLeg"));
	if (BoneMapping.RightLowerLeg.Compare("None") != 0)
		BoneMappingSkeletonToVMC.Emplace(BoneMapping.RightLowerLeg, TEXT("RightLowerLeg"));
	if (BoneMapping.LeftFoot.Compare("None") != 0)
		BoneMappingSkeletonToVMC.Emplace(BoneMapping.LeftFoot, TEXT("LeftFoot"));
	if (BoneMapping.RightFoot.Compare("None") != 0)
		BoneMappingSkeletonToVMC.Emplace(BoneMapping.RightFoot, TEXT("RightFoot"));
	if (BoneMapping.Spine.Compare("None") != 0)
		BoneMappingSkeletonToVMC.Emplace(BoneMapping.Spine, TEXT("Spine"));
	if (BoneMapping.Chest.Compare("None") != 0)
		BoneMappingSkeletonToVMC.Emplace(BoneMapping.Chest, TEXT("Chest"));
	if (BoneMapping.Neck.Compare("None") != 0)
		BoneMappingSkeletonToVMC.Emplace(BoneMapping.Neck, TEXT("Neck"));
	if (BoneMapping.Head.Compare("None") != 0)
		BoneMappingSkeletonToVMC.Emplace(BoneMapping.Head, TEXT("Head"));
	if (BoneMapping.LeftShoulder.Compare("None") != 0)
		BoneMappingSkeletonToVMC.Emplace(BoneMapping.LeftShoulder, TEXT("LeftShoulder"));
	if (BoneMapping.RightShoulder.Compare("None") != 0)
		BoneMappingSkeletonToVMC.Emplace(BoneMapping.RightShoulder, TEXT("RightShoulder"));
	if (BoneMapping.LeftUpperArm.Compare("None") != 0)
		BoneMappingSkeletonToVMC.Emplace(BoneMapping.LeftUpperArm, TEXT("LeftUpperArm"));
	if (BoneMapping.RightUpperArm.Compare("None") != 0)
		BoneMappingSkeletonToVMC.Emplace(BoneMapping.RightUpperArm, TEXT("RightUpperArm"));
	if (BoneMapping.LeftLowerArm.Compare("None") != 0)
		BoneMappingSkeletonToVMC.Emplace(BoneMapping.LeftLowerArm, TEXT("LeftLowerArm"));
	if (BoneMapping.RightLowerArm.Compare("None") != 0)
		BoneMappingSkeletonToVMC.Emplace(BoneMapping.RightLowerArm, TEXT("RightLowerArm"));
	if (BoneMapping.LeftHand.Compare("None") != 0)
		BoneMappingSkeletonToVMC.Emplace(BoneMapping.LeftHand, TEXT("LeftHand"));
	if (BoneMapping.RightHand.Compare("None") != 0)
		BoneMappingSkeletonToVMC.Emplace(BoneMapping.RightHand, TEXT("RightHand"));
	if (BoneMapping.LeftToes.Compare("None") != 0)
		BoneMappingSkeletonToVMC.Emplace(BoneMapping.LeftToes, TEXT("LeftToes"));
	if (BoneMapping.RightToes.Compare("None") != 0)
		BoneMappingSkeletonToVMC.Emplace(BoneMapping.RightToes, TEXT("RightToes"));
	if (BoneMapping.LeftEye.Compare("None") != 0)
		BoneMappingSkeletonToVMC.Emplace(BoneMapping.LeftEye, TEXT("LeftEye"));
	if (BoneMapping.RightEye.Compare("None") != 0)
		BoneMappingSkeletonToVMC.Emplace(BoneMapping.RightEye, TEXT("RightEye"));
	if (BoneMapping.Jaw.Compare("None") != 0)
		BoneMappingSkeletonToVMC.Emplace(BoneMapping.Jaw, TEXT("Jaw"));
	if (BoneMapping.LeftThumbProximal.Compare("None") != 0)
		BoneMappingSkeletonToVMC.Emplace(BoneMapping.LeftThumbProximal, TEXT("LeftThumbProximal"));
	if (BoneMapping.LeftThumbIntermediate.Compare("None") != 0)
		BoneMappingSkeletonToVMC.Emplace(BoneMapping.LeftThumbIntermediate, TEXT("LeftThumbIntermediate"));
	if (BoneMapping.LeftThumbDistal.Compare("None") != 0)
		BoneMappingSkeletonToVMC.Emplace(BoneMapping.LeftThumbDistal, TEXT("LeftThumbDistal"));
	if (BoneMapping.LeftIndexProximal.Compare("None") != 0)
		BoneMappingSkeletonToVMC.Emplace(BoneMapping.LeftIndexProximal, TEXT("LeftIndexProximal"));
	if (BoneMapping.LeftIndexIntermediate.Compare("None") != 0)
		BoneMappingSkeletonToVMC.Emplace(BoneMapping.LeftIndexIntermediate, TEXT("LeftIndexIntermediate"));
	if (BoneMapping.LeftIndexDistal.Compare("None") != 0)
		BoneMappingSkeletonToVMC.Emplace(BoneMapping.LeftIndexDistal, TEXT("LeftIndexDistal"));
	if (BoneMapping.LeftMiddleProximal.Compare("None") != 0)
		BoneMappingSkeletonToVMC.Emplace(BoneMapping.LeftMiddleProximal, TEXT("LeftMiddleProximal"));
	if (BoneMapping.LeftMiddleIntermediate.Compare("None") != 0)
		BoneMappingSkeletonToVMC.Emplace(BoneMapping.LeftMiddleIntermediate, TEXT("LeftMiddleIntermediate"));
	if (BoneMapping.LeftMiddleDistal.Compare("None") != 0)
		BoneMappingSkeletonToVMC.Emplace(BoneMapping.LeftMiddleDistal, TEXT("LeftMiddleDistal"));
	if (BoneMapping.LeftRingProximal.Compare("None") != 0)
		BoneMappingSkeletonToVMC.Emplace(BoneMapping.LeftRingProximal, TEXT("LeftRingProximal"));
	if (BoneMapping.LeftRingIntermediate.Compare("None") != 0)
		BoneMappingSkeletonToVMC.Emplace(BoneMapping.LeftRingIntermediate, TEXT("LeftRingIntermediate"));
	if (BoneMapping.LeftRingDistal.Compare("None") != 0)
		BoneMappingSkeletonToVMC.Emplace(BoneMapping.LeftRingDistal, TEXT("LeftRingDistal"));
	if (BoneMapping.LeftLittleProximal.Compare("None") != 0)
		BoneMappingSkeletonToVMC.Emplace(BoneMapping.LeftLittleProximal, TEXT("LeftLittleProximal"));
	if (BoneMapping.LeftLittleIntermediate.Compare("None") != 0)
		BoneMappingSkeletonToVMC.Emplace(BoneMapping.LeftLittleIntermediate, TEXT("LeftLittleIntermediate"));
	if (BoneMapping.LeftLittleDistal.Compare("None") != 0)
		BoneMappingSkeletonToVMC.Emplace(BoneMapping.LeftLittleDistal, TEXT("LeftLittleDistal"));
	if (BoneMapping.RightThumbProximal.Compare("None") != 0)
		BoneMappingSkeletonToVMC.Emplace(BoneMapping.RightThumbProximal, TEXT("RightThumbProximal"));
	if (BoneMapping.RightThumbIntermediate.Compare("None") != 0)
		BoneMappingSkeletonToVMC.Emplace(BoneMapping.RightThumbIntermediate, TEXT("RightThumbIntermediate"));
	if (BoneMapping.RightThumbDistal.Compare("None") != 0)
		BoneMappingSkeletonToVMC.Emplace(BoneMapping.RightThumbDistal, TEXT("RightThumbDistal"));
	if (BoneMapping.RightIndexProximal.Compare("None") != 0)
		BoneMappingSkeletonToVMC.Emplace(BoneMapping.RightIndexProximal, TEXT("RightIndexProximal"));
	if (BoneMapping.RightIndexIntermediate.Compare("None") != 0)
		BoneMappingSkeletonToVMC.Emplace(BoneMapping.RightIndexIntermediate), TEXT("RightIndexIntermediate");
	if (BoneMapping.RightIndexDistal.Compare("None") != 0)
		BoneMappingSkeletonToVMC.Emplace(BoneMapping.RightIndexDistal, TEXT("RightIndexDistal"));
	if (BoneMapping.RightMiddleProximal.Compare("None") != 0)
		BoneMappingSkeletonToVMC.Emplace(BoneMapping.RightMiddleProximal, TEXT("RightMiddleProximal"));
	if (BoneMapping.RightMiddleIntermediate.Compare("None") != 0)
		BoneMappingSkeletonToVMC.Emplace(BoneMapping.RightMiddleIntermediate, TEXT("RightMiddleIntermediate"));
	if (BoneMapping.RightMiddleDistal.Compare("None") != 0)
		BoneMappingSkeletonToVMC.Emplace(BoneMapping.RightMiddleDistal, TEXT("RightMiddleDistal"));
	if (BoneMapping.RightRingProximal.Compare("None") != 0)
		BoneMappingSkeletonToVMC.Emplace(BoneMapping.RightRingProximal, TEXT("RightRingProximal"));
	if (BoneMapping.RightRingIntermediate.Compare("None") != 0)
		BoneMappingSkeletonToVMC.Emplace(BoneMapping.RightRingIntermediate, TEXT("RightRingIntermediate"));
	if (BoneMapping.RightRingDistal.Compare("None") != 0)
		BoneMappingSkeletonToVMC.Emplace(BoneMapping.RightRingDistal, TEXT("RightRingDistal"));
	if (BoneMapping.RightLittleProximal.Compare("None") != 0)
		BoneMappingSkeletonToVMC.Emplace(BoneMapping.RightLittleProximal, TEXT("RightLittleProximal"));
	if (BoneMapping.RightLittleIntermediate.Compare("None") != 0)
		BoneMappingSkeletonToVMC.Emplace(BoneMapping.RightLittleIntermediate, TEXT("RightLittleIntermediate"));
	if (BoneMapping.RightLittleDistal.Compare("None") != 0)
		BoneMappingSkeletonToVMC.Emplace(BoneMapping.RightLittleDistal, TEXT("RightLittleDistal"));
}
