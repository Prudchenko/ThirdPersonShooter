// Third Person Shooter, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTDecorator.h"
#include "AmmoDecorator.generated.h"

class ABaseWeapon;

UCLASS()
class THIRDPERSONSHOOTER_API UAmmoDecorator : public UBTDecorator
{
	GENERATED_BODY()

	public:
    UAmmoDecorator();
    template <typename T>
    static T* GetTPSPlayerComponent(AActor* SomeActor)
    {
        if (!SomeActor) return nullptr;

        const auto Component = SomeActor->GetComponentByClass(T::StaticClass());
        return Cast<T>(Component);
    }

protected:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
    TSubclassOf<ABaseWeapon> WeaponType;

    virtual bool CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const override;
};
