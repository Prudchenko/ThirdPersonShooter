// Third Person Shooter, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GameDataWidget.generated.h"

class ATPSGameModeBase;
class ATPSPlayerState;

UCLASS()
class THIRDPERSONSHOOTER_API UGameDataWidget : public UUserWidget
{
	GENERATED_BODY()

		
public:
    UFUNCTION(BlueprintCallable, Category = "UI")
    int32 GetCurrentRoundNum() const;

    UFUNCTION(BlueprintCallable, Category = "UI")
    int32 GetTotalRoundsNum() const;

    UFUNCTION(BlueprintCallable, Category = "UI")
    int32 GetRoundSecondsRemaining() const;

private:
    ATPSGameModeBase* GetTPSGameMode() const;
    ATPSPlayerState* GetTPSPlayerState() const;
};