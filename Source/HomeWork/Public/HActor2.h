// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HActor2.generated.h"

UCLASS()
class HOMEWORK_API AHActor2 : public AActor
{
	GENERATED_BODY()
	
public:	
	
	AHActor2();

protected:
	
	USceneComponent* SceneRoot;
	UStaticMeshComponent* StaticMeshComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, CateGory = "Actor2|Properties")
	float MoveSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, CateGory = "Actor2|Properties")
	FVector CurrentLocation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, CateGory = "Actor2|Properties")
	FVector EndLocation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, CateGory = "Actor2|Properties")
	FVector StartLocation;
	bool bMovingToEnd;

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

};
