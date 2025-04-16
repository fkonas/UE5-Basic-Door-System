// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "InteractionHUD.generated.h"

/**
 * 
 */
UCLASS()
class DOORSYSTEM_API AInteractionHUD : public AHUD
{
    GENERATED_BODY()

public:
    AInteractionHUD();

    virtual void DrawHUD() override;

    // Etkile�im mesaj�n� g�sterme durumu
    UPROPERTY(BlueprintReadWrite, Category = "HUD")
    bool bShowInteractionMessage;

    // Etkile�im tu�u
    UPROPERTY(BlueprintReadWrite, Category = "HUD")
    FKey InteractionKey;

    // Mesaj�n ekrandaki konumu
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HUD")
    FVector2D MessagePosition;

    // Mesaj�n rengi
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HUD")
    FLinearColor MessageColor;

    // Mesaj�n fontu
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HUD")
    UFont* MessageFont;
};
