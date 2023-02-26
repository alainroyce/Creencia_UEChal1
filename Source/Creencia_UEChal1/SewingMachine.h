// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SewingMachine.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CREENCIA_UECHAL1_API USewingMachine : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	USewingMachine();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		float MachineProductionTime = 0;

	UPROPERTY(EditAnywhere)
		float MaxMachineProductionTime = 10.0f;
	UPROPERTY(EditAnywhere)
		int ProductionCapability = 1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		int MachineQuantity = 0;

	/// </summary>
	UPROPERTY(EditAnywhere)
		int LumberInbound = 0;
	UPROPERTY(EditAnywhere)
		int SteelInbound = 0;
	UPROPERTY(EditAnywhere)
		int LumberFactoryCapacity = 3;

	UPROPERTY(EditAnywhere)
		int SteelFactoryCapacity = 3;


};
