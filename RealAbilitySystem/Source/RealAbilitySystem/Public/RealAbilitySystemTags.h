#pragma once

#include "CoreMinimal.h"
#include "NativeGameplayTags.h"

namespace RASTags
{
	UE_DECLARE_GAMEPLAY_TAG_EXTERN(None);
	
	namespace Abilities
	{
		UE_DECLARE_GAMEPLAY_TAG_EXTERN(Primary);
		UE_DECLARE_GAMEPLAY_TAG_EXTERN(Secondary);
		UE_DECLARE_GAMEPLAY_TAG_EXTERN(Tertiary);
	}

	namespace Events
	{
		UE_DECLARE_GAMEPLAY_TAG_EXTERN(KillScored);
	}

}