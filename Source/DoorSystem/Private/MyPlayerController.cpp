#include "MyPlayerController.h"
#include "InteractionHUD.h"
#include "InteractiveDoor.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "GameFramework/Character.h"
#include "Blueprint/UserWidget.h"

AMyPlayerController::AMyPlayerController()
{
    PrimaryActorTick.bCanEverTick = true; // Tick fonksiyonunun çalýþmasý için
}

void AMyPlayerController::BeginPlay()
{
    Super::BeginPlay();
    CreateAndInitializeHUD();
}

void AMyPlayerController::CreateAndInitializeHUD()
{
    if (!GetWorld()) return;

    InteractionHUD = Cast<AInteractionHUD>(GetHUD());
    if (!InteractionHUD)
    {
        InteractionHUD = GetWorld()->SpawnActor<AInteractionHUD>();
        if (InteractionHUD)
        {
            MyHUD = InteractionHUD;
        }
    }
}

void AMyPlayerController::SetupInputComponent()
{
    Super::SetupInputComponent();

    if (InputComponent)
    {
        InputComponent->BindAction("Interact", IE_Pressed, this, &AMyPlayerController::Interact);
    }
}

void AMyPlayerController::Tick(float DeltaTime) // PlayerTick yerine Tick
{
    Super::Tick(DeltaTime);
    CheckForInteractables();
}

void AMyPlayerController::Interact()
{
    if (NearbyDoor && NearbyDoor->bPlayerInRange)
    {
        NearbyDoor->ToggleDoor();
    }
}

void AMyPlayerController::CheckForInteractables()
{
    if (!GetWorld()) return;

    TArray<AActor*> FoundActors;
    UGameplayStatics::GetAllActorsOfClass(GetWorld(), AInteractiveDoor::StaticClass(), FoundActors);

    ACharacter* PlayerCharacter = GetCharacter();
    if (!PlayerCharacter) return;

    NearbyDoor = nullptr;
    float ClosestDistance = TNumericLimits<float>::Max();

    for (AActor* Actor : FoundActors)
    {
        AInteractiveDoor* Door = Cast<AInteractiveDoor>(Actor);
        if (Door && Door->bPlayerInRange)
        {
            float Distance = FVector::Dist(PlayerCharacter->GetActorLocation(), Door->GetActorLocation());
            if (Distance < ClosestDistance)
            {
                ClosestDistance = Distance;
                NearbyDoor = Door;
            }
        }
    }

    if (InteractionHUD)
    {
        InteractionHUD->bShowInteractionMessage = (NearbyDoor != nullptr);
        if (NearbyDoor)
        {
            InteractionHUD->InteractionKey = NearbyDoor->InteractionKey;
        }
    }
}