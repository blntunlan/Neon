// Copyright Bulent

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NeonEffectActor.generated.h"

class USphereComponent;

UCLASS()
class AURA_API ANeonEffectActor : public AActor
{
	GENERATED_BODY()
	
public:
	
	ANeonEffectActor();

	UFUNCTION()
	virtual void OnOverlap(UPrimitiveComponent* OverlappedComp, AActor* Other, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& OverlapInfo);

	UFUNCTION()
	virtual void EndOverlap(UPrimitiveComponent* OverlappedComp, AActor* Other, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
protected:
	
	virtual void BeginPlay() override;

private:

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USphereComponent> Sphere;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UStaticMeshComponent> Mesh;
};
