// Third Person Shooter, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "RespawnComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class THIRDPERSONSHOOTER_API URespawnComponent : public UActorComponent
{
	GENERATED_BODY()

public:
    URespawnComponent();

    void Respawn(int32 RespawnTime);
    int32 GetRespawnCountDown() const { return RespawnCountDown; }
    bool IsRespawnInProgress() const;

private:
    FTimerHandle RespawnTimerHandle;
    int32 RespawnCountDown = 0;

    void RespawnTimerUpdate();
};
