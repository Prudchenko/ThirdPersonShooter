// Third Person Shooter, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "TPSBaseCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;

UCLASS()
class THIRDPERSONSHOOTER_API ATPSBaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ATPSBaseCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(VisibleAnywhere,BlueprintReadWrite, Category = "Components")
		USpringArmComponent* SpringArmComponent;
	UPROPERTY(VisibleAnywhere,BlueprintReadWrite, Category = "Components")
		UCameraComponent* CameraComponent;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
		bool isSprinting;
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
		bool isMovingForward = false;

	private:
    void MoveForward(float Value);
    void MoveRight(float Value);
    void LookUp(float Value);
    void LookRight(float Value);
    void StartSprint();
    void StopSprint();
};
