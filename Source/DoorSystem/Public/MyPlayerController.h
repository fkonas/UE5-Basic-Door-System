#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "InteractionHUD.h"
#include "InteractiveDoor.h"
#include "MyPlayerController.generated.h"

UCLASS()
class DOORSYSTEM_API AMyPlayerController : public APlayerController
{
    GENERATED_BODY()

public:
    AMyPlayerController();

protected:
    virtual void BeginPlay() override;
    virtual void SetupInputComponent() override;
    virtual void Tick(float DeltaTime) override; // PlayerTick yerine Tick kullanýyoruz

    // Etkileþim fonksiyonu
    UFUNCTION()
    void Interact();

    // HUD referansý
    UPROPERTY()
    AInteractionHUD* InteractionHUD;

    // Yakýndaki etkileþimli nesne
    UPROPERTY()
    AInteractiveDoor* NearbyDoor;

private:
    void CheckForInteractables();
    void CreateAndInitializeHUD();
};