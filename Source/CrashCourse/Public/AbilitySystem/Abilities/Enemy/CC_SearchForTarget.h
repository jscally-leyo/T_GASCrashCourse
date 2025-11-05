// Copyright Leyodemus

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Abilities/CC_GameplayAbility.h"
#include "CC_SearchForTarget.generated.h"

namespace EPathFollowingResult
{
	enum Type : int;
}

class UAITask_MoveTo;
class ACC_BaseCharacter;
class UCC_WaitGameplayEvent;
class AAIController;
class ACC_EnemyCharacter;
class UAbilityTask_WaitDelay;
/**
 * Lecture 57: this class is created to "replace" (some of) the BP-logic in GA_CC_SearchForTarget that was initially all done in BP
 */
UCLASS()
class CRASHCOURSE_API UCC_SearchForTarget : public UCC_GameplayAbility
{
	GENERATED_BODY()

public:
	UCC_SearchForTarget();

	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData) override;
	
	TWeakObjectPtr<ACC_EnemyCharacter> OwningEnemy;
	TWeakObjectPtr<AAIController> OwningAIController;
	TWeakObjectPtr<ACC_BaseCharacter> TargetBaseCharacter;

private:
	UPROPERTY()
	TObjectPtr<UCC_WaitGameplayEvent> WaitGameplayEventTask;

	UPROPERTY()
	TObjectPtr<UAbilityTask_WaitDelay> SearchDelayTask;

	UPROPERTY()
	TObjectPtr<UAITask_MoveTo> MoveToLocationOrActorTask;

	UPROPERTY()
	TObjectPtr<UAbilityTask_WaitDelay> AttackDelayTask;
	
	void StartSearch();

	UFUNCTION()
	void EndAttackEventReceived(FGameplayEventData Payload);

	UFUNCTION()
	void Search();

	void MoveToTargetAndAttack();

	UFUNCTION()
	void AttackTarget(TEnumAsByte<EPathFollowingResult::Type> Result, AAIController* AIController);
	
	UFUNCTION()
	void Attack();
};
