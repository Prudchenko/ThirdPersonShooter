// Third Person Shooter, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TPSAIPerceptionComponent.h"
#include "TPSAIController.generated.h"

class UTPSAIPerceptionComponent;
class URespawnComponent;

UCLASS()
class THIRDPERSONSHOOTER_API ATPSAIController : public AAIController
{
	GENERATED_BODY()

	public:
    ATPSAIController();

protected:
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
    UTPSAIPerceptionComponent* TPSAIPerceptionComponent;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
    URespawnComponent* RespawnComponent;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
    FName FocusOnKeyName = "EnemyActor";

    virtual void OnPossess(APawn* InPawn) override;
    virtual void Tick(float DeltaTime) override;

private:
    AActor* GetFocusOnActor() const;
};
