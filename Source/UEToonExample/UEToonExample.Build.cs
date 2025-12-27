// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class UEToonExample : ModuleRules
{
	public UEToonExample(ReadOnlyTargetRules Target) : base(Target)
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
			"UEToonExample",
			"UEToonExample/Variant_Platforming",
			"UEToonExample/Variant_Platforming/Animation",
			"UEToonExample/Variant_Combat",
			"UEToonExample/Variant_Combat/AI",
			"UEToonExample/Variant_Combat/Animation",
			"UEToonExample/Variant_Combat/Gameplay",
			"UEToonExample/Variant_Combat/Interfaces",
			"UEToonExample/Variant_Combat/UI",
			"UEToonExample/Variant_SideScrolling",
			"UEToonExample/Variant_SideScrolling/AI",
			"UEToonExample/Variant_SideScrolling/Gameplay",
			"UEToonExample/Variant_SideScrolling/Interfaces",
			"UEToonExample/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
