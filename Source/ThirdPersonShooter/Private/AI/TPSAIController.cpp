// Third Person Shooter, All Rights Reserved


#include "AI/TPSAIController.h"
#include "AI/AICharacter.h"
#include "Components/TPSAIPerceptionComponent.h"
#include "Components/RespawnComponent.h"
#include "BehaviorTree/BlackboardComponent.h"

ATPSAIController::ATPSAIController()
{
    TPSAIPerceptionComponent = CreateDefaultSubobject<UTPSAIPerceptionComponent>("TPSPerceptionComponent");
    SetPerceptionComponent(*TPSAIPerceptionComponent);

    RespawnComponent = CreateDefaultSubobject<URespawnComponent>("RespawnComponent");

    bWantsPlayerState = true;
}

void ATPSAIController::OnPossess(APawn* InPawn)
{
    Super::OnPossess(InPawn);

    if (const auto CharacterTemp = Cast<AAICharacter>(InPawn))
    {
        RunBehaviorTree(CharacterTemp->BehaviorTreeAsset);
    }
}

void ATPSAIController::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    SetFocus(GetFocusOnActor());
}

AActor* ATPSAIController::GetFocusOnActor() const
{
    if (!GetBlackboardComponent()) return nullptr;
    return Cast<AActor>(GetBlackboardComponent()->GetValueAsObject(FocusOnKeyName));
}
