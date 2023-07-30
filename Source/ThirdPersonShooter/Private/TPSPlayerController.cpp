// Third Person Shooter, All Rights Reserved


#include "TPSPlayerController.h"
#include "Components/RespawnComponent.h"
#include "TPSGameInstance.h"

ATPSPlayerController::ATPSPlayerController()
{
    RespawnComponent = CreateDefaultSubobject<URespawnComponent>("RespawnComponent");
}

void ATPSPlayerController::BeginPlay()
{
    Super::BeginPlay();

    if (GetWorld())
    {
        if (const auto GameMode = Cast<ATPSGameModeBase>(GetWorld()->GetAuthGameMode()))
        {
            GameMode->OnMatchStateChanged.AddUObject(this, &ATPSPlayerController::OnMatchStateChanged);
        }
    }
}

void ATPSPlayerController::OnMatchStateChanged(EMatchState State)
{
    if (State == EMatchState::InProgress)
    {
        SetInputMode(FInputModeGameOnly());
        bShowMouseCursor = false;
    }
    else
    {
        SetInputMode(FInputModeUIOnly());
        bShowMouseCursor = true;
    }
}

void ATPSPlayerController::OnPossess(APawn* InPawn)
{
    Super::OnPossess(InPawn);

    OnNewPawn.Broadcast(InPawn);
}

void ATPSPlayerController::SetupInputComponent()
{
    Super::SetupInputComponent();
    if (!InputComponent) return;

    InputComponent->BindAction("PauseGame", IE_Pressed, this, &ATPSPlayerController::OnPauseGame);
    InputComponent->BindAction("Mute", IE_Pressed, this, &ATPSPlayerController::OnMuteSound);
}

void ATPSPlayerController::OnPauseGame()
{
    if (!GetWorld() || !GetWorld()->GetAuthGameMode()) return;

    GetWorld()->GetAuthGameMode()->SetPause(this);
}

void ATPSPlayerController::OnMuteSound()
{
    if (!GetWorld()) return;

    const auto TPSGameInstace = GetWorld()->GetGameInstance<UTPSGameInstance>();
    if (!TPSGameInstace) return;

    TPSGameInstace->ToggleVolume();
}
