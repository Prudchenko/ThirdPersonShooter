// Third Person Shooter, All Rights Reserved


#include "AI/Services/ChangeWeaponService.h"
#include "Components/WeaponComponent.h"
#include "AIController.h"

UChangeWeaponService::UChangeWeaponService()
{
    NodeName = "Change Weapon";
}

void UChangeWeaponService::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
    if (const auto Controller = OwnerComp.GetAIOwner())
    {
        const auto WeaponComponent = GetTPSPlayerComponent<UWeaponComponent>(Controller->GetPawn());
        if (WeaponComponent && Probability > 0 && FMath::FRand() <= Probability)
        {
            WeaponComponent->NextWeapon();
        }
    }

    Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);
}
