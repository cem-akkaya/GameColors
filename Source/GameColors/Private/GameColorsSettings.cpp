// Cem Akkaya, Inc. All Rights Reserved.

#include "GameColorsSettings.h"
#include "Interfaces/IPluginManager.h"

/**
 * 
 */

UGameColorsSettings::UGameColorsSettings(const FObjectInitializer& ObjectInitializer):Super(ObjectInitializer)
{
	ColorAccessibilityProfileIntensity = 0;
	CorrectDeficiency = false;
	GameColorActiveProfile = FGameColorsProfile::CProfileDefault;
	PlayerCustomColorProfile = FGameColorsProfile::CProfilePlayer;
	GlobalDynamicFeedbackColor = FColor::Black;

	FString DataTablePath = IPluginManager::Get().FindPlugin(TEXT("GameColors"))->GetBaseDir() + TEXT("/Script/Engine.DataTable'/GameColors/GameColorsDefault_DT.GameColorsDefault_DT'");
	ConstructorHelpers::FObjectFinder<UDataTable> DefaultDataTable(*DataTablePath);
	GameColorsTable = DefaultDataTable.Object;
	
	// Attempt to load the config file
	LoadConfig();
	SaveConfig();
}


