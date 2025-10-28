// Copyright Leyodemus

#include "Player/CC_PlayerState.h"

#include "AbilitySystem/CC_AbilitySystemComponent.h"
#include "AbilitySystem/CC_AttributeSet.h"

ACC_PlayerState::ACC_PlayerState()
{
	SetNetUpdateFrequency(100.f); // By default, this is only set to 1 for the PlayerState, which is too low in our case

	AbilitySystemComponent = CreateDefaultSubobject<UCC_AbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);
	
	AttributeSet = CreateDefaultSubobject<UCC_AttributeSet>("AttributeSet");
}

UAbilitySystemComponent* ACC_PlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}
