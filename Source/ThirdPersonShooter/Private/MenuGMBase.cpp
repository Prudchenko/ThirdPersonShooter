// Third Person Shooter, All Rights Reserved


#include "MenuGMBase.h"

#include "Menu/MenuPlayerController.h"
#include "Menu/MenuHUD.h"

AMenuGMBase::AMenuGMBase()
{
    PlayerControllerClass = AMenuPlayerController::StaticClass();
    HUDClass = AMenuHUD::StaticClass();
}
