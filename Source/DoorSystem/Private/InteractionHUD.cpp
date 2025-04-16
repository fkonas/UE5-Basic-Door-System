#include "InteractionHUD.h"
#include "Engine/Canvas.h"
#include "Engine/Engine.h"

AInteractionHUD::AInteractionHUD()
{
    bShowInteractionMessage = false;
    MessagePosition = FVector2D(900.f, 750.f);
    MessageColor = FLinearColor::White;
}

void AInteractionHUD::DrawHUD()
{
    Super::DrawHUD();

    if (bShowInteractionMessage && Canvas)
    {
        FString Message = FString::Printf(TEXT("Press [%s] to interact"), *InteractionKey.ToString());
        FCanvasTextItem TextItem(MessagePosition, FText::FromString(Message), MessageFont, MessageColor);
        Canvas->DrawItem(TextItem);
    }
}