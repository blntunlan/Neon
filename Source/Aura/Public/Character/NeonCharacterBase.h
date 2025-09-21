// Copyright Bulent

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "NeonCharacterBase.generated.h"

UCLASS(Abstract)
class AURA_API ANeonCharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	ANeonCharacterBase();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category="Combat")
	TObjectPtr<USkeletalMeshComponent> Weapon;
	
};
