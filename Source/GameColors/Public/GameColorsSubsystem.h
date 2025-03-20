// Cem Akkaya, Inc. All Rights Reserved.

#pragma once

#include "GameColorsSettings.h"
#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "GameColorsSubsystem.generated.h"


USTRUCT(BlueprintType)
struct FAllGameColors : public FTableRowBase 
{
	GENERATED_USTRUCT_BODY()
	
	FColor FallBackColor = FColor(0,0,0,0);

	//Initialize Fallback
	FAllGameColors() :
		MainAccentColor(FallBackColor),
		BeneficialColor(FallBackColor),
		NonBeneficialColor(FallBackColor),
		CurrentDynamicAccentColor(FallBackColor),
		InteractionColor(FallBackColor),
		UIAccent(FallBackColor),
		UIConfirmation(FallBackColor),
		UICancellation(FallBackColor), UIIndicatorPositive(), UIIndicatorNegative(), UIIndicatorNatural(),
		UICommonText(), UICommonSubText(),
		UICommonTitle(),
		UICommonSubTitle(),
		GameNatural(), GamePhase(), GameCustom()
	{
	}

	UPROPERTY(Config, EditAnywhere, BlueprintReadWrite, Category = "Game Colors Subsystem - General Colors")
	FColor MainAccentColor;
	
	UPROPERTY(Config, EditAnywhere, BlueprintReadWrite, Category = "Game Colors Subsystem - General Colors")
	FColor BeneficialColor;

	UPROPERTY(Config, EditAnywhere, BlueprintReadWrite, Category = "Game Colors Subsystem - General Colors")
	FColor NonBeneficialColor;

	UPROPERTY(Config, EditAnywhere, BlueprintReadWrite, Category = "Game Colors Subsystem - Global Colors")
	FColor CurrentDynamicAccentColor;

	UPROPERTY(Config, EditAnywhere, BlueprintReadWrite, Category = "Game Colors Subsystem - Global Colors")
	FColor InteractionColor;
	
	UPROPERTY(Config, EditAnywhere, BlueprintReadWrite, Category = "Game Colors Subsystem - Interface Colors")
	FColor UIAccent;

	UPROPERTY(Config, EditAnywhere, BlueprintReadWrite, Category = "Game Colors Subsystem - Interface Colors")
	FColor UIConfirmation;

	UPROPERTY(Config, EditAnywhere, BlueprintReadWrite, Category = "Game Colors Subsystem - Interface Colors")
	FColor UICancellation;

	UPROPERTY(Config, EditAnywhere, BlueprintReadWrite, Category = "Game Colors Subsystem - Interface Pripheral Colors")
	FColor UIIndicatorPositive;

	UPROPERTY(Config, EditAnywhere, BlueprintReadWrite, Category = "Game Colors Subsystem - Interface Pripheral Colors")
	FColor UIIndicatorNegative;

	UPROPERTY(Config, EditAnywhere, BlueprintReadWrite, Category = "Game Colors Subsystem - Interface Pripheral Colors")
	FColor UIIndicatorNatural;

	UPROPERTY(Config, EditAnywhere, BlueprintReadWrite, Category = "Game Colors Subsystem - Interface Pripheral Colors")
	FColor UICommonText;

	UPROPERTY(Config, EditAnywhere, BlueprintReadWrite, Category = "Game Colors Subsystem - Interface Pripheral Colors")
	FColor UICommonSubText;

	UPROPERTY(Config, EditAnywhere, BlueprintReadWrite, Category = "Game Colors Subsystem - Interface Pripheral Colors")
	FColor UICommonTitle;

	UPROPERTY(Config, EditAnywhere, BlueprintReadWrite, Category = "Game Colors Subsystem - Interface Pripheral Colors")
	FColor UICommonSubTitle;

	UPROPERTY(Config, EditAnywhere, BlueprintReadWrite, Category = "Game Colors Subsystem - Game Pripheral Colors")
	FColor GameNatural;

	UPROPERTY(Config, EditAnywhere, BlueprintReadWrite, Category = "Game Colors Subsystem - Game Pripheral Colors")
	FColor GamePhase;

	UPROPERTY(Config, EditAnywhere, BlueprintReadWrite, Category = "Game Colors Subsystem - Game Pripheral Colors")
	FColor GameCustom;
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FColorChangeDelegate);

UCLASS(Config=Game, meta=(DisplayName="Game Colors Subsystem"))

class GAMECOLORS_API UGameColorsSubsystem : public UEngineSubsystem
{
	GENERATED_BODY()

	//~ Begin Subsystem
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;
	//~ End Subsystem


public:

	UPROPERTY(BlueprintAssignable, Category = "Game Colors Subsystem - Events")
	FColorChangeDelegate OnColorChangeEvent;

	// Color

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Game Colors Subsystem - General Colors") 
	FColor GlobalDynamicFeedbackColor;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Colors Subsystem - General Colors") 
	FAllGameColors AllGameColors;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Game Colors Subsystem - General Colors") 
	FColor MainAccentColor;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Game Colors Subsystem - General Colors") 
	FColor BeneficialColor;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Game Colors Subsystem - General Colors") 
	FColor NonBeneficialColor;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Game Colors Subsystem - General Colors") 
	FColor CurrentDynamicAccentColor;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Game Colors Subsystem - General Colors") 
	FColor InteractionColor;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Game Colors Subsystem - General Colors") 
	FColor UIAccent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Game Colors Subsystem - General Colors") 
	FColor UIConfirmation;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Game Colors Subsystem - General Colors") 
	FColor UICancellation;
	
	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "Game Colors Subsystem - Accessibility")
	FString GameColorProfileName;

	UFUNCTION(BlueprintCallable, Category = "Game Colors Subsystem")
	void SetGlobalDynamicFeedbackColor(FColor NewColor);

	UFUNCTION(BlueprintCallable, Category = "Game Colors Subsystem")
	FColor GetGlobalDynamicFeedbackColor();

	UFUNCTION(BlueprintCallable, Category = "Game Colors Subsystem")
	FColor MakeRandomColor();
	
	void ReInitializeColors();
	
	static FString GetColorProfileRowName(FGameColorsProfile GameColorProfiles);

	UFUNCTION(BlueprintCallable, Category = "Game Colors Subsystem Colors - Customize")
	void SetActiveColorProfile(FGameColorsProfile GameColorProfiles);
	
	UFUNCTION(BlueprintCallable, Category = "Game Colors Subsystem Colors - Customize")
	void SetPlayerCustomColor(FAllGameColors CustomPlayerColors) ;
	
	UFUNCTION(BlueprintCallable, Category = "Game Colors Subsystem Colors - Customize")
	void SetAccessibleColors(EColorVisionDeficiency Deficiency, bool DeficiencyStatus,float AccessibilityColorIntensity);

	UFUNCTION(BlueprintCallable, Category = "Game Colors Subsystem Colors - Helpers")
	static FColor HexToColor(const FString& HexString);

	UFUNCTION(BlueprintCallable, Category = "Game Colors Subsystem Colors - Helpers")
	static FString ColorToHex(FColor Color);
	
	UPROPERTY(Config, EditAnywhere, BlueprintReadWrite, Category = "Game Colors Subsystem Colors - Customize")
	EColorVisionDeficiency AccessibilityProfile;

	UPROPERTY(Config, EditAnywhere, BlueprintReadWrite, Category = "Game Colors Subsystem Colors - Customize")
	bool CorrectDeficiency;
	
	UPROPERTY(Config, EditAnywhere, BlueprintReadWrite, Category = "Game Colors Subsystem Colors - Customize")
	float AccessibilityProfileIntensity;
	
	TMap<FString,FColor> AllGameColorsMap;
	
	FString RowName;
	
};
