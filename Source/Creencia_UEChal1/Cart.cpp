// Fill out your copyright notice in the Description page of Project Settings.


#include "Cart.h"
#include "Math/UnrealMathUtility.h"

// Sets default values
ACart::ACart()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	RootScene = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = RootScene;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(RootComponent);
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACart::BeginPlay()
{
	Super::BeginPlay();

	CoalMineClass = CoalMine->FindComponentByClass<UCoalMine>();
	IronMineClass = IronMine->FindComponentByClass<UIronMine>();
	LumberjackClass = Lumberjack->FindComponentByClass<ULumberjack>();
	SewingMachineClass = SewingMachineFactory->FindComponentByClass<USewingMachine>();
	FurnaceClass = SteelBeamFurnace->FindComponentByClass <USteelBeamFurnace> ();

	this->StartLocation = this->GetActorLocation();
	this->CurrentLocation = this->StartLocation;
	
}

// Called every frame
void ACart::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//UE_LOG(LogTemp, Warning, TEXT("Text, %d "), IronMineClass->IronQuantity);
	  /*
	  if (Move && (Ticks < MinTime/Speed))
	  {
		  this->Ticks += DeltaTime;
		  this->SetActorLocation(FMath::Lerp(this->CurrentLocation, this->Destination, Ticks / (MinTime/Speed)));
	  }
	  else
	  {
		  this->SetActorLocation(this->Destination);
		  this->TempLocation = this->GetActorLocation();
		  this->Ticks = 0;
		  Move = false;
	  }*/
	
	if (Move && Ticks < (MinTime / Speed))
	{
		this->Ticks += DeltaTime;
		this->SetActorLocation(FMath::Lerp(this->CurrentLocation, this->Destination, Ticks / (MinTime / Speed)));
		
		//If There are slots for the cart, the cart will load items til full
	}
	else if(Move == true)
	{
		this->SetActorLocation(this->Destination);
		this->CurrentLocation = this->GetActorLocation();
		this->Ticks = 0;
		Move = false;
	}


	if (Move == false) 
	{
		AvailableSpace = MaxCapacity - Capacity;
		if (Capacity < MaxCapacity && AvailableSpace == MaxCapacity)
		{
			//check if coal production is full
			if (CoalMineClass->CoalQuantity >= CoalMineClass->CoalMaxQuantity)
			{
				this->Destination = CoalMine->GetActorLocation();
				LoadItems();
				Move = true;
			}
			//check if iron production is full
			else if (IronMineClass->IronQuantity >= IronMineClass->IronMaxQuantity)
			{
				this->Destination = IronMine->GetActorLocation();
				LoadItems();
				Move = true;
			}
			else if (LumberjackClass->LumberQuantity >= LumberjackClass->LumberMaxQuantity)
			{
				this->Destination = Lumberjack->GetActorLocation();
				LoadItems();
				Move = true;
			}
			else if (FurnaceClass->SteelQuantity >= FurnaceClass->SteelMaxQuantity)
			{
				this->Destination = SteelBeamFurnace->GetActorLocation();
				LoadItems();
				Move = true;
			}
		}
		else if (AvailableSpace != MaxCapacity || )
		{

		}

		//If There are no slots for the cart, the cart will uload items til empty
		else if (Capacity >= MaxCapacity || SteelInCart > 0 || AvailableSpace != MaxCapacity)
		{
			if (IronInCart > 0 || CoalInCart > 0)
			{
				this->Destination = SteelBeamFurnace->GetActorLocation();
				UnloadItems();
				Move = true;
			}
			if (LumberInCart > 0 || SteelInCart > 0)
			{
				this->Destination = SewingMachineFactory->GetActorLocation();
				UnloadItems();
				Move = true;
			}
		}
		else
		{
			this->Destination = SewingMachineFactory->GetActorLocation();
		}
	}
}
void ACart::LoadItems()
{

	if (CurrentLocation == CoalMine->GetActorLocation())
	{
		
		if(CoalMineClass->CoalQuantity + Capacity <= MaxCapacity)
		{
			CoalInCart += CoalMineClass->CoalQuantity;
			CoalMineClass->CoalQuantity = 0;
			Capacity = CoalInCart;
		}
		
	}
	if (CurrentLocation == IronMine->GetActorLocation())
	{
		if (IronMineClass->IronQuantity + Capacity <= MaxCapacity)
		{
			IronInCart += IronMineClass->IronQuantity;
			IronMineClass->IronQuantity = 0;
			Capacity = IronInCart;
		}
	}
	if (CurrentLocation == Lumberjack->GetActorLocation())
	{
		LumberInCart += LumberjackClass->LumberQuantity;
		LumberjackClass->LumberQuantity = 0;
		Capacity = LumberInCart;
	}
	if (CurrentLocation == SteelBeamFurnace->GetActorLocation())
	{
		SteelInCart += FurnaceClass->SteelQuantity;
		FurnaceClass->SteelQuantity = 0;
		Capacity = SteelInCart;
	}
	
}

void ACart::UnloadItems()
{
	if (CurrentLocation == SteelBeamFurnace->GetActorLocation())
	{
		if (CoalInCart <= FurnaceClass->CoalFactoryCapacity)
		{
			FurnaceClass->CoalInbound += CoalInCart;
			CoalInCart = 0;
			Capacity = CoalInCart;
		}
		if (IronInCart <= FurnaceClass->IronFactoryCapacity)
		{
			FurnaceClass->IronInbound += IronInCart;
			IronInCart = 0;
			Capacity = IronInCart;
		}
	}

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

