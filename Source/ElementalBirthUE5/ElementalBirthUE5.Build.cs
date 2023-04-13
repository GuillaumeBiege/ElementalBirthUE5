// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class ElementalBirthUE5 : ModuleRules
{
	public ElementalBirthUE5(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "GameplayAbilities", "GameplayTags", "GameplayTasks", "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "Niagara" });
		//PublicIncludePaths.Add(Path.Combine(ModuleDirectory, "Niagara"));
	}
}
