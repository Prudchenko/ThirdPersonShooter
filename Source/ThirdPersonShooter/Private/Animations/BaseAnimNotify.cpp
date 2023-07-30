// Third Person Shooter, All Rights Reserved


#include "Animations/BaseAnimNotify.h"


void UBaseAnimNotify::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
    OnNotified.Broadcast(MeshComp);
    Super::Notify(MeshComp, Animation);
}