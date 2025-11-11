// Copyright EggersBhv

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "RealAbilitySystemStatics.generated.h"

/**
 * 
 */
UCLASS()
class REALABILITYSYSTEM_API URealAbilitySystemStatics : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "RealAbilitySystem")
	static void SingleLineTraceByProfile(FHitResult& OutHitResult, const UWorld* World, const FVector& Start, const FVector& End, FName ProfileName);

	UFUNCTION(BlueprintCallable, Category = "RealAbilitySystem")
	static void AimWithPlayerController(const AActor* InSourceActor, FName ProfileName, const FVector& TraceStart, float MaxRange, FVector& OutTraceEnd, bool bIgnorePitch = false);
	
	UFUNCTION(BlueprintCallable, Category = "RealAbilitySystem")
	static bool ClipCameraRayToAbilityRange(FVector CameraLocation, FVector CameraDirection, FVector AbilityCenter, float AbilityRange, FVector& ClippedPosition);
};
