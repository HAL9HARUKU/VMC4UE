// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class VMC4UEEd : ModuleRules
{
    public VMC4UEEd (ReadOnlyTargetRules Target) : base (Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
		
        PrivateDependencyModuleNames.AddRange (new string[] { "Core", "CoreUObject", "Engine", "UnrealEd", "InputCore", "HeadMountedDisplay", "AnimGraph", "BlueprintGraph", "Json", "JsonUtilities", "VMC4UE" });
    }
}
