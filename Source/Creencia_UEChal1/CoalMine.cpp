// Fill out your copyright notice in the Description page of Project Settings.


#include "CoalMine.h"

// Sets default values for this component's properties
UCoalMine::UCoalMine()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UCoalMine::BeginPlay()
{
	Super::BeginPlay();

	// ...
	CoalProductionTime = 0;
	
}

// Called every frame
void UCoalMine::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
	if (CoalQuantity < CoalMaxQuantity) {
		CoalProductionTime = CoalProductionTime + DeltaTime;

		if (CoalProductionTime >= MaxCoalProductionTime) {
			CoalQuantity += ProductionCapability;
			CoalProductionTime = 0;
		}
	}
}



