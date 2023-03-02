// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "IronMine.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent),BLUEPRINTABLE )
class CREENCIA_UECHAL1_API UIronMine : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UIronMine();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		float IronProductionTime;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		int IronQuantity = 0;

	UPROPERTY(EditAnywhere)
		int IronMaxQuantity = 3;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float MaxIronProductionTime = 5.0f;
	UPROPERTY(EditAnywhere)
		int ProductionCapability = 1;
};
