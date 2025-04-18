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
    virtual void Tick(float DeltaTime) override; // PlayerTick yerine Tick kullanıyoruz

    // Etkileşim fonksiyonu
    UFUNCTION()
    void Interact();

    // HUD referansı
    UPROPERTY()
    AInteractionHUD* InteractionHUD;

    // Yakındaki etkileşimli nesne
    UPROPERTY()
    AInteractiveDoor* NearbyDoor;

private:
    void CheckForInteractables();
    void CreateAndInitializeHUD();
};