// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SewingMachine.h"
#include "SteelBeamFurnace.h"
#include "Lumberjack.h"
#include "CoalMine.h"
#include "IronMine.h"
#include "Components/ActorComponent.h"
#include "CartTransporter.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CREENCIA_UECHAL1_API UCartTransporter : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCartTransporter();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "MoveActor")
		class USceneComponent* RootScene;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "MoveActor")
		class UStaticMeshComponent* Mesh;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

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


};
