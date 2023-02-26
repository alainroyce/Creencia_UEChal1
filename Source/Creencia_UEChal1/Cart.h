// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SewingMachine.h"
#include "SteelBeamFurnace.h"
#include "Lumberjack.h"
#include "CoalMine.h"
#include "IronMine.h"
#include "GameFramework/Actor.h"
#include "Cart.generated.h"
using namespace std;

UCLASS()
class CREENCIA_UECHAL1_API ACart : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACart();

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
		class AActor* CoalMine;
	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category = "ActorAssignment")
		class AActor* SteelBeamFurnace;
	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category = "ActorAssignment")
		class AActor* IronMine;
	
	// CartVariables
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "CartVariables")
		float Speed;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "CartVariables")
		int Capacity = 0;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "CartVariables")
		int MaxCapacity = 3;

	//In Cart Items
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "InCartItems")
		int IronInCart = 0;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "InCartItems")
		int CoalInCart = 0;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "InCartItems")
		int SteelInCart = 0;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "InCartItems")
		int LumberInCart = 0;

	UPROPERTY(VisibleAnywhere)
		int AvailableSpace = 0;



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

public:
	//Building Classes
	UPROPERTY(VisibleAnywhere)
	UCoalMine* CoalMineClass;
	UPROPERTY(VisibleAnywhere)
	USewingMachine* SewingMachineClass;
	UPROPERTY(VisibleAnywhere)
	ULumberjack* LumberjackClass;
	UPROPERTY(VisibleAnywhere)
	UIronMine* IronMineClass;
	UPROPERTY(VisibleAnywhere)
	USteelBeamFurnace* FurnaceClass;

private:

	void LoadItems();
	void UnloadItems();
	


};
