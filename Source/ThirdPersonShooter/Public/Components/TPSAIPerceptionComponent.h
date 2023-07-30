// Third Person Shooter, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Perception/AIPerceptionComponent.h"
#include "Player/TPSPlayerState.h"
#include "TPSAIPerceptionComponent.generated.h"

/**
 * 
 */
UCLASS()
class THIRDPERSONSHOOTER_API UTPSAIPerceptionComponent : public UAIPerceptionComponent
{
	GENERATED_BODY()

public:
    AActor* GetClosestEnemy() const;

    template <typename T>
    static T* GetTPSPlayerComponent(AActor* SomeActor)
    {
        if (!SomeActor) return nullptr;

        const auto Component = SomeActor->GetComponentByClass(T::StaticClass());
        return Cast<T>(Component);
    }

    bool static AreEnemies(AController* Controller1, AController* Controller2)
    {
        if (!Controller1 || !Controller2 || Controller1 == Controller2) return false;

        const auto PlayerState1 = Cast<ATPSPlayerState>(Controller1->PlayerState);
        const auto PlayerState2 = Cast<ATPSPlayerState>(Controller2->PlayerState);

        return PlayerState1 && PlayerState2 && PlayerState1->GetTeamID() != PlayerState2->GetTeamID();
    }
};
