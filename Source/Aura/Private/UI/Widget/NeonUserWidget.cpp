// Copyright Bulent


#include "UI/Widget/NeonUserWidget.h"

void UNeonUserWidget::SetWidgetController(UObject* InWidgetController)
{
	WidgetController = InWidgetController;
	WidgetControllerSet();
}
