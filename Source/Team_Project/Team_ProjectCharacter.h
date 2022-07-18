// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Enum_Collection.h"
#include "Team_ProjectCharacter.generated.h"

UCLASS(config=Game)
class ATeam_ProjectCharacter : public ACharacter
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, Category = "CharacterInventory")
	class UInventoryComponent* InventoryComponent;

	
public:
	ATeam_ProjectCharacter();

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	void LeftHand();
	void RightHand();

	void InputTimeCheck();
	void CameraOption();

	UFUNCTION()
		void SetViewType(EViewType ViewType);
	
	UFUNCTION()
		void ViewChange();

	UFUNCTION()
		void StanceChange();

	UFUNCTION()
		void SetStanceType(EStance StanceType);

	UFUNCTION()
		void SetStanding(EStanding StandingType);

	UFUNCTION()
		void StandingChange();

public:
	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Input)
	float TurnRateGamepad;

	// Widgetclass to spawn for the heads up display.
	UPROPERTY(EditAnywhere)
	TSubclassOf<class UBarWidget> PlayerWidgetClass;

	// The Widget instance that we are using as our HUD.
	UPROPERTY()
	class UBarWidget* PlayerWidget;

	EViewType CurrentViewMode;
	EStance CurrentStanceMode;
	EStanding CurrentStanding;
	EWeaponType CurrentWeapon;
	EWeaponHand CurrentHandWeapon;
	bool bThirdPersonView;
	float BareHandDamage;//맨손공격력
	float inputTime;
	float PCInputTime;

protected:

	/** Called for forwards/backward input */
	void MoveForward(float Value);

	/** Called for side to side input */
	void MoveRight(float Value);

	/** 
	 * Called via input to turn at a given rate. 
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void TurnAtRate(float Rate);

	/**
	 * Called via input to turn look up/down at a given rate. 
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void LookUpAtRate(float Rate);

	/** Handler for when a touch input begins. */
	void TouchStarted(ETouchIndex::Type FingerIndex, FVector Location);

	/** Handler for when a touch input stops. */
	void TouchStopped(ETouchIndex::Type FingerIndex, FVector Location);

	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	// End of APawn interface

	void Interact();


private:
	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class USpringArmComponent* FirstPersonCameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class UCameraComponent* FirstPersonFollowCamera;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class USpringArmComponent* ThirdPersonCameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class UCameraComponent* ThirdPersonFollowCamera;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Character, meta = (AllowPrivateAccess = "true"))
		class AMKKS_PlayerController* MKKS_Controller;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Character, meta = (AllowPrivateAccess = "true"))
		class UMKKS_PlayerAnimInstance* PlayerAnim;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Combat, meta = (AllowPrivateAccess = "true"))
		class UAnimMontage* LeftPunchingMontage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Combat, meta = (AllowPrivateAccess = "true"))
		class UAnimMontage* RightPunchingMontage;

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Motion,
		meta = (AllowPrivateAccess = "true"))
	bool bDoAttacking;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Motion,
		meta = (AllowPrivateAccess = "true"))
	bool bCrouching;//웅크리고있느냐

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Motion,
		meta = (AllowPrivateAccess = "true"))
	bool bSitting;//앉아있느냐

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Motion,
		meta = (AllowPrivateAccess = "true"))
	bool bLayingDown;//누워있느냐?

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Motion,
		meta = (AllowPrivateAccess = "true"))
	bool bCombatState;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Motion,
		meta = (AllowPrivateAccess = "true"))
	bool bLeftHandAction;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Motion,
		meta = (AllowPrivateAccess = "true"))
	bool bRightHandAction;


public:
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetFirstPersonCameraBoom() const { return FirstPersonCameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFirstPersonFollowCamera() const { return FirstPersonFollowCamera; }

	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetThirdPersonCameraBoom() const { return ThirdPersonCameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetThirdPersonFollowCamera() const { return ThirdPersonFollowCamera; }

	FORCEINLINE bool GetSitting() const { return bSitting; }

	FORCEINLINE bool GetCrouching() const { return bCrouching; }

	FORCEINLINE bool GetLyingDown() const { return bLayingDown; }

	FORCEINLINE bool GetCombatState() const { return bCombatState; }

	FORCEINLINE bool GetLeftHandAction() const { return bLeftHandAction; }

	FORCEINLINE bool GetRightHandAction() const { return bRightHandAction; }

};

