// Copyright Bulent


#include "Actor/NeonEffectActor.h"

#include "AbilitySystemInterface.h"
#include "AbilitySystem/NeonAbilitySystemComponent.h"
#include "AbilitySystem/NeonAttributeSet.h"
#include "Components/SphereComponent.h"


ANeonEffectActor::ANeonEffectActor()
{
 	
	PrimaryActorTick.bCanEverTick = false;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	SetRootComponent(Mesh);

	Sphere = CreateDefaultSubobject<USphereComponent>("Sphere");
	Sphere->SetupAttachment(Mesh);

}

void ANeonEffectActor::OnOverlap(UPrimitiveComponent* OverlappedComp, AActor* Other, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& OverlapInfo)
{
	if (const IAbilitySystemInterface* AbilitySystemInterface = Cast<IAbilitySystemInterface>(Other))
	{
		if (UAbilitySystemComponent* ASC = AbilitySystemInterface->GetAbilitySystemComponent())
		{
			if (const UNeonAttributeSet* AttributeSet = Cast<UNeonAttributeSet>(ASC->GetAttributeSet(UNeonAttributeSet::StaticClass())))
			{
				UNeonAttributeSet* MutableAttributeSet = const_cast<UNeonAttributeSet*>(AttributeSet);
				MutableAttributeSet->SetHealth(AttributeSet->GetHealth() + 25.f);
				Destroy();
			}
		}
	}
}

void ANeonEffectActor::EndOverlap(UPrimitiveComponent* OverlappedComp, AActor* Other, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex)
{
}


void ANeonEffectActor::BeginPlay()
{
	Super::BeginPlay();


	Sphere->OnComponentBeginOverlap.AddDynamic(this , &ANeonEffectActor::OnOverlap);
	Sphere->OnComponentEndOverlap.AddDynamic(this , &ANeonEffectActor::EndOverlap);
}



