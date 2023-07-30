// Third Person Shooter, All Rights Reserved


#include "PickUps/HealthPickup.h"
#include "Components/TPSHealthComponent.h"

bool AHealthPickup::GivePickupTo(APawn* PlayerPawn)
{
    const auto HealthComponent = GetTPSPlayerComponent<UTPSHealthComponent>(PlayerPawn);
    if (!HealthComponent) return false;
    return HealthComponent->TryToAddHealth(HealthAmount);
}
