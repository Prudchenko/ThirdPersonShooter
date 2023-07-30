// Third Person Shooter, All Rights Reserved


#include "AI/Decorators/HealthDecorator.h"
#include "AIController.h"
#include "Components/TPSHealthComponent.h"

UHealthDecorator::UHealthDecorator()
{
    NodeName = "Health Percent";
}

bool UHealthDecorator::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
    const auto Controller = OwnerComp.GetAIOwner();
    if (!Controller) return false;

    const auto HealthComponent = GetTPSPlayerComponent<UTPSHealthComponent>(Controller->GetPawn());
    if (!HealthComponent || HealthComponent->IsDead()) return false;

    return HealthComponent->GetHealthPercent() <= HealthPercent;
}
