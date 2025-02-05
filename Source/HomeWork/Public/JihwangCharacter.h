#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "JihwangCharacter.generated.h"

UCLASS()
class HOMEWORK_API AJihwangCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	
	AJihwangCharacter();

protected:
	
	virtual void BeginPlay() override;

public:	
	
	virtual void Tick(float DeltaTime) override;

	
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
