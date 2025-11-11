// Copyright EggersBhv

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "RealGameplayAbility.generated.h"

class URealAbilitySystemComponent;

/**
 * 
 */
UCLASS()
class REALABILITYSYSTEM_API URealGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	URealAbilitySystemComponent* GetRealAbilitySystemComponentFromActorInfo() const;
	UFUNCTION(BlueprintCallable)
	AController* GetControllerFromActorInfo() const;
	
protected:
	virtual void ActivateAbility(
		const FGameplayAbilitySpecHandle Handle,
		const FGameplayAbilityActorInfo* ActorInfo,
		const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData) override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "RealAbilitySystem|Debug")
	bool bDrawDebugs = false;
};
