// Fill out your copyright notice in the Description page of Project Settings.


#include "Cart2.h"

// Sets default values
ACart2::ACart2()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACart2::BeginPlay()
{
	Super::BeginPlay();
	LumberjackClass = Lumberjack->FindComponentByClass<ULumberjack>();
	SewingMachineClass = SewingMachineFactory->FindComponentByClass<USewingMachine>();
	FurnaceClass = SteelBeamFurnace->FindComponentByClass <USteelBeamFurnace>();
	
	this->StartLocation = Garage2->GetActorLocation();
	this->CurrentLocation = this->StartLocation;
	LoadUnloadTime = FMath::FRandRange(1.0f, 3.0f);

}

// Called every frame
void ACart2::Tick(float DeltaTime)
{
	
	Super::Tick(DeltaTime);
	
	

	if (Move && Ticks < (MinTime / Speed))
	{
		this->Ticks += DeltaTime;
		this->SetActorLocation(FMath::Lerp(this->CurrentLocation, this->Destination, Ticks / (MinTime / Speed)));

		//If There are slots for the cart, the cart will load items til full
	}
	else if (Move == true)
	{
		
		this->SetActorLocation(this->Destination);
		this->CurrentLocation = this->GetActorLocation();
		this->Ticks = 0;
		Move = false;
	}

	if (Move == false && TimeElapsed < LoadUnloadTime)
	{
		TimeElapsed += DeltaTime;
		AvailableSpace = MaxCapacity - Capacity;
		if (Capacity < MaxCapacity)
		{
			UE_LOG(LogTemp, Warning, TEXT("LumberInBound: %d LumberMaxCapacity: %d"), SewingMachineClass->LumberInbound, SewingMachineClass->LumberFactoryCapacity);
			//check if Lumber production is full
			if (LumberjackClass->LumberQuantity >= MaxCapacity && 
				SewingMachineClass->LumberInbound ==0)
				//&& (SewingMachineClass->LumberFactoryCapacity - SewingMachineClass->LumberInbound) > LumberInCart)
			{
				this->Destination = Lumberjack->GetActorLocation();
				LoadItems();
			}
			//check if Steel production is full
			else if (FurnaceClass->SteelQuantity >= MaxCapacity
				&& SewingMachineClass->SteelInbound ==0) //SewingMachineClass->SteelFactoryCapacity - 1 && 
				//(SewingMachineClass->SteelFactoryCapacity - SewingMachineClass->SteelInbound) > SteelInCart)
			{
				this->Destination = SteelBeamFurnace->GetActorLocation();
				LoadItems();
			}
			else {
				this->Destination = Garage2->GetActorLocation();
				TimeElapsed += LoadUnloadTime;
			}
			
		}
		else if (Capacity >= MaxCapacity )
		{
			if (LumberInCart > 0 || SteelInCart > 0)
			{
				this->Destination = SewingMachineFactory->GetActorLocation();
				UnloadItems();
			}

		}
		
	}
	else if (Move == false)
	{
		Move = true;
		LoadUnloadTime = FMath::FRandRange(1.0f, 3.0f);
		TimeElapsed = 0;
	}
}

void ACart2::UnloadItems()
{
	if (CurrentLocation == SewingMachineFactory->GetActorLocation())
	{
		if (SteelInCart <= SewingMachineClass->SteelFactoryCapacity)
		{
			SewingMachineClass->SteelInbound += SteelInCart;
			SteelInCart = 0;
			Capacity = SteelInCart;
		}
		if (LumberInCart <= SewingMachineClass->LumberFactoryCapacity)
		{
			SewingMachineClass->LumberInbound += LumberInCart;
			LumberInCart = 0;
			Capacity = LumberInCart;
		}
	}

}

void ACart2::LoadItems()
{
	if (CurrentLocation == Lumberjack->GetActorLocation())
	{
		LumberInCart += MaxCapacity;
		LumberjackClass->LumberQuantity -= MaxCapacity;
		Capacity = LumberInCart;
	}
	if (CurrentLocation == SteelBeamFurnace->GetActorLocation())
	{
		SteelInCart += MaxCapacity;
		FurnaceClass->SteelQuantity -= MaxCapacity;
		Capacity = SteelInCart;
	}
}

