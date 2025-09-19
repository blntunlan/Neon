// Copyright Bulent


#include "NeonCharacterBase.h"

// Sets default values
ANeonCharacterBase::ANeonCharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ANeonCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ANeonCharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ANeonCharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

