// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SewingMachine.h"
#include "SteelBeamFurnace.h"
#include "Lumberjack.h"
#include "CoalMine.h"
#include "IronMine.h"
#include "GameFramework/Actor.h"
#include "Cart2.generated.h"
using namespace std;

UCLASS()
class CREENCIA_UECHAL1_API ACart2 : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ACart2();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "MoveActor")
		class USceneComponent* RootScene;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "MoveActor")
		class UStaticMeshComponent* Mesh;

public:

	// Called every frame
	virtual void Tick(float DeltaTime) override;


	//Actor Assignments
	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category = "ActorAssignment")
		class AActor* SewingMachineFactory;
	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category = "ActorAssignment")
		class AActor* Lumberjack;
	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category = "ActorAssignment")	
		class AActor* SteelBeamFurnace;
	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category = "ActorAssignment")
		class AActor* Garage2;

	// CartVariables
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "CartVariables")
		float Speed;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "CartVariables")
		int Capacity = 0;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "CartVariables")
		int MaxCapacity = 3;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		float TimeElapsed = 0;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		float LoadUnloadTime = 0;

	//In Cart Items
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "InCartItems")
		int SteelInCart = 0;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "InCartItems")
		int LumberInCart = 0;

	UPROPERTY(VisibleAnywhere)
		int AvailableSpace = MaxCapacity - Capacity;



protected:

	//Movement Variables
	float TotalDistance;
	float CurrentDistance;
	FVector Direction;
	UPROPERTY(EditAnywhere, Category = "CartVariables")
	FVector Destination;
	FVector StartLocation;
	UPROPERTY(EditAnywhere, Category = "CartVariables")
		FVector CurrentLocation;
	bool Move = true;
	UPROPERTY(VisibleAnywhere)
		float Ticks = 0;
	UPROPERTY(EditAnywhere, Category = "CartVariables")
		float MinTime = 8.0f;

	UPROPERTY(EditAnywhere, Category = "CartVariables")
		FVector TempLocation;

	bool ReadyPickup = false;

public:
	//Building Classes
	UPROPERTY(VisibleAnywhere)
	
		USewingMachine* SewingMachineClass;
	UPROPERTY(VisibleAnywhere)
		ULumberjack* LumberjackClass;
	UPROPERTY(VisibleAnywhere)
		USteelBeamFurnace* FurnaceClass;

private:

	void LoadItems();
	void UnloadItems();



};
