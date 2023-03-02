// Fill out your copyright notice in the Description page of Project Settings.


#include "SteelBeamFurnace.h"

// Sets default values for this component's properties
USteelBeamFurnace::USteelBeamFurnace()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void USteelBeamFurnace::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void USteelBeamFurnace::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
	if (CoalInbound >= 1 && IronInbound >= 1 && SteelQuantity < SteelMaxQuantity) {
		SteelProductionTime += DeltaTime;

		if (SteelProductionTime >= MaxSteelProductionTime) {
			SteelQuantity += ProductionCapability;
			CoalInbound -= ProductionCapability;
			IronInbound -= ProductionCapability;
			SteelProductionTime = 0;
		}
	}
}

