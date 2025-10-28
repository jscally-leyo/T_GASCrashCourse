// Copyright Leyodemus

#pragma once

#include "CoreMinimal.h"
#include "Components/WidgetComponent.h"
#include "CC_WidgetComponent.generated.h"

class UCC_AttributeSet;
class UCC_AbilitySystemComponent;
class UAttributeSet;
class UAbilitySystemComponent;
class ACC_BaseCharacter;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class CRASHCOURSE_API UCC_WidgetComponent : public UWidgetComponent
{
	GENERATED_BODY()

public:


protected:
	virtual void BeginPlay() override;

private:
	TWeakObjectPtr<ACC_BaseCharacter> CrashCharacter;
	TWeakObjectPtr<UCC_AbilitySystemComponent> AbilitySystemComponent;
	TWeakObjectPtr<UCC_AttributeSet> AttributeSet;

	void InitAbilitySystemData();
	bool IsASCInitialized() const;

	UFUNCTION()
	void OnASCInitialized(UAbilitySystemComponent* ASC, UAttributeSet* AS);
};
