// Third Person Shooter, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TPSGameModeBase.h"
#include "TPSPlayerController.generated.h"

class URespawnComponent;

UCLASS()
class THIRDPERSONSHOOTER_API ATPSPlayerController : public APlayerController
{
	GENERATED_BODY()

	public:
    ATPSPlayerController();

protected:
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
    URespawnComponent* RespawnComponent;

    virtual void BeginPlay() override;
    virtual void OnPossess(APawn* InPawn) override;
    virtual void SetupInputComponent() override;

private:
    void OnPauseGame();
    void OnMatchStateChanged(EMatchState State);
    void OnMuteSound();
};
