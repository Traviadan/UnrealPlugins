#include "RealAbilitySystemTags.h"

namespace RASTags
{
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(None, "RASTags.None", "None")
	
	namespace Abilities
	{
		UE_DEFINE_GAMEPLAY_TAG_COMMENT(Primary, "RASTags.Abilities.Primary", "Tag for the primary Ability")
		UE_DEFINE_GAMEPLAY_TAG_COMMENT(Secondary, "RASTags.Abilities.Secondary", "Tag for the secondary Ability")
		UE_DEFINE_GAMEPLAY_TAG_COMMENT(Tertiary, "RASTags.Abilities.Tertiary", "Tag for the tertiary Ability")
	}

	namespace Events
	{
		UE_DEFINE_GAMEPLAY_TAG_COMMENT(KillScored, "RASTags.Events.KillScored", "Tag for the KillScored Event")
	}

}