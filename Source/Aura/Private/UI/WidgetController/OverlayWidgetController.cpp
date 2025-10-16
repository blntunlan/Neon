// Copyright Bulent

#include "UI/WidgetController/OverlayWidgetController.h"
#include "AbilitySystem/NeonAttributeSet.h"

void UOverlayWidgetController::BroadcastInitialValues()
{
    const UNeonAttributeSet* NeonAttributeSet = CastChecked<UNeonAttributeSet>(AttributeSet);
    
    OnHealthChanged.Broadcast(NeonAttributeSet->GetHealth());
    OnMaxHealthChanged.Broadcast(NeonAttributeSet->GetMaxHealth());
    OnManaChanged.Broadcast(NeonAttributeSet->GetMana());
    OnMaxManaChanged.Broadcast(NeonAttributeSet->GetMaxMana());
}

void UOverlayWidgetController::BindCallbacksToDependencies()
{
    const UNeonAttributeSet* NeonAttributeSet = CastChecked<UNeonAttributeSet>(AttributeSet);

    // Health değişikliklerini dinle
    AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
        NeonAttributeSet->GetHealthAttribute()).AddLambda(
            [this](const FOnAttributeChangeData& Data)
            {
                OnHealthChanged.Broadcast(Data.NewValue);
            }
    );

    // MaxHealth değişikliklerini dinle
    AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
        NeonAttributeSet->GetMaxHealthAttribute()).AddLambda(
            [this](const FOnAttributeChangeData& Data)
            {
                OnMaxHealthChanged.Broadcast(Data.NewValue);
            }
    );

    // Mana değişikliklerini dinle
    AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
        NeonAttributeSet->GetManaAttribute()).AddLambda(
            [this](const FOnAttributeChangeData& Data)
            {
                OnManaChanged.Broadcast(Data.NewValue);
            }
    );

    // MaxMana değişikliklerini dinle
    AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
        NeonAttributeSet->GetMaxManaAttribute()).AddLambda(
            [this](const FOnAttributeChangeData& Data)
            {
                OnMaxManaChanged.Broadcast(Data.NewValue);
            }
    );
}