// Copyright Bulent

#pragma once

#include "CoreMinimal.h"
#include "Character/NeonCharacterBase.h"
#include "Interaction/EnemyInterface.h"
#include "NeonEnemy.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API ANeonEnemy : public ANeonCharacterBase, public IEnemyInterface
{
	GENERATED_BODY()

public:

	virtual void HighlightActor() override;
	virtual void UnHighlightActor() override;
};
