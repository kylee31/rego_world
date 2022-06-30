// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor4.h"

// Sets default values
AMyActor4::AMyActor4()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//레고 집 문
	root = CreateDefaultSubobject<USceneComponent>(TEXT("MyRoot"));
	RootComponent = root;

	door = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("door"));

	static ConstructorHelpers::FObjectFinder<UStaticMesh> L_door(TEXT("StaticMesh'/Game/Lego_house/Door.Door'"));

	door->SetStaticMesh((UStaticMesh*)L_door.Object);
	door->AttachTo(root);

	t0 = 76.0f;
	t1 = t0 + 2.f;
	t2 = t1 + 2.f;
	t3 = t2 + 2.f;
}

// Called when the game starts or when spawned
void AMyActor4::BeginPlay()
{
	Super::BeginPlay();
	time =0.f;
}

// Called every frame
void AMyActor4::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	time += DeltaTime;

	FRotator k0(0, 0, 0);
	FRotator k1(-120, 0, 0);

	float t;

	if (time < t0) {

	}
	//문 열기
	else if (time < t1) {
		t = (time - t0) / (t1 - t0);
		FQuat q = FQuat::Slerp(FQuat(k0), FQuat(k1), t);
		door->SetRelativeRotation(q);
	}
	else if (time < t2) {

	}
	//문 닫기
	else if (time < t3) {
		t = (time - t2) / (t3 - t2);
		FQuat q = FQuat::Slerp(FQuat(k1), FQuat(k0), t);
		door->SetRelativeRotation(q);
	}
	else {

	}
}

