// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "../Include/AnimGraphNode_ModifyVMC4UEMorph.h"
#include "Textures/SlateIcon.h"
#include "GraphEditorActions.h"
#include "ScopedTransaction.h"
#include "Kismet2/CompilerResultsLog.h"
#include "AnimationGraphSchema.h"
#include "BlueprintActionDatabaseRegistrar.h"
#include "Framework/Commands/UIAction.h"
#include "Framework/MultiBox/MultiBoxBuilder.h"
#include "Kismet2/BlueprintEditorUtils.h"

#define LOCTEXT_NAMESPACE "ModifyVMC4UEMorph"

UAnimGraphNode_ModifyVMC4UEMorph::UAnimGraphNode_ModifyVMC4UEMorph()
{
}

FString UAnimGraphNode_ModifyVMC4UEMorph::GetNodeCategory() const
{
    return TEXT("VMC4UE");
}

FText UAnimGraphNode_ModifyVMC4UEMorph::GetTooltipText() const
{
    return GetNodeTitle(ENodeTitleType::ListView);
}

FText UAnimGraphNode_ModifyVMC4UEMorph::GetNodeTitle(ENodeTitleType::Type TitleType) const
{
    return LOCTEXT("AnimGraphNode_ModifyCurve_Title", "Modify VMC4UE Morph");
}

TArray<FName> UAnimGraphNode_ModifyVMC4UEMorph::GetCurvesToAdd() const
{
    TArray<FName> CurvesToAdd;

    return CurvesToAdd;
}

void UAnimGraphNode_ModifyVMC4UEMorph::GetAddCurveMenuActions(FMenuBuilder &MenuBuilder) const
{
}

void UAnimGraphNode_ModifyVMC4UEMorph::GetRemoveCurveMenuActions(FMenuBuilder &MenuBuilder) const
{
}

void UAnimGraphNode_ModifyVMC4UEMorph::GetContextMenuActions(const FGraphNodeContextMenuBuilder &Context) const
{
}

void UAnimGraphNode_ModifyVMC4UEMorph::RemoveCurvePin(FName CurveName)
{
}

void UAnimGraphNode_ModifyVMC4UEMorph::AddCurvePin(FName CurveName)
{
}

void UAnimGraphNode_ModifyVMC4UEMorph::CustomizePinData(UEdGraphPin *Pin, FName SourcePropertyName, int32 ArrayIndex) const
{
}

#undef LOCTEXT_NAMESPACE
