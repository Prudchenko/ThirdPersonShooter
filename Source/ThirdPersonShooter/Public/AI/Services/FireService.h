// Third Person Shooter, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "FireService.generated.h"

/**
 * 
 */
UCLASS()
class THIRDPERSONSHOOTER_API UFireService : public UBTService
{
	GENERATED_BODY()

public:
    UFireService();

    template <typename T>
    static T* GetTPSPlayerComponent(AActor* SomeActor)
    {
        if (!SomeActor) return nullptr;

        const auto Component = SomeActor->GetComponentByClass(T::StaticClass());
        return Cast<T>(Component);
    }

protected:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
    FBlackboardKeySelector EnemyActorKey;

    virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
};
