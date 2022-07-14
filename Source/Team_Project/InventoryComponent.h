// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InventoryComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnInventoryUpdated);


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TEAM_PROJECT_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInventoryComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	/*
	UPROPERTY(EditDefaultsOnly, Category = "Inventory")
	int32 MaxItemsInInventory;
		
	UPROPERTY(BlueprintReadOnly, Category = "CharacterInventory")
	TArray<AActor*> Items;
	*/

public:
	/*
	void AddItemToInventory(AActor* Item);

	// UPROPERTY(BlueprintReadOnly, Category = "CharacterInventory")

	void DropItem(AActor* Item);

	UFUNCTION(BlueprintCallable, Category = "CharacterInventory")
	TArray<AActor*>GetInventoryItems() const { return Items; }
	*/

	bool AddItem(class AItem* Item);
	bool RemoveItem(class AItem* Item);

	UPROPERTY(EditDefaultsOnly, Instanced)
		TArray<class AItem*> DefaultItems;

	UPROPERTY(EditDefaultsOnly, Category = "Inventory")
		int32 Capacity;

	UPROPERTY(BlueprintAssignable, Category = "Inventory")
	FOnInventoryUpdated OnInventoryUpdated;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Items")
		TArray<class AItem*> Items;
};