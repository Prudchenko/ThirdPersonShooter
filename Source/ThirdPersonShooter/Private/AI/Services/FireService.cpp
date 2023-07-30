// Third Person Shooter, All Rights Reserved


#include "AI/Services/FireService.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Components/WeaponComponent.h"

UFireService::UFireService()
{
    NodeName = "Fire";
}

void UFireService::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
    const auto Blackboard = OwnerComp.GetBlackboardComponent();
    const auto HasAim = Blackboard && Blackboard->GetValueAsObject(EnemyActorKey.SelectedKeyName);

    if (const auto Controller = OwnerComp.GetAIOwner())
    {
        if (const auto WeaponComponent = GetTPSPlayerComponent<UWeaponComponent>(Controller->GetPawn()))
        {
            HasAim ? WeaponComponent->StartFire() : WeaponComponent->StopFire();
        }
    }

    Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);
}
