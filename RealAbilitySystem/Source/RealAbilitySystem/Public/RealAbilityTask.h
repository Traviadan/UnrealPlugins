// Copyright EggersBhv

#pragma once

#include "CoreMinimal.h"
#include "Abilities/Tasks/AbilityTask.h"
#include "RealAbilityTask.generated.h"

/**
 * 
 */
UCLASS(Abstract)
class REALABILITYSYSTEM_API URealAbilityTask : public UAbilityTask
{
	GENERATED_BODY()

protected:
	virtual void Activate() override;
	
	virtual void PerformTask();

	float PerformTaskInterval = 0.1f;
	FTimerHandle TimerHandle;
	
private:
	virtual void OnDestroy(bool AbilityEnded) override;
};
