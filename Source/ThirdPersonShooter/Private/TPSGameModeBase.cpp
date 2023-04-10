// Third Person Shooter, All Rights Reserved

#include "TPSGameModeBase.h"
#include "TPSBaseCharacter.h"
#include "TPSPlayerController.h"

ATPSGameModeBase::ATPSGameModeBase()
{
    DefaultPawnClass = ATPSBaseCharacter::StaticClass();
    PlayerControllerClass = ATPSPlayerController::StaticClass();
}
