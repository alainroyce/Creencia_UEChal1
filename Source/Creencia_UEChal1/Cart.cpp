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
	FurnaceClass = SteelBeamFurnace->FindComponentByClass <USteelBeamFurnace>();

	this->StartLocation = Garage->GetActorLocation();
	this->CurrentLocation = this->StartLocation;
	LoadUnloadTime = FMath::FRandRange(1.0f, 3.0f);
}

// Called every frame
void ACart::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Timer = Timer + DeltaTime;
	
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
		UE_LOG(LogTemp, Warning, TEXT("LoadTime: %.1f"), LoadUnloadTime);
		TimeElapsed += DeltaTime;
		AvailableSpace = MaxCapacity - Capacity;
		if (Capacity < MaxCapacity && AvailableSpace == MaxCapacity)
		{
			//check if coal production is full
			if (CoalMineClass->CoalQuantity >= CoalMineClass->CoalMaxQuantity
				&& FurnaceClass->CoalInbound == 0 &&FurnaceClass->SteelQuantity < FurnaceClass->SteelMaxQuantity)
			{
				LoadUnloadTime = FMath::FRandRange(1.0f, 3.0f);
				this->Destination = CoalMine->GetActorLocation();
				LoadItems();
				Move = true;
			}
			//check if iron production is full
			else if (IronMineClass->IronQuantity >= IronMineClass->IronMaxQuantity
				&& FurnaceClass->IronInbound == 0 && FurnaceClass->SteelQuantity < FurnaceClass->SteelMaxQuantity)
			{
				LoadUnloadTime = FMath::FRandRange(1.0f, 3.0f);
				this->Destination = IronMine->GetActorLocation();
				LoadItems();
				Move = true;
			}
			else {
				this->Destination = Garage->GetActorLocation();
				Move = true;
			}
			
		}


		//If There are no slots for the cart, the cart will uload items til empty
		else if (Capacity >= MaxCapacity || AvailableSpace != MaxCapacity)
		{
			if (IronInCart > 0 || CoalInCart > 0 && FurnaceClass->SteelQuantity < FurnaceClass->SteelMaxQuantity)
			{
				LoadUnloadTime = FMath::FRandRange(1.0f, 3.0f);
				this->Destination = SteelBeamFurnace->GetActorLocation();
				UnloadItems();
				Move = true;
			}
		}
	}
}
void ACart::LoadItems()
{

	if (CurrentLocation == CoalMine->GetActorLocation())
	{

			CoalInCart += CoalMineClass->CoalQuantity;
			CoalMineClass->CoalQuantity = 0;
			Capacity = CoalInCart;
	

	}
	if (CurrentLocation == IronMine->GetActorLocation())
	{
		
			IronInCart += IronMineClass->IronQuantity;
			IronMineClass->IronQuantity = 0;
			Capacity = IronInCart;
		
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

	
}

