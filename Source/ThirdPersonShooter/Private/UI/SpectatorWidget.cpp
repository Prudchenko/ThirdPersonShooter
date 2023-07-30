// Third Person Shooter, All Rights Reserved


#include "UI/SpectatorWidget.h"
#include "Components/RespawnComponent.h"

bool USpectatorWidget::GetRespawnTime(int32& CountDownTime) const
{
    const auto RespawnComponent = GetTPSPlayerComponent<URespawnComponent>(GetOwningPlayer());
    if (!RespawnComponent || !RespawnComponent->IsRespawnInProgress()) return false;

    CountDownTime = RespawnComponent->GetRespawnCountDown();
    return true;
}
