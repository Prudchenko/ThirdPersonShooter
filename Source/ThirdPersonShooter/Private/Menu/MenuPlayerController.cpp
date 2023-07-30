// Third Person Shooter, All Rights Reserved


#include "Menu/MenuPlayerController.h"

void AMenuPlayerController::BeginPlay()
{
    Super::BeginPlay();

    SetInputMode(FInputModeUIOnly());
    bShowMouseCursor = true;
}