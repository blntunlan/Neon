// Copyright Bulent


#include "AbilitySystem/NeonAttributeSet.h"

#include "Net/UnrealNetwork.h"

UNeonAttributeSet::UNeonAttributeSet()
{
	InitHealth(50.f);
	InitMaxHealth(100.f);
	InitMana(25.f);
	InitMaxMana(100.f);
}

void UNeonAttributeSet::GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY(UNeonAttributeSet, Health, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UNeonAttributeSet, MaxHealth, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UNeonAttributeSet, Mana, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UNeonAttributeSet, MaxMana, COND_None, REPNOTIFY_Always);
	
}

void UNeonAttributeSet::OnRep_Health(const FGameplayAttributeData& OldHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UNeonAttributeSet, Health, OldHealth);
}

void UNeonAttributeSet::OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UNeonAttributeSet, MaxHealth, OldMaxHealth);
}

void UNeonAttributeSet::OnRep_Mana(const FGameplayAttributeData& OldMana) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UNeonAttributeSet, Mana, OldMana);
}

void UNeonAttributeSet::OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UNeonAttributeSet, MaxMana, OldMaxMana);
}
