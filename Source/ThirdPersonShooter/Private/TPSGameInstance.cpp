// Third Person Shooter, All Rights Reserved


#include "TPSGameInstance.h"
#include "SoundFunctionLibrary.h"

void UTPSGameInstance::ToggleVolume()
{
    USoundFunctionLibrary::ToggleSoundClassVolume(MasterSoundClass);
}
