#include "GameplayTags/CCTags.h"

namespace CCTags
{
	namespace SetByCaller
	{
		UE_DEFINE_GAMEPLAY_TAG_COMMENT(Projectile, "CCTags.SetByCaller.Projectile","Tag for Set by Caller magnitude for Projectiles.");
	}
	
	namespace CCAbilities
	{
		UE_DEFINE_GAMEPLAY_TAG_COMMENT(ActivateOnGiven, "CCTags.CCAbilities.ActivateOnGiven","Tag for abilities that should activate immediately once given.");
		
		UE_DEFINE_GAMEPLAY_TAG_COMMENT(Primary, "CCTags.CCAbilities.Primary","Tag for the Primary ability");
		UE_DEFINE_GAMEPLAY_TAG_COMMENT(Secondary, "CCTags.CCAbilities.Secondary","Tag for the Secondary ability");
		UE_DEFINE_GAMEPLAY_TAG_COMMENT(Tertiary, "CCTags.CCAbilities.Tertiary","Tag for the Tertiary ability");

		namespace Enemy
		{
			UE_DEFINE_GAMEPLAY_TAG_COMMENT(Attack, "CCTags.CCAbilities.Enemy.Attack","Tag for the enemy Attack ability");
		}
	}

	namespace Events // no CC-prefix because we already created this (sub)tag in the Unreal editor first
	{
		UE_DEFINE_GAMEPLAY_TAG_COMMENT(KillScored, "CCTags.Events.Enemy.KillScored","Tag for the KillScored event");
		
		namespace Player
		{
			UE_DEFINE_GAMEPLAY_TAG_COMMENT(HitReact, "CCTags.Events.Player.HitReact","Tag for the player HitReact event");
			UE_DEFINE_GAMEPLAY_TAG_COMMENT(Death, "CCTags.Events.Player.Death","Tag for the player Death event");
		}
		
		namespace Enemy
		{
			UE_DEFINE_GAMEPLAY_TAG_COMMENT(HitReact, "CCTags.Events.Enemy.HitReact","Tag for the enemy HitReact event");
			UE_DEFINE_GAMEPLAY_TAG_COMMENT(EndAttack, "CCTags.Events.Enemy.EndAttack","Tag for the enemy EndAttack event");
			UE_DEFINE_GAMEPLAY_TAG_COMMENT(MeleeTraceHit, "CCTags.Events.Enemy.MeleeTraceHit","Tag for the enemy MeleeTraceHit event");
		}
	}
}