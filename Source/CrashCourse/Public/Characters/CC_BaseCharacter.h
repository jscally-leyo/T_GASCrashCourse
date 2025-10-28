// Copyright Leyodemus

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"

#include "CC_BaseCharacter.generated.h"

class UAttributeSet;
class UGameplayEffect;
class UGameplayAbility;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FASCInitialized, UAbilitySystemComponent*, ASC, UAttributeSet*, AS); // Explanation halfway through Lecture 34

UCLASS(Abstract) // Set to (Abstract) if you design the class to just be inherited from and not to be directly instantiated 
class CRASHCOURSE_API ACC_BaseCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	ACC_BaseCharacter();
	
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	virtual UAttributeSet* GetAttributeSet() const {return nullptr;}; // Will need overrides in the child classes

	UPROPERTY(BlueprintAssignable)
	FASCInitialized OnASCInitialized; // Check ECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FASCInitialized, ...) up top of this class

protected:
	void GiveStartupAbilities();
	void InitializeAttributes() const;

private:
	UPROPERTY(EditDefaultsOnly, Category = "Crash|Abilities")
	TArray<TSubclassOf<UGameplayAbility>> StartupAbilities;

	UPROPERTY(EditDefaultsOnly, Category = "Crash|Effects")
	TSubclassOf<UGameplayEffect> InitializeAttributesEffect;
};
