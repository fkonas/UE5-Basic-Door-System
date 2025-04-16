#include "InteractiveDoor.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/Character.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"
#include "Components/WidgetComponent.h"
#include "Components/TextBlock.h"

AInteractiveDoor::AInteractiveDoor()
{
    PrimaryActorTick.bCanEverTick = true;

    DoorFrame = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DoorFrame"));
    RootComponent = DoorFrame;

    Door = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Door"));
    Door->SetupAttachment(RootComponent);

    //// Widget component ekle
    //InteractionWidgetComponent = CreateDefaultSubobject<UWidgetComponent>(TEXT("InteractionWidget"));
    //InteractionWidgetComponent->SetupAttachment(RootComponent);
    //InteractionWidgetComponent->SetWidgetSpace(EWidgetSpace::Screen);
    //InteractionWidgetComponent->SetRelativeLocation(FVector(0, 0, 0)); // Kapýnýn üstünde
    //InteractionWidgetComponent->SetDrawSize(FVector2D(200, 50));
    //InteractionWidgetComponent->SetVisibility(false); // Baþlangýçta gizli

    CurrentDoorAngle = 0.0f;
    TargetDoorAngle = 0.0f;
}

void AInteractiveDoor::BeginPlay()
{
    Super::BeginPlay();
    bIsOpen = false;
    bPlayerInRange = false;

    //// Widget oluþtur
    //if (InteractionWidgetClass && InteractionWidgetComponent)
    //{
    //    InteractionWidgetComponent->SetWidgetClass(InteractionWidgetClass);
    //    InteractionWidgetComponent->InitWidget();
    //}
}

void AInteractiveDoor::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    CheckPlayerRange();

    // Yumuþak kapý hareketi
    CurrentDoorAngle = FMath::FInterpTo(CurrentDoorAngle, TargetDoorAngle, DeltaTime, DoorOpenSpeed);
    Door->SetRelativeRotation(FRotator(0.f, CurrentDoorAngle, 0.f));

    //// Widget görünürlüðünü güncelle
    //if (InteractionWidgetComponent)
    //{
    //    InteractionWidgetComponent->SetVisibility(bPlayerInRange);

    //    // Widget içeriðini güncelle
    //    if (UUserWidget* Widget = InteractionWidgetComponent->GetWidget())
    //    {
    //        if (UTextBlock* TextBlock = Cast<UTextBlock>(Widget->GetWidgetFromName("InteractionText")))
    //        {
    //            TextBlock->SetText(FText::FromString(FString::Printf(TEXT("Press [%s] to interact"), *InteractionKey.ToString())));
    //        }
    //    }
    //}
}

void AInteractiveDoor::CheckPlayerRange()
{
    ACharacter* PlayerCharacter = UGameplayStatics::GetPlayerCharacter(this, 0);
    if (!PlayerCharacter) return;

    float Distance = FVector::Dist(GetActorLocation(), PlayerCharacter->GetActorLocation());
    bPlayerInRange = Distance <= InteractionDistance;
}

void AInteractiveDoor::ToggleDoor()
{
    if (bIsOpen)
    {
        // Kapýyý kapat
        FRotator NewRotation = FRotator(0.f, 0.f, 0.f);
        Door->SetRelativeRotation(NewRotation);
    }
    else
    {
        // Kapýyý aç
        FRotator NewRotation = FRotator(0.f, 90.f, 0.f);
        Door->SetRelativeRotation(NewRotation);
    }

    bIsOpen = !bIsOpen;
    TargetDoorAngle = bIsOpen ? 90.0f : 0.0f; // Hedef açýyý güncelle
}

