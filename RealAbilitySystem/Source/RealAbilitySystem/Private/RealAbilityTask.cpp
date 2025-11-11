// Copyright EggersBhv


#include "RealAbilityTask.h"

void URealAbilityTask::Activate()
{
	SetWaitingOnAvatar();

	UWorld* World = GetWorld();
	World->GetTimerManager().SetTimer(TimerHandle, this, &ThisClass::PerformTask, PerformTaskInterval, true);
}

void URealAbilityTask::PerformTask()
{
	// Should be implemented by the child class
}

void URealAbilityTask::OnDestroy(bool AbilityEnded)
{
	if (UWorld* World = GetWorld())
	{
		World->GetTimerManager().ClearTimer(TimerHandle);
	}
	
	Super::OnDestroy(AbilityEnded);
}
