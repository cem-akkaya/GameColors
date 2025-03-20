// Cem Akkaya, Inc. All Rights Reserved.

#include "GameColorsSubsystem.h"
#include "GameColorsSettings.h"
#include "Blueprint/WidgetBlueprintLibrary.h"


void UGameColorsSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	ReInitializeColors();
}

void UGameColorsSubsystem::Deinitialize()
{
	Super::Deinitialize();
}


void UGameColorsSubsystem::SetGlobalDynamicFeedbackColor(FColor NewColor)
{
	const UGameColorsSettings* GCSettings = GetDefault<UGameColorsSettings>();
	GCSettings->GlobalDynamicFeedbackColor = NewColor;
	
	ReInitializeColors();
}

FColor UGameColorsSubsystem::GetGlobalDynamicFeedbackColor()
{
	return GlobalDynamicFeedbackColor;
}

FColor UGameColorsSubsystem::MakeRandomColor()
{
	FColor RandomColor = FColor(FMath::Rand() % 256, FMath::Rand() % 256, FMath::Rand() % 256, 255);
	return RandomColor;
}

void UGameColorsSubsystem::ReInitializeColors() {
	
	const UGameColorsSettings* GCSettings = GetDefault<UGameColorsSettings>();
	const_cast<UGameColorsSettings*>(GCSettings)->TryUpdateDefaultConfigFile();

	//Get active profile and select colors from data
	const auto ActiveProfile = GCSettings->GameColorActiveProfile;

	GameColorProfileName = GetColorProfileRowName(ActiveProfile);
	
	RowName = GetColorProfileRowName(ActiveProfile);
	const UDataTable* GameColorsTable = GCSettings->GameColorsTable.LoadSynchronous();

	const auto HandledRow = GameColorsTable->FindRow<FAllGameColors>(*RowName, "");
	
	MainAccentColor = AllGameColors.MainAccentColor = HandledRow->MainAccentColor;
	BeneficialColor = AllGameColors.BeneficialColor = HandledRow->BeneficialColor;
	NonBeneficialColor = AllGameColors.NonBeneficialColor = HandledRow->NonBeneficialColor;
	CurrentDynamicAccentColor = AllGameColors.CurrentDynamicAccentColor = HandledRow->CurrentDynamicAccentColor;
	InteractionColor = AllGameColors.InteractionColor = HandledRow->InteractionColor;
	UIAccent = AllGameColors.UIAccent = HandledRow->UIAccent;
	UIConfirmation = AllGameColors.UIConfirmation = HandledRow->UIConfirmation;
	UICancellation = AllGameColors.UICancellation = HandledRow->UICancellation;

	//Below colors is only accessible through struct all game colors that are less commonly used and talked.
	AllGameColors.UIIndicatorNatural = HandledRow->UIIndicatorNatural;
	AllGameColors.UIIndicatorPositive = HandledRow->UIIndicatorPositive;
	AllGameColors.UIIndicatorNegative = HandledRow->UIIndicatorNegative;
	AllGameColors.UICommonText = HandledRow->UICommonText;
	AllGameColors.UICommonSubText = HandledRow->UICommonSubText;
	AllGameColors.UICommonTitle = HandledRow->UICommonTitle;
	AllGameColors.UICommonSubTitle = HandledRow->UICommonSubTitle;
	AllGameColors.GameNatural = HandledRow->GameNatural;
	AllGameColors.GamePhase = HandledRow->GamePhase;
	AllGameColors.GameCustom = HandledRow->GameCustom;

	
	GlobalDynamicFeedbackColor = GCSettings->GlobalDynamicFeedbackColor;
	
	//Declare accessibility options to subsystem from config
	AccessibilityProfile = GCSettings->DeficiencyType;
	CorrectDeficiency = GCSettings->CorrectDeficiency;
	AccessibilityProfileIntensity = GCSettings-> ColorAccessibilityProfileIntensity;

	if (AccessibilityProfile != EColorVisionDeficiency::NormalVision)
	{
		SetAccessibleColors(AccessibilityProfile, CorrectDeficiency, AccessibilityProfileIntensity);
	}

	
	//Broadcast Color Change
	OnColorChangeEvent.Broadcast();
}

void UGameColorsSubsystem::SetActiveColorProfile(FGameColorsProfile GameColorProfiles) {

	const UGameColorsSettings* GCSettings = GetDefault<UGameColorsSettings>();
	GCSettings->GameColorActiveProfile = GameColorProfiles;

	ReInitializeColors();
}

FString UGameColorsSubsystem::GetColorProfileRowName(FGameColorsProfile GameColorProfiles) {

	FString RowName;
	
	switch (GameColorProfiles)
	{
	case FGameColorsProfile::CProfileDefault :
		RowName = "DefaultColors";
		break;

	case FGameColorsProfile::CProfileDeutan:
		RowName = "Deutan";
		break;
		
	case FGameColorsProfile::CProfileProtan:
		RowName = "Protan";
		break;
		
	case FGameColorsProfile::CProfileTritan:
		RowName = "Tritan";
		break;
		
	case FGameColorsProfile::CProfilePlayer:
		RowName = "PlayerCustom";
		break;
		
	default: RowName = "DefaultColors";
	}
	return RowName;
}


void UGameColorsSubsystem::SetPlayerCustomColor(FAllGameColors CustomPlayerColors) {

	// Create reference
	const auto GCSettings = NewObject<UGameColorsSettings>();
	
	// Get default player custom color profile name from settings
	const auto PlayerColorProfile = GCSettings->PlayerCustomColorProfile;
	
	// Get row name from enum
	FString PlayerColorProfileRowName = GetColorProfileRowName(PlayerColorProfile);
	
	// Find row in color table and assign a new color as parameter to the row.
	auto ExistingCustomPlayerColorProfileRow = &CustomPlayerColors;
	
	//Add to table
	GCSettings->GameColorsTable->AddRow(FName(PlayerColorProfileRowName),*ExistingCustomPlayerColorProfileRow);

	ReInitializeColors();
}

void UGameColorsSubsystem::SetAccessibleColors(EColorVisionDeficiency Deficiency, bool DeficiencyStatus,float AccessibilityColorIntensity) {

	const UGameColorsSettings* GCSettings = GetDefault<UGameColorsSettings>();
	GCSettings->CorrectDeficiency = DeficiencyStatus;
	GCSettings->ColorAccessibilityProfileIntensity = AccessibilityColorIntensity;
	GCSettings->DeficiencyType = Deficiency;
	
	const auto AccessibilitySettings = NewObject<UWidgetBlueprintLibrary>();
	UWidgetBlueprintLibrary* UGameColorsClass = Cast<UWidgetBlueprintLibrary>(AccessibilitySettings);
	UGameColorsClass->SetColorVisionDeficiencyType(Deficiency, AccessibilityColorIntensity, CorrectDeficiency, false );

}


FColor UGameColorsSubsystem::HexToColor(const FString& HexString)
{
	return FColor::FromHex(HexString);
}

FString UGameColorsSubsystem::ColorToHex(const FColor Color)
{
	return Color.ToHex();
}

