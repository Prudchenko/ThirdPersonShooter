// Third Person Shooter, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "ChangeWeaponService.generated.h"

/**
 * 
 */
UCLASS()
class THIRDPERSONSHOOTER_API UChangeWeaponService : public UBTService
{
	GENERATED_BODY()

	public:
    UChangeWeaponService();

    template <typename T>
    static T* GetTPSPlayerComponent(AActor* SomeActor)
    {
        if (!SomeActor) return nullptr;

        const auto Component = SomeActor->GetComponentByClass(T::StaticClass());
        return Cast<T>(Component);
    }

protected:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI", meta = (ClampMin = "0.0", ClampMax = "1.0"))
    float Probability = 0.3f;

    virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
};
