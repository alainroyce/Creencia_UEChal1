// Fill out your copyright notice in the Description page of Project Settings.


#include "SewingMachine.h"

// Sets default values for this component's properties
USewingMachine::USewingMachine()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	
	// ...
}


// Called when the game starts
void USewingMachine::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

// Called every frame
void USewingMachine::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
	if (LumberInbound >= 1 && SteelInbound >= 1) {
		MachineProductionTime += DeltaTime;

		if (MachineProductionTime >= MaxMachineProductionTime) {
			MachineQuantity += ProductionCapability;
			LumberInbound -= ProductionCapability;
			SteelInbound -= ProductionCapability;
			MachineProductionTime = 0;
		}
	}
}

