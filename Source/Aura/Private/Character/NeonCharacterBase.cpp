// Copyright Bulent


#include "Character/NeonCharacterBase.h"

// Sets default values
ANeonCharacterBase::ANeonCharacterBase()
{
 	PrimaryActorTick.bCanEverTick = false;

	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");
	Weapon->SetupAttachment(GetMesh(), FName("WeaponSocket")); // FName() kullanmak daha güvenli.
	Weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);

}

void ANeonCharacterBase::BeginPlay()
{
	Super::BeginPlay();

}

UAbilitySystemComponent* ANeonCharacterBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}


