// Third Person Shooter, All Rights Reserved


#include "TPSBaseCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"

// Sets default values
ATPSBaseCharacter::ATPSBaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CameraComponent = CreateDefaultSubobject<UCameraComponent>("CameraComponent");
    CameraComponent->SetupAttachment(GetRootComponent());
}

// Called when the game starts or when spawned
void ATPSBaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATPSBaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATPSBaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &ATPSBaseCharacter::MoveForward);
    PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &ATPSBaseCharacter::MoveRight);
}

void ATPSBaseCharacter::MoveForward(float Value) 
{
    AddMovementInput(GetActorForwardVector(), Value);
}


void ATPSBaseCharacter::MoveRight(float Value) 
{
    AddMovementInput(GetActorRightVector(), Value);
}

