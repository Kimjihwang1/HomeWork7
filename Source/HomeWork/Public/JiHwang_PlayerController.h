#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "JiHwang_PlayerController.generated.h"


class UInputMappingContext;  //IMC���� ���� ����
class UInputAction; //IA ���� ���� ����

UCLASS()
class HOMEWORK_API AJiHwang_PlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AJiHwang_PlayerController();

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category = "Input")
	UInputMappingContext* InputMappingContext;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	UInputAction* MoveAction;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	UInputAction* JumpAction;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	UInputAction* LookAction;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	UInputAction* SprintAction;

	virtual void BeginPlay() override;
	
	
};
