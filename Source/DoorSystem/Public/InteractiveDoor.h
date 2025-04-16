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

    // Kap� bile�enleri
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Door")
    class UStaticMeshComponent* DoorFrame;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Door")
    class UStaticMeshComponent* Door;

    // Etkile�im mesafesi
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Door")
    float InteractionDistance = 200.f;

    // Kap� a��k m�?
    UPROPERTY(BlueprintReadOnly, Category = "Door")
    bool bIsOpen;

    // Kap�y� a�/kapa
    UFUNCTION(BlueprintCallable, Category = "Door")
    void ToggleDoor();

    // Oyuncu etkile�imde mi?
    UPROPERTY(BlueprintReadOnly, Category = "Door")
    bool bPlayerInRange;

    // Etkile�im tu�u
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Door")
    FKey InteractionKey = EKeys::E;

    // Oyuncu kontrolc�s�n� kontrol et
    void CheckPlayerRange();

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Door")
    float DoorOpenSpeed = 2.0f; // A��l�� h�z�

    //UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Door")
    //class UWidgetComponent* InteractionWidgetComponent; // Etkile�im widget'�

    //UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Door", meta = (BlueprintProtected = "true"))
    //TSubclassOf<class UUserWidget> InteractionWidgetClass; // Widget blueprint class

private:
    float CurrentDoorAngle; // Mevcut kap� a��s�
    float TargetDoorAngle; // Hedef kap� a��s�
};
