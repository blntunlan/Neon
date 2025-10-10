// Copyright Bulent

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "NeonUserWidget.generated.h"


UCLASS()
class AURA_API UNeonUserWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	
	UFUNCTION(BlueprintCallable)
	void SetWidgetController(UObject* InWidgetController);
	
	UPROPERTY(BlueprintReadOnly, Category = "WidgetController")
	TObjectPtr<UObject> WidgetController;
	
protected:

	UFUNCTION(BlueprintImplementableEvent)
	void WidgetControllerSet();
};
