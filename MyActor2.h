// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor2.generated.h"

UCLASS()
class LEGOWORLD_API AMyActor2 : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyActor2();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY()
		USceneComponent* root;

	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* mesh1;
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* key0;
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* key1;
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* key2;
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* key3;
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* key4;
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* key5;
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* key6;
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* key7;
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* key8;
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* key9;
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* key10;
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* key11;

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
		AActor* camera_actor;

	FVector plane_to_cam;

	float time;

};
