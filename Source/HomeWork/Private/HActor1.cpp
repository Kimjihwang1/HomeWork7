#include "HActor1.h"


AHActor1::AHActor1()
{
 	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/Resources/Props/SM_Star_B.SM_Star_B"));
	if (MeshAsset.Succeeded())
	{
		StaticMeshComp->SetStaticMesh(MeshAsset.Object);
	}
	
	static ConstructorHelpers::FObjectFinder<UMaterial> MaterialAsset(TEXT("/Game/Resources/Materials/M_Potion.M_Potion"));
	if (MaterialAsset.Succeeded())
	{
		StaticMeshComp->SetMaterial(0,MaterialAsset.Object);
	}
	
	PrimaryActorTick.bCanEverTick = true;
	RotationSpeed = 180.0f;
}


void AHActor1::BeginPlay()
{
	Super::BeginPlay();
	
}


void AHActor1::Tick(float DeltaTime)  //DeltaTime: 프레임과 프레임사이 걸린시간(초) 즉60 FPS의 DeltaTime: 1/60 =0.0167초
{
	Super::Tick(DeltaTime);

	if (!FMath::IsNearlyZero(RotationSpeed))
	{
		AddActorLocalRotation(FRotator(100, RotationSpeed * DeltaTime, 0.0f));   //Y,Z,X pitch yaw Roll
	}

}

