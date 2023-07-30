// Third Person Shooter, All Rights Reserved


#include "PickUps/AmmoPickup.h"
#include "Components/TPSHealthComponent.h"
#include "Components/WeaponComponent.h"

bool AAmmoPickup::GivePickupTo(APawn* PlayerPawn)
{
    const auto HealthComponent = GetTPSPlayerComponent<UTPSHealthComponent>(PlayerPawn);
    if (!HealthComponent || HealthComponent->IsDead()) return false;

    const auto WeaponComponent = GetTPSPlayerComponent<UWeaponComponent>(PlayerPawn);
    if (!WeaponComponent) return false;
    return WeaponComponent->TryToAddAmmo(WeaponType, ClipsAmount);
}
 