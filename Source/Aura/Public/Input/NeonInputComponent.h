// Copyright Bulent

#pragma once

#include "CoreMinimal.h"
#include "EnhancedInputComponent.h"
#include "NeonInputConfig.h"
#include "NeonInputComponent.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API UNeonInputComponent : public UEnhancedInputComponent
{
	GENERATED_BODY()

public:

	template<class UserClass, typename PressedFuncType, typename ReleasedFuncType, typename HeldFuncType>
	void BindAbilityActions(const UNeonInputConfig* InputConfig, UserClass* Object, PressedFuncType PressedFunc, ReleasedFuncType ReleasedFunc, HeldFuncType HeldFunc);
};

template <class UserClass, typename PressedFuncType, typename ReleasedFuncType, typename HeldFuncType>
void UNeonInputComponent::BindAbilityActions(const UNeonInputConfig* InputConfig, UserClass* Object, PressedFuncType PressedFunc, ReleasedFuncType ReleasedFunc, HeldFuncType HeldFunc)
{
	for (const FNeonInputAction& Action : InputConfig->AbilityInputActions)
	{
		if (Action.InputAction)
		{
			if (PressedFunc)
			{
				BindAction(Action.InputAction, ETriggerEvent::Started, Object, PressedFunc);
			}

			if (ReleasedFunc)
			{
				BindAction(Action.InputAction, ETriggerEvent::Completed, Object, ReleasedFunc);
			}

			if (HeldFunc)
			{
				BindAction(Action.InputAction, ETriggerEvent::Triggered, Object, HeldFunc);
			}
		}
	}
}

