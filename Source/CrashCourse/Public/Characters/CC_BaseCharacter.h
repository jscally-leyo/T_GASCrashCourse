// Copyright Leyodemus

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"

#include "CC_BaseCharacter.generated.h"

class UGameplayAbility;

UCLASS(Abstract) // Set to (Abstract) if you design the class to just be inherited from and not to be directly instantiated 
class CRASHCOURSE_API ACC_BaseCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	ACC_BaseCharacter();
	
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

protected:
	void GiveStartupAbilities();

private:
	UPROPERTY(EditDefaultsOnly, Category = "Crash|Abilities")
	TArray<TSubclassOf<UGameplayAbility>> StartupAbilities;
};
