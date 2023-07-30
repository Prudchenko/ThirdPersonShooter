// Third Person Shooter, All Rights Reserved


#include "UI/GameDataWidget.h"
#include "TPSGameModeBase.h"
#include "Player/TPSPlayerState.h"

int32 UGameDataWidget::GetCurrentRoundNum() const
{
    const auto GameMode = GetTPSGameMode();
    return GameMode ? GameMode->GetCurrentRoundNum() : 0;
}

int32 UGameDataWidget::GetTotalRoundsNum() const
{
    const auto GameMode = GetTPSGameMode();
    return GameMode ? GameMode->GetGameData().RoundsNum : 0;
}

int32 UGameDataWidget::GetRoundSecondsRemaining() const
{
    const auto GameMode = GetTPSGameMode();
    return GameMode ? GameMode->GetRoundSecondsRemaining() : 0;
}

ATPSGameModeBase* UGameDataWidget::GetTPSGameMode() const
{
    return GetWorld() ? Cast<ATPSGameModeBase>(GetWorld()->GetAuthGameMode()) : nullptr;
}

ATPSPlayerState* UGameDataWidget::GetTPSPlayerState() const
{
    return GetOwningPlayer() ? Cast<ATPSPlayerState>(GetOwningPlayer()->PlayerState) : nullptr;
}
