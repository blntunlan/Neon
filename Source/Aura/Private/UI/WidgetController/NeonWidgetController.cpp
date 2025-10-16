// Copyright Bulent


#include "UI/WidgetController/NeonWidgetController.h"


void UNeonWidgetController::SetWidgetControllerParams(const FWidgetControllerParams& Params)
{
	PlayerController = Params.PlayerController;
	PlayerState = Params.PlayerState;
	AbilitySystemComponent = Params.AbilitySystemComponent;
	AttributeSet = Params.AttributeSet;
}

void UNeonWidgetController::BroadcastInitialValues()
{
}

void UNeonWidgetController::BindCallbacksToDependencies()
{
}
