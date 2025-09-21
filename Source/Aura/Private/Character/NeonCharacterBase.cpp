// Copyright Bulent


#include "Character/NeonCharacterBase.h"

// Sets default values
ANeonCharacterBase::ANeonCharacterBase()
{
 	PrimaryActorTick.bCanEverTick = false;

	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");
	Weapon->SetupAttachment(GetMesh(),"WeaponSocket");
	Weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);

}

void ANeonCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}


