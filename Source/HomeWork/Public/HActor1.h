// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HActor1.generated.h"  //�׻�ڿ��־����, ���÷��� �ý����� �����ϴ� �������

UCLASS()
class HOMEWORK_API AHActor1 : public AActor
{
	GENERATED_BODY()
	
public:	
	AHActor1();

protected:
	
	
	USceneComponent* SceneRoot;
	UStaticMeshComponent* StaticMeshComp;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,CateGory="Actor1|Properties")
	float RotationSpeed;

	virtual void Tick(float DeltaTime) override;
	virtual void BeginPlay() override;

};
