// Third Person Shooter, All Rights Reserved

#include "Components/TPSCharacterMovementComponent.h"
#include "TPSBaseCharacter.h"

float UTPSCharacterMovementComponent::GetMaxSpeed() const
{
    const float MaxSpeed = Super::GetMaxSpeed();
    const ATPSBaseCharacter* Player = Cast<ATPSBaseCharacter>(GetPawnOwner());
    return Player && Player->IsRunning() ? MaxSpeed * RunModifier : MaxSpeed;
}
