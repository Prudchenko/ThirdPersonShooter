// Third Person Shooter, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "PickUps/BasePickup.h"
#include "AmmoPickup.generated.h"


class ABaseWeapon;

UCLASS()
class THIRDPERSONSHOOTER_API AAmmoPickup : public ABasePickup
{
	GENERATED_BODY()

	protected:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pickup", meta = (ClampMin = "1", ClampMax = "10"))
    int32 ClipsAmount = 10;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pickup")
    TSubclassOf<ABaseWeapon> WeaponType;

private:
    virtual bool GivePickupTo(APawn* PlayerPawn) override;
};
