// Copyright Epic Games, Inc. All Rights Reserved.

#include "GameColors.h"

#include "GameColorsSettings.h"
#include "ISettingsModule.h"

#define LOCTEXT_NAMESPACE "FGameColorsModule"

void FGameColorsModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module

	if(ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
	{
		SettingsModule->RegisterSettings("Project", "Plugins", "Game Colors Settings",
			LOCTEXT("RuntimeSettings", "Game Colors"), LOCTEXT("RuntimeSettingsDescription", "Global Game Colors Definations"),
			GetMutableDefault<UGameColorsSettings>());
	}
}

void FGameColorsModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.

	if(ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
	{
		SettingsModule->UnregisterSettings("Project", "Plugins", "Game Colors Settings");
	}
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FGameColorsModule, GameColors)