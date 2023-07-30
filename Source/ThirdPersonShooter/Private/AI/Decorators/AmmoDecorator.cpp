// Third Person Shooter, All Rights Reserved


#include "AI/Decorators/AmmoDecorator.h"
#include "AIController.h"
#include "Components/WeaponComponent.h"

UAmmoDecorator::UAmmoDecorator()
{
    NodeName = "Need Ammo";
}

bool UAmmoDecorator::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
    const auto Controller = OwnerComp.GetAIOwner();
    if (!Controller) return false;

    const auto WeaponComponent = GetTPSPlayerComponent<UWeaponComponent>(Controller->GetPawn());
    if (!WeaponComponent) return false;

    return WeaponComponent->NeedAmmo(WeaponType);
}
