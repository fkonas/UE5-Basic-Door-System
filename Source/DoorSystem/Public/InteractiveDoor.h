// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InteractiveDoor.generated.h"


UCLASS()
class DOORSYSTEM_API AInteractiveDoor : public AActor
{
    GENERATED_BODY()

public:
    AInteractiveDoor();

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;

    // Kapý bileþenleri
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Door")
    class UStaticMeshComponent* DoorFrame;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Door")
    class UStaticMeshComponent* Door;

    // Etkileþim mesafesi
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Door")
    float InteractionDistance = 200.f;

    // Kapý açýk mý?
    UPROPERTY(BlueprintReadOnly, Category = "Door")
    bool bIsOpen;

    // Kapýyý aç/kapa
    UFUNCTION(BlueprintCallable, Category = "Door")
    void ToggleDoor();

    // Oyuncu etkileþimde mi?
    UPROPERTY(BlueprintReadOnly, Category = "Door")
    bool bPlayerInRange;

    // Etkileþim tuþu
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Door")
    FKey InteractionKey = EKeys::E;

    // Oyuncu kontrolcüsünü kontrol et
    void CheckPlayerRange();

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Door")
    float DoorOpenSpeed = 2.0f; // Açýlýþ hýzý

    //UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Door")
    //class UWidgetComponent* InteractionWidgetComponent; // Etkileþim widget'ý

    //UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Door", meta = (BlueprintProtected = "true"))
    //TSubclassOf<class UUserWidget> InteractionWidgetClass; // Widget blueprint class

private:
    float CurrentDoorAngle; // Mevcut kapý açýsý
    float TargetDoorAngle; // Hedef kapý açýsý
};
