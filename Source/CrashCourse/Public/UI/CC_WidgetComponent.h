// Copyright Leyodemus

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "Components/WidgetComponent.h"
#include "CC_WidgetComponent.generated.h"

struct FGameplayAttribute;
class UCC_AttributeSet;
class UCC_AbilitySystemComponent;
class UAbilitySystemComponent;
class ACC_BaseCharacter;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class CRASHCOURSE_API UCC_WidgetComponent : public UWidgetComponent
{
	GENERATED_BODY()

public:


protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
	TMap<FGameplayAttribute, FGameplayAttribute> AttributeMap;

private:
	TWeakObjectPtr<ACC_BaseCharacter> CrashCharacter;
	TWeakObjectPtr<UCC_AbilitySystemComponent> AbilitySystemComponent;
	TWeakObjectPtr<UCC_AttributeSet> AttributeSet;

	void InitAbilitySystemData();
	bool IsASCInitialized() const;
	// Explanation halfway through Lecture 35
	void InitializeAttributeDelegate();
	// Explanation halfway through Lecture 36
	void BindWidgetToAttributeChanges(UWidget* WidgetObject, const TTuple<FGameplayAttribute, FGameplayAttribute>& Pair) const;

	// Explanation halfway through Lecture 34
	UFUNCTION()
	void OnASCInitialized(UAbilitySystemComponent* ASC, UAttributeSet* AS);
	
	// Explanation halfway through Lecture 35
	UFUNCTION()
	void BindToAttributeChanges();

};
