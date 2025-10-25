// Copyright Leyodemus

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CC_BaseCharacter.generated.h"

UCLASS(Abstract) // Set to (Abstract) if you design the class to just be inherited from and not to be directly instantiated 
class CRASHCOURSE_API ACC_BaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ACC_BaseCharacter();

};
