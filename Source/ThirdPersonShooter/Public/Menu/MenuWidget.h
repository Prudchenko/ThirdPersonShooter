// Third Person Shooter, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "BaseWidget.h"
#include "Blueprint/UserWidget.h"
#include "TPSGameInstance.h"
#include "MenuWidget.generated.h"

class UButton;
class UHorizontalBox;
class ULevelItemWidget;
class USoundCue;

UCLASS()
class THIRDPERSONSHOOTER_API UMenuWidget : public UBaseWidget
{
	GENERATED_BODY()

	protected:
    UPROPERTY(meta = (BindWidget))
    UButton* StartGameButton;

    UPROPERTY(meta = (BindWidget))
    UButton* QuitGameButton;

    UPROPERTY(meta = (BindWidget))
    UHorizontalBox* LevelItemsBox;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI")
    TSubclassOf<UUserWidget> LevelItemWidgetClass;

    UPROPERTY(Transient, meta = (BindWidgetAnim))
    UWidgetAnimation* HideAnimation;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Sound")
    USoundCue* StartGameSound;

    virtual void NativeOnInitialized() override;
    virtual void OnAnimationFinished_Implementation(const UWidgetAnimation* Animation) override;

private:
    UPROPERTY()
    TArray<ULevelItemWidget*> LevelItemWidgets;

    UFUNCTION()
    void OnStartGame();

    UFUNCTION()
    void OnQuitGame();

    void InitLevelItems();
    void OnLevelSelected(const FLevelData& Data);
    UTPSGameInstance* GetTPSGameInstance() const;
};
