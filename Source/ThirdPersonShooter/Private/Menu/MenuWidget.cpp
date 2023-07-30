// Third Person Shooter, All Rights Reserved


#include "Menu/MenuWidget.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Components/HorizontalBox.h"
#include "Menu/LevelItemWidget.h"
#include "Sound/SoundCue.h"

DEFINE_LOG_CATEGORY_STATIC(LogMenuWidget, All, All);

void UMenuWidget::NativeOnInitialized()
{
    Super::NativeOnInitialized();

    if (StartGameButton)
    {
        StartGameButton->OnClicked.AddDynamic(this, &UMenuWidget::OnStartGame);
    }

    if (QuitGameButton)
    {
        QuitGameButton->OnClicked.AddDynamic(this, &UMenuWidget::OnQuitGame);
    }

    InitLevelItems();
}

void UMenuWidget::InitLevelItems()
{
    const auto TPSGameInstance = GetTPSGameInstance();
    if (!TPSGameInstance) return;
    
    if (!LevelItemsBox) return;
    LevelItemsBox->ClearChildren();

    for (auto LevelData : TPSGameInstance->GetLevelsData())
    {
        const auto LevelItemWidget = CreateWidget<ULevelItemWidget>(GetWorld(), LevelItemWidgetClass);
        if (!LevelItemWidget) continue;

        LevelItemWidget->SetLevelData(LevelData);
        LevelItemWidget->OnLevelSelected.AddUObject(this, &UMenuWidget::OnLevelSelected);

        LevelItemsBox->AddChild(LevelItemWidget);
        LevelItemWidgets.Add(LevelItemWidget);
    }

    if (TPSGameInstance->GetStartupLevelData().LevelName.IsNone())
    {
        OnLevelSelected(TPSGameInstance->GetLevelsData()[0]);
    }
    else
    {
        OnLevelSelected(TPSGameInstance->GetStartupLevelData());
    }
}

void UMenuWidget::OnLevelSelected(const FLevelData& Data)
{
    const auto TPSGameInstance = GetTPSGameInstance();
    if (!TPSGameInstance) return;

    TPSGameInstance->SetStartupLevelData(Data);

    for (auto LevelItemWidget : LevelItemWidgets)
    {
        if (LevelItemWidget)
        {
            const auto IsSelected = Data.LevelName == LevelItemWidget->GetLevelData().LevelName;
            LevelItemWidget->SetSelected(IsSelected);
        }
    }
}

void UMenuWidget::OnStartGame()
{
    PlayAnimation(HideAnimation);
    UGameplayStatics::PlaySound2D(GetWorld(), StartGameSound);
}

void UMenuWidget::OnAnimationFinished_Implementation(const UWidgetAnimation* Animation)
{
    if (Animation != HideAnimation) return;

    const auto TPSGameInstance = GetTPSGameInstance();
    if (!TPSGameInstance) return;

    UGameplayStatics::OpenLevel(this, TPSGameInstance->GetStartupLevelData().LevelName);
}

void UMenuWidget::OnQuitGame()
{
    UKismetSystemLibrary::QuitGame(this, GetOwningPlayer(), EQuitPreference::Quit, true);
}

UTPSGameInstance* UMenuWidget::GetTPSGameInstance() const
{
    if (!GetWorld()) return nullptr;
    return GetWorld()->GetGameInstance<UTPSGameInstance>();
}
