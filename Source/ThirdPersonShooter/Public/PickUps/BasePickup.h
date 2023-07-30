// Third Person Shooter, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Player/TPSPlayerState.h"
#include "BasePickup.generated.h"

class USphereComponent;
class USoundCue;

UCLASS()
class THIRDPERSONSHOOTER_API ABasePickup : public AActor
{
	GENERATED_BODY()
	
public:
    ABasePickup();

protected:
    UPROPERTY(VisibleAnywhere, Category = "Pickup")
    USphereComponent* CollisionComponent;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pickup")
    float RespawnTime = 60.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sound")
    USoundCue* PickupTakenSound;

    virtual void BeginPlay() override;
    virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;
    virtual void NotifyActorEndOverlap(AActor* OtherActor) override;

public:
    virtual void Tick(float DeltaTime) override;
    bool CouldBeTaken() const;

    template <typename T>
    static T* GetTPSPlayerComponent(AActor* SomeActor)
    {
        if (!SomeActor) return nullptr;

        const auto Component = SomeActor->GetComponentByClass(T::StaticClass());
        return Cast<T>(Component);
    }

private:
    float RotationYaw = 0.0f;
    FTimerHandle RespawnTimerHandle;

    UPROPERTY()
    TArray<APawn*> OverlappingPawns;

    virtual bool GivePickupTo(APawn* PlayerPawn);

    void PickupWasTaken();
    void Respawn();
    void GenerateRotationYaw();
};
