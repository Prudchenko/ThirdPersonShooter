// Third Person Shooter, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Weapon/BaseWeapon.h"
#include "Launcher.generated.h"

class ARocket;
class USoundCue;

UCLASS()
class THIRDPERSONSHOOTER_API ALauncher : public ABaseWeapon
{
	GENERATED_BODY()
public:
    virtual void StartFire() override;

protected:
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon")
    TSubclassOf<ARocket> ProjectileClass;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Sound")
    USoundCue* NoAmmoSound;

    virtual void MakeShot() override;
};
