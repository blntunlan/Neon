// Copyright Bulent


#include "Player/NeonPlayerState.h"

#include "AbilitySystem/NeonAbilitySystemComponent.h"
#include "AbilitySystem/NeonAttributeSet.h"

ANeonPlayerState::ANeonPlayerState()
{
	AbilitySystemComponent = CreateDefaultSubobject<UNeonAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);

	AttributeSet = CreateDefaultSubobject<UNeonAttributeSet>("AttributeSet");
	SetNetUpdateFrequency(100.f);
}

UAbilitySystemComponent* ANeonPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}
