// Third Person Shooter, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "PickUps/BasePickup.h"
#include "HealthPickup.generated.h"

/**
 * 
 */
UCLASS()
class THIRDPERSONSHOOTER_API AHealthPickup : public ABasePickup
{
	GENERATED_BODY()

protected:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pickup", meta = (ClampMin = "1.0", ClampMax = "100.0"))
    float HealthAmount = 50.0f;

private:
    virtual bool GivePickupTo(APawn* PlayerPawn) override;
};
