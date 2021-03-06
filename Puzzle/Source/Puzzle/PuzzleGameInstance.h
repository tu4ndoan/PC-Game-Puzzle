// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "PuzzleGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class PUZZLE_API UPuzzleGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
	UPuzzleGameInstance(const FObjectInitializer&ObjectInitializer);

	virtual void Init();
	
	UFUNCTION(Exec)
	void Host();

	UFUNCTION(Exec)
	void Join(const FString& Address);
};
