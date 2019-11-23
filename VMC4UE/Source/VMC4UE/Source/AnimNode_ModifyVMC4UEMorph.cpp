// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "../INclude/AnimNode_ModifyVMC4UEMorph.h"
#include "AnimationRuntime.h"
#include "../Include/VMC4UEStreamingData.h"
#include "../Include/VMC4UEBoneMapping.h"
#include "Animation/AnimInstanceProxy.h"

void FAnimNode_ModifyVMC4UEMorph::Initialize_AnyThread(const FAnimationInitializeContext &Context)
{
    Super::Initialize_AnyThread(Context);
    SourcePose.Initialize(Context);

	MorphStates.Empty();
	if (VRMMapping.IsValid())
	{
		FVMC4UEVRMMappingData& VRMMappingData = VRMMapping.Get()->VRMMapping;

		for (auto& Mesh : VRMMappingData.BlendShape.Meshes)
		{
			for (int32 TargetIndex = 0; TargetIndex < Mesh.Targets.Num(); ++TargetIndex)
			{
				MorphStates.Add(Mesh.Targets[TargetIndex], 0.0f);
			}
		}
	}
}

void FAnimNode_ModifyVMC4UEMorph::CacheBones_AnyThread(const FAnimationCacheBonesContext &Context)
{
    Super::CacheBones_AnyThread(Context);
    SourcePose.CacheBones(Context);
}

void FAnimNode_ModifyVMC4UEMorph::Evaluate_AnyThread(FPoseContext &Output)
{
    FPoseContext SourceData(Output);
    SourcePose.Evaluate(SourceData);

    Output = SourceData;

	if (!StreamingSkeletalMeshTransform.IsValid())
	{
		return;
	}

    //	Morph target and Material parameter curves
    USkeleton *Skeleton = Output.AnimInstanceProxy->GetSkeleton();

	if (VRMMapping.IsValid())
	{
		FVMC4UEVRMMappingData& VRMMappingData = VRMMapping.Get()->VRMMapping;

		// Reset
		for (auto& MorphState : MorphStates)
		{
			MorphState.Value = 0.0f;
		}

		// Calc
		{
			FRWScopeLock RWScopeLock(StreamingSkeletalMeshTransform->RWLock, FRWScopeLockType::SLT_ReadOnly);

			for (const auto& BlendShape : StreamingSkeletalMeshTransform->CurrentBlendShapes)
			{
				auto Clip = VRMMappingData.BlendShape.Clips.FindByPredicate([BlendShape](const FVMC4UEBlendShapeClip& Clip) {
					return Clip.Name == BlendShape.Key;
				});
				if (Clip == nullptr)
				{
					continue;
				}
				const auto& Meshes = VRMMappingData.BlendShape.Meshes;

				for (const auto& State : Clip->States)
				{
					const auto Mesh = Meshes.FindByPredicate([State](const FVMC4UEBlendShapeMesh& Mesh) {
						return Mesh.Name == State.Name;
					});
					if (Mesh == nullptr)
					{
						continue;
					}

					for (const auto& Target : State.Targets)
					{
						const FName& MorphName = Mesh->Targets[Target.Index];
						if (MorphStates.Contains(MorphName))
						{
							MorphStates[MorphName] = Target.Weight * BlendShape.Value / 100.0f;
						}
					}
				}
			}
		}

		// Apply
		for (auto& MorphState : MorphStates)
		{
			SmartName::UID_Type NameUID = Skeleton->GetUIDByName(USkeleton::AnimCurveMappingName, MorphState.Key);
			if (NameUID != SmartName::MaxUID)
			{
				Output.Curve.Set(NameUID, MorphState.Value);
			}
		}
	}
}

void FAnimNode_ModifyVMC4UEMorph::Update_AnyThread(const FAnimationUpdateContext &Context)
{
    // Run update on input pose nodes
    SourcePose.Update(Context);

    // Evaluate any BP logic plugged into this node
    EvaluateGraphExposedInputs.Execute(Context);
}

#if WITH_EDITOR

void FAnimNode_ModifyVMC4UEMorph::AddCurve(const FName &InName, float InValue)
{
}

void FAnimNode_ModifyVMC4UEMorph::RemoveCurve(int32 PoseIndex)
{
}

#endif // WITH_EDITOR
