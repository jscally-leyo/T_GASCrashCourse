// Copyright Leyodemus


#include "AbilitySystem/AbilityTasks/CC_WaitGameplayEvent.h"

UCC_WaitGameplayEvent* UCC_WaitGameplayEvent::WaitGameplayEventToActorProxy(AActor* TargetActor, FGameplayTag EventTag,
	bool OnlyTriggerOnce, bool OnlyMatchExact)
{
	UCC_WaitGameplayEvent* MyObj = NewObject<UCC_WaitGameplayEvent>();
	MyObj->SetAbilityActor(TargetActor);
	MyObj->Tag = EventTag;
	MyObj->OnlyTriggerOnce = OnlyTriggerOnce;
	MyObj->OnlyMatchExact = OnlyMatchExact;
	return MyObj;
}

void UCC_WaitGameplayEvent::StartActivation()
{
	Activate(); // We just need this function, but it is protected by design. By using it like this, we can call it from external classes.
}
