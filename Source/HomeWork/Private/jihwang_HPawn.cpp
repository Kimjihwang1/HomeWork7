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
	// ��Ʈ�ѷ��� �־�� ���� ����� ����
	if (!Controller) return;

	// Value�� Axis2D�� ������ IA_Move�� �Է°� (WASD)�� ��� ����
// ��) (X=1, Y=0) �� ���� / (X=-1, Y=0) �� ���� / (X=0, Y=1) �� ������ / (X=0, Y=-1) �� ����
	const FVector2D MoveInput = Value.Get<FVector2D>();

	if (!FMath::IsNearlyZero(MoveInput.X))
	{
		// ĳ���Ͱ� �ٶ󺸴� ����(����)���� X�� �̵�
		AddMovementInput(GetActorForwardVector(), MoveInput.X);
	}

	if (!FMath::IsNearlyZero(MoveInput.Y))
	{
		// ĳ������ ������ �������� Y�� �̵�
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
	// ���콺�� X, Y �������� 2D ������ ������
	FVector2D LookInput = Value.Get<FVector2D>();

	// X�� �¿� ȸ�� (Yaw), Y�� ���� ȸ�� (Pitch)
	// �¿� ȸ��
	AddControllerYawInput(LookInput.X);
	// ���� ȸ��
	AddControllerPitchInput(LookInput.Y);
	
}

void Ajihwang_HPawn::StartSprint(const FInputActionValue& Value)
{
	

}
void Ajihwang_HPawn::StopSprint(const FInputActionValue& Value)
{

}

