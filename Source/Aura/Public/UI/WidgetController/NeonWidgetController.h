// Copyright Bulent

#pragma once

#include "CoreMinimal.h"
#include "NeonWidgetController.generated.h"


class UAttributeSet;
class UAbilitySystemComponent;

UCLASS()
class AURA_API UNeonWidgetController : public UObject
{
	GENERATED_BODY()

protected:


	UPROPERTY(BlueprintReadOnly, Category="WidgetController")
	TObjectPtr<APlayerController> PlayerController;

	UPROPERTY(BlueprintReadOnly, Category="WidgetController")
	TObjectPtr<APlayerState> PlayerState;

	UPROPERTY(BlueprintReadOnly, Category="WidgetController")
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY(BlueprintReadOnly, Category="WidgetController")
	TObjectPtr<UAttributeSet> AttributeSet;
};

