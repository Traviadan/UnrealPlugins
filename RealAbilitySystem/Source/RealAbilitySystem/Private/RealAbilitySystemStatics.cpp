// Copyright EggersBhv


#include "RealAbilitySystemStatics.h"

#include "Kismet/GameplayStatics.h"

void URealAbilitySystemStatics::SingleLineTraceByProfile(FHitResult& OutHitResult, const UWorld* World, const FVector& Start,
                                                         const FVector& End, FName ProfileName)
{
	check(World);

	FCollisionQueryParams Params;
	Params.bTraceComplex = false;
	OutHitResult = FHitResult();
	FHitResult HitResult;
	World->LineTraceSingleByProfile(HitResult, Start, End, ProfileName, Params);

	OutHitResult.TraceStart = Start;
	OutHitResult.TraceEnd = End;
	OutHitResult = HitResult;
}

void URealAbilitySystemStatics::AimWithPlayerController(const AActor* InSourceActor, FName ProfileName,
	const FVector& TraceStart, float MaxRange, FVector& OutTraceEnd, bool bIgnorePitch)
{
	UWorld* World = InSourceActor->GetWorld();
	check(World);
	
	APlayerController* PC = World->GetFirstPlayerController();
	check(PC);

	FVector ViewStart;
	FRotator ViewRot;
	PC->GetPlayerViewPoint(ViewStart, ViewRot);

	const FVector ViewDir = ViewRot.Vector();
	FVector ViewEnd = ViewStart + (ViewDir * MaxRange);

	ClipCameraRayToAbilityRange(ViewStart, ViewDir, TraceStart, MaxRange, ViewEnd);

	FHitResult HitResult;
	SingleLineTraceByProfile(HitResult, InSourceActor->GetWorld(), ViewStart, ViewEnd, ProfileName);

	const bool bUseTraceResult = HitResult.bBlockingHit && (FVector::DistSquared(TraceStart, HitResult.Location) <= (MaxRange * MaxRange));

	const FVector AdjustedEnd = (bUseTraceResult) ? HitResult.Location : ViewEnd;

	FVector AdjustedAimDir = (AdjustedEnd - TraceStart).GetSafeNormal();
	if (AdjustedAimDir.IsZero())
	{
		AdjustedAimDir = ViewDir;
	}

	if (!bIgnorePitch && bUseTraceResult)
	{
		FVector OriginalAimDir = (ViewEnd - TraceStart).GetSafeNormal();

		if (!OriginalAimDir.IsZero())
		{
			// Convert to angles and use original pitch
			const FRotator OriginalAimRot = OriginalAimDir.Rotation();

			FRotator AdjustedAimRot = AdjustedAimDir.Rotation();
			AdjustedAimRot.Pitch = OriginalAimRot.Pitch;

			AdjustedAimDir = AdjustedAimRot.Vector();
		}
	}

	OutTraceEnd = TraceStart + (AdjustedAimDir * MaxRange);
}

bool URealAbilitySystemStatics::ClipCameraRayToAbilityRange(FVector CameraLocation, FVector CameraDirection,
                                                            FVector AbilityCenter, float AbilityRange, FVector& ClippedPosition)
{
	FVector CameraToCenter = AbilityCenter - CameraLocation;
	float DotToCenter = FVector::DotProduct(CameraToCenter, CameraDirection);
	if (DotToCenter >= 0)		//If this fails, we're pointed away from the center, but we might be inside the sphere and able to find a good exit point.
	{
		float DistanceSquared = CameraToCenter.SizeSquared() - (DotToCenter * DotToCenter);
		float RadiusSquared = (AbilityRange * AbilityRange);
		if (DistanceSquared <= RadiusSquared)
		{
			float DistanceFromCamera = FMath::Sqrt(RadiusSquared - DistanceSquared);
			float DistanceAlongRay = DotToCenter + DistanceFromCamera;						//Subtracting instead of adding will get the other intersection point
			ClippedPosition = CameraLocation + (DistanceAlongRay * CameraDirection);		//Cam aim point clipped to range sphere
			return true;
		}
	}
	return false;
}
