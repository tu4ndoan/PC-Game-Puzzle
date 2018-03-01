// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "MovingBox.generated.h"

/**
 * 
 */
UCLASS()
class PUZZLE_API AMovingBox : public AStaticMeshActor
{
	GENERATED_BODY()
	
public:
	AMovingBox();
	virtual void Tick(float DeltaTime) override;

	virtual void BeginPlay();

	UPROPERTY(EditAnywhere)
	float Speed = 20;

	UPROPERTY(EditAnywhere, Meta = (MakeEditWidget = true))
	FVector TargetLocation;

private:
	FVector GlobalTargetLocation;
	FVector GlobalStartLocation;
};
