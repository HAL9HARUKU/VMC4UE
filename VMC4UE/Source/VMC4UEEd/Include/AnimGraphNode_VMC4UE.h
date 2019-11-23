#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "EdGraph/EdGraphNodeUtils.h"
#include "AnimGraphNode_SkeletalControlBase.h"
#include "../../VMC4UE/Include/AnimNode_VMC4UE.h"
#include "AnimGraphNode_VMC4UE.generated.h"

class FCompilerResultsLog;

/**
 *
 */
UCLASS(meta = (Keywords = "VMC4UE Modify Transform"))
class VMC4UEED_API UAnimGraphNode_VMC4UE : public UAnimGraphNode_SkeletalControlBase
{
    GENERATED_UCLASS_BODY()

    UPROPERTY(EditAnywhere, Category = Settings)
    FAnimNode_VMC4UE Node;

public:
    // UEdGraphNode interface
    virtual FText GetNodeTitle(ENodeTitleType::Type TitleType) const override;
    virtual FText GetTooltipText() const override;
    // End of UEdGraphNode interface

protected:
    // UAnimGraphNode_Base interface
	virtual FString GetNodeCategory() const override;
    virtual void ValidateAnimNodeDuringCompilation(USkeleton *ForSkeleton, FCompilerResultsLog &MessageLog) override;
    virtual FEditorModeID GetEditorMode() const override;
    virtual void CopyNodeDataToPreviewNode(FAnimNode_Base *InPreviewNode) override;
    virtual void CopyPinDefaultsToNodeData(UEdGraphPin *InPin) override;
    // End of UAnimGraphNode_Base interface

    // UAnimGraphNode_SkeletalControlBase interface
    virtual FText GetControllerDescription() const override;
    virtual const FAnimNode_SkeletalControlBase *GetNode() const override { return &Node; }
    // End of UAnimGraphNode_SkeletalControlBase interface

private:
    /** Constructing FText strings can be costly, so we cache the node's title */
    FNodeTitleTextTable CachedNodeTitles;

    // storing current widget mode
    int32 CurWidgetMode;
};
