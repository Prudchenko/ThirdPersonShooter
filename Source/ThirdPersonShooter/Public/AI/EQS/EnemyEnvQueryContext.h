// Third Person Shooter, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "EnvironmentQuery/EnvQueryContext.h"
#include "EnemyEnvQueryContext.generated.h"

/**
 * 
 */
UCLASS()
class THIRDPERSONSHOOTER_API UEnemyEnvQueryContext : public UEnvQueryContext
{
	GENERATED_BODY()

public:
    virtual void ProvideContext(FEnvQueryInstance& QueryInstance, FEnvQueryContextData& ContextData) const override;

protected:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
    FName EnemyActorKeyName = "EnemyActor";
};
