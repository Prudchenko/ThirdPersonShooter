// Third Person Shooter, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "BaseWidget.h"
#include "PauseWidget.generated.h"

class UButton;

UCLASS()
class THIRDPERSONSHOOTER_API UPauseWidget : public UBaseWidget
{
	GENERATED_BODY()

	protected:
    UPROPERTY(meta = (BindWidget))
    UButton* ClearPauseButton;

    virtual void NativeOnInitialized() override;

private:
    UFUNCTION()
    void OnClearPause();
};
