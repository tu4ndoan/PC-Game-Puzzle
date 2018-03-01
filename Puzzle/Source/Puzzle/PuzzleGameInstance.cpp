// Fill out your copyright notice in the Description page of Project Settings.

#include "PuzzleGameInstance.h"
#include "Engine/Engine.h"

UPuzzleGameInstance::UPuzzleGameInstance(const FObjectInitializer&ObjectInitializer) {
	UE_LOG(LogTemp, Warning, TEXT("Game instance constructor"));
};

void UPuzzleGameInstance::Init() {
	UE_LOG(LogTemp, Warning, TEXT("Game instance Init"))
};

void UPuzzleGameInstance::Host() {
	UEngine* Engine = GetEngine();
	if (!ensure(Engine != nullptr)) return;
	
	Engine->AddOnScreenDebugMessage(0, 2, FColor::Green, TEXT("Hosting"));

	UWorld* World = GetWorld();
	if (!ensure(World != nullptr)) return;

	World->ServerTravel("/game/ThirdPersonCPP/Maps/ThirdPersonExampleMap?listen");
};

void UPuzzleGameInstance::Join(const FString& Address) {
	UEngine* Engine = GetEngine();
	if (!ensure(Engine != nullptr)) return;

	Engine->AddOnScreenDebugMessage(0, 2, FColor::Green, FString::Printf(TEXT("Joining %s"), *Address));
	APlayerController* PlayerController = GetFirstLocalPlayerController();

	if (!ensure(PlayerController != nullptr)) return;

	PlayerController->ClientTravel(Address, ETravelType::TRAVEL_Absolute);
}

 