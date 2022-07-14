// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "MKKS_PlayerAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class TEAM_PROJECT_API UMKKS_PlayerAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:


	UFUNCTION(BlueprintCallable)
		void UpdateAnimationProperties(float DeltaTime);

	virtual void NativeInitializeAnimation() override;

private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Movement,
		meta = (AllowPrivateAccess = "true"))
		class ATeam_ProjectCharacter* Team_ProjectCharacter;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Movement,
		meta = (AllowPrivateAccess = "true"))
		float Speed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Movement,
		meta = (AllowPrivateAccess = "true"))
		bool bIsInAir;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Movement,
		meta = (AllowPrivateAccess = "true"))
		bool bIsSprint;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Movement,
		meta = (AllowPrivateAccess = "true"))
		bool bCombatState;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Movement,
		meta = (AllowPrivateAccess = "true"))
		bool bSitting;//�ɾ��ִ���

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Movement,
		meta = (AllowPrivateAccess = "true"))
		bool bLyingDown;//�����ִ���?

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Movement,
		meta = (AllowPrivateAccess = "true"))
		bool bIsAccelerating;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Movement,
		meta = (AllowPrivateAccess = "true"))
		float MovementOffsetYaw;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Movement,
		meta = (AllowPrivateAccess = "true"))
		float LastMovementOffsetYaw;//��ž���� �ٷ� ���� �������� OffsetYaw ��

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Movement,
		meta = (AllowPrivateAccess = "true"))
		float MoveForwardBack;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Movement,
		meta = (AllowPrivateAccess = "true"))
		float MoveRightLeft;

public:

};
