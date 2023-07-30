// Third Person Shooter, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "BaseWidget.generated.h"

class USoundCue;

UCLASS()
class THIRDPERSONSHOOTER_API UBaseWidget : public UUserWidget
{
	GENERATED_BODY()


	public:
    void Show();

protected:
    UPROPERTY(Transient, meta = (BindWidgetAnim))
    UWidgetAnimation* ShowAnimation;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Sound")
    USoundCue* OpenSound;
};
