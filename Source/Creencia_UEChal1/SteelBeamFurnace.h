// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SteelBeamFurnace.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CREENCIA_UECHAL1_API USteelBeamFurnace : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	USteelBeamFurnace();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	
public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditAnywhere)
		int SteelMaxQuantity = 3;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float MaxSteelProductionTime = 2.5f;
	UPROPERTY(EditAnywhere)
		int ProductionCapability = 1;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		int SteelQuantity = 0;

	UPROPERTY(EditAnywhere)
		int IronInbound = 0;
	UPROPERTY(EditAnywhere)
		int CoalInbound = 0;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		float SteelProductionTime = 0;
	UPROPERTY(EditAnywhere)
		int IronFactoryCapacity = 3;
	UPROPERTY(EditAnywhere)
		int CoalFactoryCapacity = 3;

		
};
