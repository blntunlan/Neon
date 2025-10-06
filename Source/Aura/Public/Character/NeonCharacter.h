// Copyright Bulent

#pragma once

#include "CoreMinimal.h"
#include "Character/NeonCharacterBase.h"
#include "NeonCharacter.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API ANeonCharacter : public ANeonCharacterBase
{
	GENERATED_BODY()

public:
	ANeonCharacter();

	virtual void OnRep_PlayerState() override;
	virtual void PossessedBy(AController* NewController) override;

private:
	
	void InitAbilityActorInfo();
};
