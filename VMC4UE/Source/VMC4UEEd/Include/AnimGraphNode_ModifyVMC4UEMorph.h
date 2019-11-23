// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "AnimGraphNode_Base.h"
#include "../../VMC4UE/Include/AnimNode_ModifyVMC4UEMorph.h"
#include "AnimGraphNode_ModifyVMC4UEMorph.generated.h"

class FMenuBuilder;

/** Easy way to modify curve values on a pose */
UCLASS(MinimalAPI)
class UAnimGraphNode_ModifyVMC4UEMorph : public UAnimGraphNode_Base
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, Category = Settings)
    FAnimNode_ModifyVMC4UEMorph Node;

public:
	UAnimGraphNode_ModifyVMC4UEMorph();

    // UEdGraphNode interface
    virtual FText GetTooltipText() const override;
    virtual FText GetNodeTitle(ENodeTitleType::Type TitleType) const override;
    // End of UEdGraphNode interface

    // UAnimGraphNode_Base interface
    virtual FString GetNodeCategory() const override;
    virtual void CustomizePinData(UEdGraphPin *Pin, FName SourcePropertyName, int32 ArrayIndex) const override;
    // End of UAnimGraphNode_Base interface

    // UK2Node interface
    virtual void GetContextMenuActions(const FGraphNodeContextMenuBuilder &Context) const override;
    // End of UK2Node interface

private:
    /** Remove a curve pin with the given name */
    void RemoveCurvePin(FName CurveName);
    /** Add a curve pin with the given name */
    void AddCurvePin(FName CurveName);
    /** Create submenu with options for curves to add */
    void GetAddCurveMenuActions(FMenuBuilder &MenuBuilder) const;
    /** Create submenu with options for curves to remove */
    void GetRemoveCurveMenuActions(FMenuBuilder &MenuBuilder) const;
    /** Returns list of curves we have not added yet */
    TArray<FName> GetCurvesToAdd() const;
};
