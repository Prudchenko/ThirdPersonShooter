// Third Person Shooter, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "TPSBaseCharacter.generated.h"

class UTPSHealthComponent;
class UWeaponComponent;
class USoundCue;

UCLASS()
class THIRDPERSONSHOOTER_API ATPSBaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ATPSBaseCharacter(const FObjectInitializer& ObjInit);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
    UPROPERTY(VisibleAnywhere,BlueprintReadWrite, Category = "Components")
        UTPSHealthComponent* HealthComponent;
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
        UWeaponComponent* WeaponComponent;
    UPROPERTY(EditDefaultsOnly, Category = "Animation")
        UAnimMontage* DeathAnimMontage;
    UPROPERTY(EditDefaultsOnly, Category = "Damage")
        float LifeSpanOnDeath = 5.0f;

    UPROPERTY(EditDefaultsOnly, Category = "Damage")
    FVector2D LandedDamageVelocity = FVector2D(900.0f, 1200.0f);

    UPROPERTY(EditDefaultsOnly, Category = "Damage")
    FVector2D LandedDamage = FVector2D(10.0f, 100.0f);

    UPROPERTY(EditDefaultsOnly, Category = "Damage")
    FName MaterialColorName = "Paint Color";

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Sound")
    USoundCue* DeathSound;

    virtual void OnDeath();
    virtual void OnHealthChanged(float Health, float HealthDelta);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
    virtual bool IsRunning() const;

    UFUNCTION(BlueprintCallable)
    float GetMovementDirection() const;

    void SetPlayerColor(const FLinearColor& Color);
	private:

    UFUNCTION()
    void OnGroundLanded(const FHitResult& Hit);
    
};
