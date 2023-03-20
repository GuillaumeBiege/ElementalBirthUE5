// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class ElementalBirthUE5 : ModuleRules
{
	public ElementalBirthUE5(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
