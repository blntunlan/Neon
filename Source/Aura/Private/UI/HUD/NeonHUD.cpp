// Copyright Bulent


#include "UI/HUD/NeonHUD.h"

#include "UI/Widget/NeonUserWidget.h"

void ANeonHUD::BeginPlay()
{
	Super::BeginPlay();

	UUserWidget* Widget = CreateWidget<UUserWidget>(GetWorld(), OverlayWidgetClass);
	Widget->AddToViewport();
}
