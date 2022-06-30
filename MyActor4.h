// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor4.generated.h"

UCLASS()
class LEGOWORLD_API AMyActor4 : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyActor4();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//¹®
	UPROPERTY()
		USceneComponent* root;

	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* door;

	UPROPERTY(EditAnywhere)
		float t0;
	UPROPERTY(EditAnywhere)
		float t1;
	UPROPERTY(EditAnywhere)
		float t2;
	UPROPERTY(EditAnywhere)
		float t3;

	float time;
};
