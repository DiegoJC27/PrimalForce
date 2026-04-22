// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class PrimalForce : ModuleRules
{
	public PrimalForce(ReadOnlyTargetRules Target) : base(Target)
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
			"PrimalForce",
			"PrimalForce/Variant_Platforming",
			"PrimalForce/Variant_Platforming/Animation",
			"PrimalForce/Variant_Combat",
			"PrimalForce/Variant_Combat/AI",
			"PrimalForce/Variant_Combat/Animation",
			"PrimalForce/Variant_Combat/Gameplay",
			"PrimalForce/Variant_Combat/Interfaces",
			"PrimalForce/Variant_Combat/UI",
			"PrimalForce/Variant_SideScrolling",
			"PrimalForce/Variant_SideScrolling/AI",
			"PrimalForce/Variant_SideScrolling/Gameplay",
			"PrimalForce/Variant_SideScrolling/Interfaces",
			"PrimalForce/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
