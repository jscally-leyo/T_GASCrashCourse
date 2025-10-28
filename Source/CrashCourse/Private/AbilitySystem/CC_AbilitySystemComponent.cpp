// Copyright Leyodemus

#include "AbilitySystem/CC_AbilitySystemComponent.h"

#include "GameplayTags/CCTags.h"

void UCC_AbilitySystemComponent::OnGiveAbility(FGameplayAbilitySpec& AbilitySpec)
{
	Super::OnGiveAbility(AbilitySpec);

	HandleAutoActivatedAbility(AbilitySpec);
}

void UCC_AbilitySystemComponent::OnRep_ActivateAbilities()
{
	Super::OnRep_ActivateAbilities();

	FScopedAbilityListLock ActiveScopeLock(*this); // Prevents accessing an ability that has been removed
	for (const FGameplayAbilitySpec& AbilitySpec : GetActivatableAbilities())
	{
		HandleAutoActivatedAbility(AbilitySpec);
	}
}

void UCC_AbilitySystemComponent::SetAbilityLevel(TSubclassOf<UGameplayAbility> AbilityClass, int32 Level)
{
	// We only want to do this on the server
	if (IsValid(GetAvatarActor()) && !GetAvatarActor()->HasAuthority()) return;

	if (FGameplayAbilitySpec* AbilitySpec = FindAbilitySpecFromClass(AbilityClass))
	{
		AbilitySpec->Level = Level;
		MarkAbilitySpecDirty(*AbilitySpec); // This triggers replication, also to BP
	}
	
}

void UCC_AbilitySystemComponent::AddToAbilityLevel(TSubclassOf<UGameplayAbility> AbilityClass, int32 Level)
{
	// We only want to do this on the server!
	// ...but when called on a client this should also work, by using a GameplayAbility (which we don't do here)
	// OR we could do this in BP as explained in Lecture 40 at the end
	if (IsValid(GetAvatarActor()) && !GetAvatarActor()->HasAuthority()) return;

	if (FGameplayAbilitySpec* AbilitySpec = FindAbilitySpecFromClass(AbilityClass))
	{
		AbilitySpec->Level += Level;
		MarkAbilitySpecDirty(*AbilitySpec); // This triggers replication, also to BP
	}
}

void UCC_AbilitySystemComponent::HandleAutoActivatedAbility(const FGameplayAbilitySpec& AbilitySpec)
{
	if (!IsValid(AbilitySpec.Ability)) return;
	
	for (const FGameplayTag& Tag : AbilitySpec.Ability->GetAssetTags())
	{
		if (Tag.MatchesTagExact(CCTags::CCAbilities::ActivateOnGiven))
		{
			TryActivateAbility(AbilitySpec.Handle);
			return; // No need to continue the loop if tag was found
		}
	}
}
