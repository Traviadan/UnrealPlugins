// Copyright EggersBhv

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "RealAbilitySystemComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class REALABILITYSYSTEM_API URealAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()

public:
	URealAbilitySystemComponent();

	virtual void OnGiveAbility(FGameplayAbilitySpec& AbilitySpec) override;
	virtual void OnRep_ActivateAbilities() override;

	UFUNCTION(BlueprintCallable, Category = "RealAbilitySystem")
	void SetAbilityLevel(TSubclassOf<UGameplayAbility> AbilityClass, int32 Level);

	UFUNCTION(BlueprintCallable, Category = "RealAbilitySystem")
	void AddToAbilityLevel(TSubclassOf<UGameplayAbility> AbilityClass, int32 Level = 1);
	
private:
	void HandleAutoActivatedAbility(const FGameplayAbilitySpec& AbilitySpec);
};
