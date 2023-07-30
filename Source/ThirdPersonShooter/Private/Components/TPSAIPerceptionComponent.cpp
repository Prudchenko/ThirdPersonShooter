// Third Person Shooter, All Rights Reserved

#include "AIController.h"
#include "Components/TPSAIPerceptionComponent.h"
#include "Components/TPSHealthComponent.h"
#include "Perception/AISense_Sight.h"
#include "Perception/AISense_Damage.h"

AActor* UTPSAIPerceptionComponent::GetClosestEnemy() const
{
    TArray<AActor*> PercieveActors;
    GetCurrentlyPerceivedActors(UAISense_Sight::StaticClass(), PercieveActors);
    if (PercieveActors.Num() == 0)
    {
        GetCurrentlyPerceivedActors(UAISense_Damage::StaticClass(), PercieveActors);
        if (PercieveActors.Num() == 0) return nullptr;
    }

    const auto Controller = Cast<AAIController>(GetOwner());
    if (!Controller) return nullptr;

    const auto Pawn = Controller->GetPawn();
    if (!Pawn) return nullptr;

    float BestDistance = MAX_FLT;
    AActor* BestPawn = nullptr;
    for (const auto PercieveActor : PercieveActors)
    {
        const auto HealthComponent = GetTPSPlayerComponent<UTPSHealthComponent>(PercieveActor);

        const auto PercievePawn = Cast<APawn>(PercieveActor);
        const auto bAreEnemies = PercievePawn && AreEnemies(Controller, PercievePawn->Controller);

        if (HealthComponent && !HealthComponent->IsDead() /*&& bAreEnemies*/)
        {
            const auto CurrentDistance = (PercieveActor->GetActorLocation() - Pawn->GetActorLocation()).Size();
            if (CurrentDistance < BestDistance)
            {
                BestDistance = CurrentDistance;
                BestPawn = PercieveActor;
            }
        }
    }

    return BestPawn;
}