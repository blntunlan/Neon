// Copyright Bulent

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "NeonInputConfig.generated.h"

USTRUCT()
struct FNeonInputAction
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly)
	const class UInputAction* InputAction = nullptr;
};
UCLASS()
class AURA_API UNeonInputConfig : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Input")
	TArray<FNeonInputAction> AbilityInputActions;	
};
