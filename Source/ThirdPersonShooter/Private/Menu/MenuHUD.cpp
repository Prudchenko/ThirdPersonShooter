// Third Person Shooter, All Rights Reserved


#include "Menu/MenuHUD.h"
#include "UI/BaseWidget.h"

void AMenuHUD::BeginPlay()
{
    Super::BeginPlay();

    if (const auto MenuWidget = CreateWidget<UBaseWidget>(GetWorld(), MenuWidgetClass))
    {
        MenuWidget->AddToViewport();
        MenuWidget->Show();
    }
}
