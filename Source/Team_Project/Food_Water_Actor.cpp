// Fill out your copyright notice in the Description page of Project Settings.


#include "Food_Water_Actor.h"

// Sets default values
AFood_Water_Actor::AFood_Water_Actor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFood_Water_Actor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFood_Water_Actor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

