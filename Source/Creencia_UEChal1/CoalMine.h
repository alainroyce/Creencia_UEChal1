// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CoalMine.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CREENCIA_UECHAL1_API UCoalMine : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCoalMine();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		float CoalProductionTime;
	UPROPERTY(EditAnywhere)
		int CoalQuantity = 0;

	UPROPERTY(EditAnywhere)
		int CoalMaxQuantity = 3;
	UPROPERTY(EditAnywhere)
		float MaxCoalProductionTime = 5.0f;
	UPROPERTY(EditAnywhere)
		int ProductionCapability = 1;

		
};
