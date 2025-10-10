// Copyright Bulent

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "NeonHUD.generated.h"

class UNeonUserWidget;
/**
 * 
 */
UCLASS()
class AURA_API ANeonHUD : public AHUD
{
	GENERATED_BODY()

public:

	UPROPERTY()
	TObjectPtr<UNeonUserWidget> OverlayWidget;

protected:

	virtual void BeginPlay() override;

private:

	UPROPERTY(EditAnywhere)
	TSubclassOf<UNeonUserWidget> OverlayWidgetClass;

};
