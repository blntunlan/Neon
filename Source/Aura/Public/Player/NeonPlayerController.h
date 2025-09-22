// Copyright Bulent

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "NeonPlayerController.generated.h"

class USplineComponent;
class UInputMappingContext;
class UInputAction;
class UNeonInputConfig;
class IEnemyInterface;
struct FInputActionValue;
/**
 * 
 */
UCLASS()
class AURA_API ANeonPlayerController : public APlayerController
{
	GENERATED_BODY()

public:

	ANeonPlayerController();
	virtual void SetupInputComponent() override;
	
protected:

	virtual void BeginPlay() override;
	virtual void PlayerTick(float DeltaTime) override;
	
private:
	
	UPROPERTY(EditDefaultsOnly, Category="Input")
	TObjectPtr<UInputMappingContext> DefaultMappingContext;

	UPROPERTY(EditDefaultsOnly, Category="Input")
	TObjectPtr<UNeonInputConfig> InputConfig;

	UPROPERTY(EditDefaultsOnly, Category="Input")
	TObjectPtr<UInputAction> MoveAction;

	UPROPERTY(EditDefaultsOnly, Category="Nav")
	TObjectPtr<USplineComponent> Spline;

	UPROPERTY(EditDefaultsOnly)
	float AutoRunAcceptanceRadius = 50.f;
	
	void Move(const FInputActionValue& ActionValue);
	void AbilityInputTagPressed();
	void AbilityInputTagReleased();
	void AbilityInputActionTagHeld();

	void CursorTrace();
	FHitResult CursorHit;
	void AutoRun();
	FVector CachedDestination = FVector::ZeroVector;
	bool bAutoRunning;
	

};
