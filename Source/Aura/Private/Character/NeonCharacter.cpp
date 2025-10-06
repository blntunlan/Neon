// Copyright Bulent

#include "Character/NeonCharacter.h"
#include "AbilitySystem/NeonAbilitySystemComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Player/NeonPlayerState.h"

ANeonCharacter::ANeonCharacter()
{
	// Set this character to call Tick() every frame if needed
	PrimaryActorTick.bCanEverTick = false;

	// Configure character movement
	UCharacterMovementComponent* CharMoveComp = GetCharacterMovement();
	if (CharMoveComp)
	{
		CharMoveComp->bOrientRotationToMovement = true;
		CharMoveComp->RotationRate = FRotator(0.0, 400.0, 0.0);
		CharMoveComp->bConstrainToPlane = true;
		CharMoveComp->bSnapToPlaneAtStart = true;
	}

	// Disable controller rotation
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;
}

void ANeonCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	// Server-side initialization
	InitAbilityActorInfo();
}

void ANeonCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();

	// Client-side initialization
	InitAbilityActorInfo();
}

void ANeonCharacter::InitAbilityActorInfo()
{
	ANeonPlayerState* NeonPS = GetPlayerState<ANeonPlayerState>();
	if (!NeonPS)
	{
		return;
	}

	UAbilitySystemComponent* ASC = NeonPS->GetAbilitySystemComponent();
	if (ASC)
	{
		ASC->InitAbilityActorInfo(NeonPS, this);
		AbilitySystemComponent = ASC;
	}

	AttributeSet = NeonPS->GetAttributeSet();
}