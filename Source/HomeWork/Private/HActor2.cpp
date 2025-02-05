#include "HActor2.h"

// Sets default values
AHActor2::AHActor2()
{
	PrimaryActorTick.bCanEverTick = true;
	
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/Resources/Props/SM_Potion_A.SM_Potion_A"));
	if (MeshAsset.Succeeded())
	{
		StaticMeshComp->SetStaticMesh(MeshAsset.Object);
	}

	static ConstructorHelpers::FObjectFinder<UMaterial> MaterialAsset(TEXT("/Game/Resources/Materials/M_Heart.M_Heart"));
	if (MaterialAsset.Succeeded())
	{
		StaticMeshComp->SetMaterial(0, MaterialAsset.Object);
	}

	StartLocation = FVector(0.0f, 0.0f, 0.0f);
	EndLocation = FVector(1000.0f, 0.0f, 0.0f);
	CurrentLocation = StartLocation;
	MoveSpeed = 200.0f;
	bMovingToEnd = true;
	
} 


void AHActor2::BeginPlay()
{
	Super::BeginPlay();
	
	SetActorLocation(StartLocation);
}


void AHActor2::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//FVector TargetLocation;
	FVector TargetLocation = bMovingToEnd ? EndLocation : StartLocation;
	/*if (bMovingToEnd)
	{
		TargetLocation = CurrentLocation;
	}
	else
	{
		TargetLocation = StartLocation;
	}*/

	FVector Direction = (TargetLocation - CurrentLocation).GetSafeNormal();
	CurrentLocation += Direction * MoveSpeed * DeltaTime;

	if (FVector::Dist(CurrentLocation, TargetLocation) < 10.0f)
	{
		bMovingToEnd = !bMovingToEnd;
	}

	SetActorLocation(CurrentLocation);
	


	


}

