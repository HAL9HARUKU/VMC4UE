//#include "MySandboxDeveloper.h"
#include "../Include/AnimGraphNode_VMC4UE.h"

// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
#include "../../VMC4UE/Include/AnimNode_VMC4UE.h"
#include "UnrealWidget.h"
#include "AnimNodeEditModes.h"
#include "Kismet2/CompilerResultsLog.h"

/////////////////////////////////////////////////////
// UAnimGraphNode_VMC4UE

#define LOCTEXT_NAMESPACE "VMC4UEEd"

UAnimGraphNode_VMC4UE::UAnimGraphNode_VMC4UE(const FObjectInitializer &ObjectInitializer)
    : Super(ObjectInitializer)
{
    CurWidgetMode = (int32)FWidget::WM_Rotate;
}

FString UAnimGraphNode_VMC4UE::GetNodeCategory() const
{
	return TEXT("VMC4UE");
}

void UAnimGraphNode_VMC4UE::ValidateAnimNodeDuringCompilation(USkeleton *ForSkeleton, FCompilerResultsLog &MessageLog)
{
    Super::ValidateAnimNodeDuringCompilation(ForSkeleton, MessageLog);
}

FText UAnimGraphNode_VMC4UE::GetControllerDescription() const
{
    return LOCTEXT("TransformModifyBone", "Modify VMC4UE Bones");
}

FText UAnimGraphNode_VMC4UE::GetTooltipText() const
{
    return LOCTEXT("AnimGraphNode_ModifyBone_Tooltip", "The Transform Bone node");
}

FText UAnimGraphNode_VMC4UE::GetNodeTitle(ENodeTitleType::Type TitleType) const
{
    if ((TitleType == ENodeTitleType::ListView || TitleType == ENodeTitleType::MenuTitle))
    {
        return GetControllerDescription();
    }
    else if (!CachedNodeTitles.IsTitleCached(TitleType, this))
    {
        FFormatNamedArguments Args;
        Args.Add(TEXT("ControllerDescription"), GetControllerDescription());

        if (TitleType == ENodeTitleType::ListView || TitleType == ENodeTitleType::MenuTitle)
        {
            CachedNodeTitles.SetCachedTitle(TitleType, FText::Format(LOCTEXT("AnimGraphNode_VRMR4UE_ListTitle", "{ControllerDescription} - Bone: {BoneName}"), Args), this);
        }
        else
        {
            CachedNodeTitles.SetCachedTitle(TitleType, FText::Format(LOCTEXT("AnimGraphNode_VRMR4UE_Title", "{ControllerDescription}\nBone: {BoneName}"), Args), this);
        }
    }
    return CachedNodeTitles[TitleType];
}

void UAnimGraphNode_VMC4UE::CopyNodeDataToPreviewNode(FAnimNode_Base *InPreviewNode)
{
    FAnimNode_VMC4UE *ModifyBone = static_cast<FAnimNode_VMC4UE *>(InPreviewNode);

	ModifyBone->VRMMapping = Node.VRMMapping;
	ModifyBone->StreamingSkeletalMeshTransform = Node.StreamingSkeletalMeshTransform;
}

FEditorModeID UAnimGraphNode_VMC4UE::GetEditorMode() const
{
    return "AnimGraph.SkeletalControl.VMC4UE_ModifyBones";
}

void UAnimGraphNode_VMC4UE::CopyPinDefaultsToNodeData(UEdGraphPin *InPin)
{
}

#undef LOCTEXT_NAMESPACE
