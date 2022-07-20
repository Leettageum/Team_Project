// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Item.h"
#include "Enum_Collection.h"
#include "Weapon.generated.h"

/**
 * 
 */
UCLASS()
class TEAM_PROJECT_API AWeapon : public AItem
{
	GENERATED_BODY()
	
public:
	AWeapon();

	void SetWeaponType(EWeaponType Type);
	void SetWeaponHand(EWeaponHand Kind);

	UPROPERTY(VisibleAnywhere, Category = Weapon)
		USkeletalMeshComponent* Weapon;

	EWeaponHand CurrentWeaponHand;
	EWeaponType CurrentWeaponType;

protected:

private:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Attack,
			meta = (AllowPrivateAccess = "true"))
		float AttackRange;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Attack,
		meta = (AllowPrivateAccess = "true"))
		float AttackDamageMin;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Attack,
		meta = (AllowPrivateAccess = "true"))
		float AttackDamageMax;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Attack,
		meta = (AllowPrivateAccess = "true"))
		float AttackModifierMin;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Attack,
		meta = (AllowPrivateAccess = "true"))
		float AttackModifierMax;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Weapon,
		meta = (AllowPrivateAccess = "true"))
		bool bBowEquip;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Weapon,
		meta = (AllowPrivateAccess = "true"))
		bool bTwoHandedEquip;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Weapon,
		meta = (AllowPrivateAccess = "true"))
		bool bOneHandedEquip;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Weapon,
		meta = (AllowPrivateAccess = "true"))
		bool bKnuckleEquip;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Weapon,
		meta = (AllowPrivateAccess = "true"))
		bool bFistWeapon;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Weapon,
		meta = (AllowPrivateAccess = "true"))
		bool bSwordWeapon;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Weapon,
		meta = (AllowPrivateAccess = "true"))
		bool bHammerWeapon;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Weapon,
		meta = (AllowPrivateAccess = "true"))
		bool bBowWeapon;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Motion,
		meta = (AllowPrivateAccess = "true"))
		bool bWeaponEquip;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Motion,
		meta = (AllowPrivateAccess = "true"))
		bool bWhereWeapon;

public:
	FORCEINLINE bool GetWeaponEquip() const { return bWeaponEquip; }
	FORCEINLINE bool GetWeaponWhere() const { return bWhereWeapon; }
	FORCEINLINE bool GetBowEquip() const { return bBowEquip; }
	FORCEINLINE bool GetTwoHandedEquip() const { return bTwoHandedEquip; }
	FORCEINLINE bool GetOneHandedEquip() const { return bOneHandedEquip; }
	FORCEINLINE bool GetKnuckleEquip() const { return bKnuckleEquip; }
	FORCEINLINE bool GetFistWeapon() const { return bFistWeapon; }
	FORCEINLINE bool GetSwordWeapon() const { return bSwordWeapon; }
	FORCEINLINE bool GetHammerWeapon() const { return bHammerWeapon; }
	FORCEINLINE bool GetBowWeapon() const { return bBowWeapon; }

};
