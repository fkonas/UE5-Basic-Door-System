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

    // Etkileþim mesajýný gösterme durumu
    UPROPERTY(BlueprintReadWrite, Category = "HUD")
    bool bShowInteractionMessage;

    // Etkileþim tuþu
    UPROPERTY(BlueprintReadWrite, Category = "HUD")
    FKey InteractionKey;

    // Mesajýn ekrandaki konumu
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HUD")
    FVector2D MessagePosition;

    // Mesajýn rengi
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HUD")
    FLinearColor MessageColor;

    // Mesajýn fontu
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HUD")
    UFont* MessageFont;
};
