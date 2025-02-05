#include "jihwang_HPawn.h"
#include "JiHwang_PlayerController.h"
#include "EnhancedInputComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/BoxComponent.h"
#include "Components/SkeletalMeshComponent.h"




Ajihwang_HPawn::Ajihwang_HPawn()
{
 
	PrimaryActorTick.bCanEverTick = false;

	BoxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));
	SetRootComponent(BoxComp);

	SkeletalMeshComp = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Skeletal"));
	SkeletalMeshComp->SetupAttachment(RootComponent);
	

	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArmComp->SetupAttachment(RootComponent);
	SpringArmComp->TargetArmLength = 300.0f;
	SpringArmComp->bUsePawnControlRotation = true;

	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	CameraComp->SetupAttachment(SpringArmComp,USpringArmComponent::SocketName);
	CameraComp->bUsePawnControlRotation = false;


	MoveSpeed = 100.0f;
	TurnSpeed = 2.0f;
	bIsMovingForward = true;
	bIsMovingRight = true;
	
}
void Ajihwang_HPawn::BeginPlay()
{
	Super::BeginPlay();
	
}


void Ajihwang_HPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	

}


void Ajihwang_HPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EnhancedInput = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		if (AJiHwang_PlayerController* PlayerController = Cast<AJiHwang_PlayerController>(GetController()))
		{
			if (PlayerController->MoveAction)
			{
				EnhancedInput->BindAction(PlayerController->MoveAction, ETriggerEvent::Triggered, this, &Ajihwang_HPawn::Move);
			}
			

			if (PlayerController->LookAction)
			{
				EnhancedInput->BindAction(PlayerController->MoveAction, ETriggerEvent::Triggered, this, &Ajihwang_HPawn::Look);
			}

			
			
		}
	}
}

void Ajihwang_HPawn::Move(const FInputActionValue& Value)
{
	// 컨트롤러가 있어야 방향 계산이 가능
	if (!Controller) return;

	// Value는 Axis2D로 설정된 IA_Move의 입력값 (WASD)을 담고 있음
// 예) (X=1, Y=0) → 전진 / (X=-1, Y=0) → 후진 / (X=0, Y=1) → 오른쪽 / (X=0, Y=-1) → 왼쪽
	const FVector2D MoveInput = Value.Get<FVector2D>();

	if (!FMath::IsNearlyZero(MoveInput.X))
	{
		// 캐릭터가 바라보는 방향(정면)으로 X축 이동
		AddMovementInput(GetActorForwardVector(), MoveInput.X);
	}

	if (!FMath::IsNearlyZero(MoveInput.Y))
	{
		// 캐릭터의 오른쪽 방향으로 Y축 이동
		AddMovementInput(GetActorRightVector(), MoveInput.Y);
	}
}

void Ajihwang_HPawn::StartJump(const FInputActionValue& Value)
{
	
}

void Ajihwang_HPawn::StopJump(const FInputActionValue& Value)
{
	
}

void Ajihwang_HPawn::Look(const FInputActionValue& Value)
{ 
	// 마우스의 X, Y 움직임을 2D 축으로 가져옴
	FVector2D LookInput = Value.Get<FVector2D>();

	// X는 좌우 회전 (Yaw), Y는 상하 회전 (Pitch)
	// 좌우 회전
	AddControllerYawInput(LookInput.X);
	// 상하 회전
	AddControllerPitchInput(LookInput.Y);
	
}

void Ajihwang_HPawn::StartSprint(const FInputActionValue& Value)
{
	

}
void Ajihwang_HPawn::StopSprint(const FInputActionValue& Value)
{

}

