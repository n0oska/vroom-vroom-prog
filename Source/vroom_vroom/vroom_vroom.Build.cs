// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class vroom_vroom : ModuleRules
{
	public vroom_vroom(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"vroom_vroom",
			"vroom_vroom/Variant_Platforming",
			"vroom_vroom/Variant_Platforming/Animation",
			"vroom_vroom/Variant_Combat",
			"vroom_vroom/Variant_Combat/AI",
			"vroom_vroom/Variant_Combat/Animation",
			"vroom_vroom/Variant_Combat/Gameplay",
			"vroom_vroom/Variant_Combat/Interfaces",
			"vroom_vroom/Variant_Combat/UI",
			"vroom_vroom/Variant_SideScrolling",
			"vroom_vroom/Variant_SideScrolling/AI",
			"vroom_vroom/Variant_SideScrolling/Gameplay",
			"vroom_vroom/Variant_SideScrolling/Interfaces",
			"vroom_vroom/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
