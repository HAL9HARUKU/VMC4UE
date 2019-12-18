//#include "MySandboxDeveloper.h"
#include "../Include/AnimGraphNode_ModifyVMC4UEBones.h"

// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
#include "../../VMC4UE/Include/AnimNode_ModifyVMC4UEBones.h"
#include "UnrealWidget.h"
#include "AnimNodeEditModes.h"
#include "Kismet2/CompilerResultsLog.h"

/////////////////////////////////////////////////////
// UAnimGraphNode_ModifyVMC4UEBones

#define LOCTEXT_NAMESPACE "VMC4UEEd"

UAnimGraphNode_ModifyVMC4UEBones::UAnimGraphNode_ModifyVMC4UEBones(const FObjectInitializer &ObjectInitializer)
    : Super(ObjectInitializer)
{
}

FString UAnimGraphNode_ModifyVMC4UEBones::GetNodeCategory() const
{
	return TEXT("VMC4UE");
}

void UAnimGraphNode_ModifyVMC4UEBones::ValidateAnimNodeDuringCompilation(USkeleton *ForSkeleton, FCompilerResultsLog &MessageLog)
{
    Super::ValidateAnimNodeDuringCompilation(ForSkeleton, MessageLog);
}

FText UAnimGraphNode_ModifyVMC4UEBones::GetControllerDescription() const
{
    return LOCTEXT("TransformModifyBone", "Modify VMC4UE Bones");
}

FText UAnimGraphNode_ModifyVMC4UEBones::GetTooltipText() const
{
    return LOCTEXT("AnimGraphNode_ModifyBone_Tooltip", "The Transform Bone node");
}

FText UAnimGraphNode_ModifyVMC4UEBones::GetNodeTitle(ENodeTitleType::Type TitleType) const
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

FEditorModeID UAnimGraphNode_ModifyVMC4UEBones::GetEditorMode() const
{
    return "AnimGraphNode.ModifyVMC4UEBones";
}

#undef LOCTEXT_NAMESPACE
