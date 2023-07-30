// Third Person Shooter, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "BaseWidget.h"
#include "TPSGameModeBase.h"
#include "GameOverWidget.generated.h"

class UVerticalBox;
class UButton;

UCLASS()
class THIRDPERSONSHOOTER_API UGameOverWidget : public UBaseWidget
{
	GENERATED_BODY()

	protected:
    UPROPERTY(meta = (BindWidget))
    UVerticalBox* PlayerStatBox;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI")
    TSubclassOf<UUserWidget> PlayerStatRowWidgetClass;

    UPROPERTY(meta = (BindWidget))
    UButton* ResetLevelButton;

    virtual void NativeOnInitialized() override;
    static FText TextFromInt(int32 Number) { return FText::FromString(FString::FromInt(Number)); }

private:
    void OnMatchStateChanged(EMatchState State);
    void UpdatePlayersStat();

    UFUNCTION()
    void OnResetLevel();
};
