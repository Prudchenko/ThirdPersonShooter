// Third Person Shooter, All Rights Reserved


#include "TPSBaseCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
ATPSBaseCharacter::ATPSBaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>("SpringArmComponent");
    SpringArmComponent->SetupAttachment(GetRootComponent());
    SpringArmComponent->bUsePawnControlRotation = true;

	CameraComponent = CreateDefaultSubobject<UCameraComponent>("CameraComponent");
    CameraComponent->SetupAttachment(SpringArmComponent);
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
    PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &ATPSBaseCharacter::LookUp);
    PlayerInputComponent->BindAxis(TEXT("LookRight"), this, &ATPSBaseCharacter::LookRight);
    PlayerInputComponent->BindAction(TEXT("Jump"), IE_Pressed, this, &ATPSBaseCharacter::Jump);
    PlayerInputComponent->BindAction(TEXT("Sprint"), IE_Pressed, this, &ATPSBaseCharacter::StartSprint);
    PlayerInputComponent->BindAction(TEXT("Sprint"), IE_Released, this, &ATPSBaseCharacter::StopSprint);
}

void ATPSBaseCharacter::MoveForward(float Value) 
{
    isMovingForward = Value > 0;
    AddMovementInput(GetActorForwardVector(), Value);
}


void ATPSBaseCharacter::MoveRight(float Value) 
{
    AddMovementInput(GetActorRightVector(), Value);
}

void ATPSBaseCharacter::LookUp(float Value) 
{
    AddControllerPitchInput(Value);
}

void ATPSBaseCharacter::LookRight(float Value) 
{
    AddControllerYawInput(Value);
}

void ATPSBaseCharacter::StartSprint() 
{
    if (isMovingForward)
    {
        isSprinting = true;
    }
}

void ATPSBaseCharacter::StopSprint()
{
    isSprinting = false;
}

