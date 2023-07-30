// Third Person Shooter, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "EnvironmentQuery/EnvQueryTest.h"
#include "PickUpEnvQueryTest.generated.h"

/**
 * 
 */
UCLASS()
class THIRDPERSONSHOOTER_API UPickUpEnvQueryTest : public UEnvQueryTest
{
	GENERATED_BODY()

	public:
    UPickUpEnvQueryTest(const FObjectInitializer& ObjectInitializer);
    virtual void RunTest(FEnvQueryInstance& QueryInstance) const override;
};
