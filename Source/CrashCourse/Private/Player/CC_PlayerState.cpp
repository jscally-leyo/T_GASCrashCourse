// Copyright Leyodemus

#include "Player/CC_PlayerState.h"
#include "AbilitySystemComponent.h"

ACC_PlayerState::ACC_PlayerState()
{
	SetNetUpdateFrequency(100.f); // By default, this is only set to 1 for the PlayerState, which is too low in our case

	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);
	
}

UAbilitySystemComponent* ACC_PlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}
