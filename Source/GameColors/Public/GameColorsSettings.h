// Cem Akkaya, Inc. All Rights Reserved.

#pragma once
#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "GameColorsSettings.generated.h"

/**
 * 
 */

UENUM(BlueprintType)
enum class FGameColorsProfile : uint8
{
	CProfileDefault UMETA(DisplayName = "Default Colors"),
	CProfileDeutan UMETA(DisplayName = "Deutan Colors"),
	CProfileProtan UMETA(DisplayName = "Protan Colors"),
	CProfileTritan UMETA(DisplayName = "Tritan Colors"),
	CProfilePlayer UMETA(DisplayName = "Player Custom Colors")
};

UCLASS(Config = Game, DefaultConfig, meta = (DisplayName="Game Color Settings")) 
class GAMECOLORS_API UGameColorsSettings : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(Config, EditAnywhere, BlueprintReadWrite, Category = "Colors System - Settings")
	mutable FGameColorsProfile GameColorActiveProfile;

	UPROPERTY(Config, EditAnywhere, BlueprintReadWrite, Category = "Colors System - Settings")
	FGameColorsProfile PlayerCustomColorProfile;
	
	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "Colors System - Settings")
	TSoftObjectPtr<UDataTable> GameColorsTable;
	
	UPROPERTY(Config, EditAnywhere, Category = "Colors System - Settings")
	mutable bool CorrectDeficiency;

	UPROPERTY(Config, EditAnywhere, BlueprintReadWrite, meta = (Min = "0", Max = "1"), Category = "Colors System - Settings")
	mutable float ColorAccessibilityProfileIntensity;

	UPROPERTY(Config, EditAnywhere, BlueprintReadWrite, meta = (Min = "0", Max = "1"), Category = "Colors System - Settings")
	mutable EColorVisionDeficiency DeficiencyType;

	UPROPERTY(Config, EditAnywhere, Category = "Colors System - Settings")
	mutable FColor GlobalDynamicFeedbackColor;
	
	UGameColorsSettings(const FObjectInitializer& ObjectInitializer);
};