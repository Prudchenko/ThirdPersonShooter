// Third Person Shooter, All Rights Reserved


#include "UI/GoToMenuWidget.h"
#include "Components/Button.h"
#include "TPSGameInstance.h"
#include "Kismet/GameplayStatics.h"

DEFINE_LOG_CATEGORY_STATIC(LogGoToMenuWidget, All, All);

void UGoToMenuWidget::NativeOnInitialized()
{
    Super::NativeOnInitialized();

    if (GoToMenuButton)
    {
        GoToMenuButton->OnClicked.AddDynamic(this, &UGoToMenuWidget::OnGoToMenu);
    }
}

void UGoToMenuWidget::OnGoToMenu()
{
    if (!GetWorld()) return;

    const auto TPSGameInstance = GetWorld()->GetGameInstance<UTPSGameInstance>();
    if (!TPSGameInstance) return;

    if (TPSGameInstance->GetMenuLevelName().IsNone()) return;

    UGameplayStatics::OpenLevel(this, TPSGameInstance->GetMenuLevelName());
}