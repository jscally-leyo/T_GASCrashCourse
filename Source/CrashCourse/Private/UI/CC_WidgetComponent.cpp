// Copyright Leyodemus

#include "UI/CC_WidgetComponent.h"

#include "AbilitySystem/CC_AbilitySystemComponent.h"
#include "AbilitySystem/CC_AttributeSet.h"
#include "Characters/CC_BaseCharacter.h"

void UCC_WidgetComponent::BeginPlay()
{
	Super::BeginPlay();

	InitAbilitySystemData();

	if(!IsASCInitialized())
	{
		CrashCharacter->OnASCInitialized.AddDynamic(this, &ThisClass::OnASCInitialized);
	}
	
}

void UCC_WidgetComponent::InitAbilitySystemData()
{
	CrashCharacter = Cast<ACC_BaseCharacter>(GetOwner());
	AttributeSet = Cast<UCC_AttributeSet>(CrashCharacter->GetAttributeSet());
	AbilitySystemComponent = Cast<UCC_AbilitySystemComponent>(CrashCharacter->GetAbilitySystemComponent());
}

bool UCC_WidgetComponent::IsASCInitialized() const
{
	return AbilitySystemComponent.IsValid() && AttributeSet.IsValid();
}

void UCC_WidgetComponent::OnASCInitialized(UAbilitySystemComponent* ASC, UAttributeSet* AS)
{
	AbilitySystemComponent = Cast<UCC_AbilitySystemComponent>(ASC);
	AttributeSet = Cast<UCC_AttributeSet>(AS);

	// TODO: check if the attribute set has been initialized with the first GameplayEffect
	// if not: bind to some delegate that will be broadcast when it is initialized
}
