// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Lumberjack.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CREENCIA_UECHAL1_API ULumberjack : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	ULumberjack();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	


public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;


	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		float LumberProductionTime;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		int LumberQuantity = 0;

	UPROPERTY(EditAnywhere)
		int LumberMaxQuantity = 3;
	UPROPERTY(EditAnywhere)
		float MaxLumberProductionTime = 2.5f;
	UPROPERTY(EditAnywhere)
		int ProductionCapability = 1;

		
};
