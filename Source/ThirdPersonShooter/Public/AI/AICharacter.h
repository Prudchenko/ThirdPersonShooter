// Third Person Shooter, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "TPSBaseCharacter.h"
#include "AICharacter.generated.h"

class UBehaviorTree;
class UWidgetComponent;

UCLASS()
class THIRDPERSONSHOOTER_API AAICharacter : public ATPSBaseCharacter
{
	GENERATED_BODY()
public:
    AAICharacter(const FObjectInitializer& ObjInit);

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "AI")
    UBehaviorTree* BehaviorTreeAsset;

    virtual void Tick(float DeltaTime) override;

protected:
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
    UWidgetComponent* HealthWidgetComponent;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Health")
    float HealthVisibilityDistance = 1000.0f;

    virtual void BeginPlay() override;

    virtual void OnDeath() override;
    virtual void OnHealthChanged(float Health, float HealthDelta) override;

private:
    void UpdateHealthWidgetVisibility();
};
