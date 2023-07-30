// Third Person Shooter, All Rights Reserved


#include "UI/GameHUD.h"
#include "Engine/Canvas.h"
#include "UI/BaseWidget.h"

void AGameHUD::DrawHUD()
{
    Super::DrawHUD(); 
}

void AGameHUD::BeginPlay()
{
    Super::BeginPlay();

    GameWidgets.Add(EMatchState::InProgress, CreateWidget<UBaseWidget>(GetWorld(), PlayerHUDWidgetClass));
    GameWidgets.Add(EMatchState::Pause, CreateWidget<UBaseWidget>(GetWorld(), PauseWidgetClass));
    GameWidgets.Add(EMatchState::GameOver, CreateWidget<UBaseWidget>(GetWorld(), GameOverWidgetClass));

    for (auto GameWidgetPair : GameWidgets)
    {
        const auto GameWidget = GameWidgetPair.Value;
        if (!GameWidget) continue;

        GameWidget->AddToViewport();
        GameWidget->SetVisibility(ESlateVisibility::Hidden);
    }

    if (GetWorld())
    {
        const auto GameMode = Cast<ATPSGameModeBase>(GetWorld()->GetAuthGameMode());
        if (GameMode)
        {
            GameMode->OnMatchStateChanged.AddUObject(this, &AGameHUD::OnMatchStateChanged);
        }
    }
}

void AGameHUD::OnMatchStateChanged(EMatchState State)
{
    if (CurrentWidget)
    {
        CurrentWidget->SetVisibility(ESlateVisibility::Hidden);
    }

    if (GameWidgets.Contains(State))
    {
        CurrentWidget = GameWidgets[State];
    }

    if (CurrentWidget)
    {
        CurrentWidget->SetVisibility(ESlateVisibility::Visible);
        CurrentWidget->Show();
    }
}
