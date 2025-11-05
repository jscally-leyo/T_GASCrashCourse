#pragma once

#include "CoreMinimal.h"
#include "NativeGameplayTags.h"

/**
 * We will create gameplay tags here that could/will be used in C++ and BP
 * We will also have other tags set up in the Project Settings in the editor, those will only be used in BP
 * Splitting tags like this is a perfectly valid approach
 */
namespace CCTags
{
	namespace CCAbilities
	{
		UE_DECLARE_GAMEPLAY_TAG_EXTERN(ActivateOnGiven);
		
		UE_DECLARE_GAMEPLAY_TAG_EXTERN(Primary);
		UE_DECLARE_GAMEPLAY_TAG_EXTERN(Secondary);
		UE_DECLARE_GAMEPLAY_TAG_EXTERN(Tertiary);

		namespace Enemy
		{
			UE_DECLARE_GAMEPLAY_TAG_EXTERN(Attack);
		}
	}

	namespace Events // no CC-prefix because we already created this (sub)tag in the Unreal editor first
	{
		UE_DECLARE_GAMEPLAY_TAG_EXTERN(KillScored);
		
		namespace Enemy
		{
			UE_DECLARE_GAMEPLAY_TAG_EXTERN(HitReact);
			UE_DECLARE_GAMEPLAY_TAG_EXTERN(EndAttack);
		}
		
	}
}