// Copyright Leyodemus

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Abilities/CC_GameplayAbility.h"
#include "CC_Primary.generated.h"

UCLASS()
class CRASHCOURSE_API UCC_Primary : public UCC_GameplayAbility
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Crash|Abilities")
	void HitBoxOverlapTest();

private:
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Crash|Abilities", meta = (AllowPrivateAccess = "true"))
	float HitBoxRadius = 100.0f;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Crash|Abilities", meta = (AllowPrivateAccess = "true"))
	float HitBoxForwardOffset = 200.0f;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Crash|Abilities", meta = (AllowPrivateAccess = "true"))
	float HitBoxElevationOffset = 20.0f;
};
