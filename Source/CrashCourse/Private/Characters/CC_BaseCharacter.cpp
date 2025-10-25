// Copyright Leyodemus

#include "CrashCourse/Public/Characters/CC_BaseCharacter.h"

ACC_BaseCharacter::ACC_BaseCharacter()
{
	PrimaryActorTick.bCanEverTick = false;

	// Tick and refresh bone transforms, whether rendered or not - for bone updates on a dedicated server (this is set to "off" by default)
	GetMesh()->VisibilityBasedAnimTickOption = EVisibilityBasedAnimTickOption::AlwaysTickPoseAndRefreshBones;
}

