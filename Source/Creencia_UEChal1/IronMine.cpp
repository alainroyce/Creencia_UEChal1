// Fill out your copyright notice in the Description page of Project Settings.


#include "IronMine.h"

// Sets default values for this component's properties
UIronMine::UIronMine()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UIronMine::BeginPlay()
{
	Super::BeginPlay();

	// ...
	IronProductionTime = 0;
	
}



// Called every frame
void UIronMine::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
	if (IronQuantity < IronMaxQuantity) {
		IronProductionTime = IronProductionTime + DeltaTime;

		if (IronProductionTime >= MaxIronProductionTime) {
			IronQuantity += ProductionCapability;
			IronProductionTime = 0;
		}
	}
}

