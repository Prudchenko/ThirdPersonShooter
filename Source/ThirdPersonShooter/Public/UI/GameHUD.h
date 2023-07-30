// Third Person Shooter, All Rights Reserved

#pragma once

#include "GameFramework/HUD.h"
#include "TPSGameModeBase.h"
#include "CoreMinimal.h"
#include "GameHUD.generated.h"

class UBaseWidget;

UCLASS()
class THIRDPERSONSHOOTER_API AGameHUD : public AHUD
{
	GENERATED_BODY()

	public:
    virtual void DrawHUD() override;

protected:
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI")
    TSubclassOf<UUserWidget> PlayerHUDWidgetClass;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI")
    TSubclassOf<UUserWidget> PauseWidgetClass;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI")
    TSubclassOf<UUserWidget> GameOverWidgetClass;

    virtual void BeginPlay() override;

private:
    UPROPERTY()
    TMap<EMatchState, UBaseWidget*> GameWidgets;

    UPROPERTY()
    UBaseWidget* CurrentWidget = nullptr;

    void DrawCrossHair();
    void OnMatchStateChanged(EMatchState State);
        
};
