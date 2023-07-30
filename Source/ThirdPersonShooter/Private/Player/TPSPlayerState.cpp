// Third Person Shooter, All Rights Reserved


#include "Player/TPSPlayerState.h"

void ATPSPlayerState::LogInfo()
{
    UE_LOG(LogTemp, Display, TEXT("TeamID: %i, Kills: %i, Deaths: %i"), TeamID, KillsNum, DeathsNum);
}