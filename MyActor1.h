// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor1.generated.h"

UCLASS()
class LEGOWORLD_API AMyActor1 : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyActor1();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual bool ShouldTickIfViewportsOnly() const override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	//레고 전체
	UPROPERTY()
		USceneComponent* root; 

	UPROPERTY(EditAnywhere)
		USceneComponent* neck;
	UPROPERTY(EditAnywhere)
		USceneComponent* left_shoulder;
	UPROPERTY(EditAnywhere)
		USceneComponent* right_shoulder;
	UPROPERTY(EditAnywhere)
		USceneComponent* left_wrist;
	UPROPERTY(EditAnywhere)
		USceneComponent* right_wrist;
	UPROPERTY(EditAnywhere)
		USceneComponent* body_waist;
	UPROPERTY(EditAnywhere)
		USceneComponent* left_legjoint;
	UPROPERTY(EditAnywhere)
		USceneComponent* right_legjoint;

	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* head;
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* body;
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* left_arm;
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* right_arm;
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* left_hand;
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* right_hand;
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* waist;
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* leg;
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* left_leg;
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* right_leg;

	UPROPERTY(EditAnywhere)
		float t0;
	UPROPERTY(EditAnywhere)
		float t1;
	UPROPERTY(EditAnywhere)
		float t2;
	UPROPERTY(EditAnywhere)
		float t3;
	UPROPERTY(EditAnywhere)
		float t4;
	UPROPERTY(EditAnywhere)
		float t5;
	UPROPERTY(EditAnywhere)
		float t6;
	UPROPERTY(EditAnywhere)
		float t7;
	UPROPERTY(EditAnywhere)
		float t8;
	UPROPERTY(EditAnywhere)
		float t9;
	UPROPERTY(EditAnywhere)
		float t10;
	UPROPERTY(EditAnywhere)
		float t11;
	UPROPERTY(EditAnywhere)
		float t12;
	UPROPERTY(EditAnywhere)
		float t13;
	UPROPERTY(EditAnywhere)
		float t14;
	UPROPERTY(EditAnywhere)
		float t15;
	UPROPERTY(EditAnywhere)
		float t16;
	UPROPERTY(EditAnywhere)
		float t17;
	UPROPERTY(EditAnywhere)
		float t18;
	UPROPERTY(EditAnywhere)
		float t19;
	UPROPERTY(EditAnywhere)
		float t20;
	UPROPERTY(EditAnywhere)
		float t21;
	UPROPERTY(EditAnywhere)
		float t22;
	UPROPERTY(EditAnywhere)
		float t23;
	UPROPERTY(EditAnywhere)
		float t24;
	UPROPERTY(EditAnywhere)
		float t25;


	UPROPERTY(EditAnywhere)
		AActor* camera_actor;

	FVector lego_to_cam;

	float time;
};
