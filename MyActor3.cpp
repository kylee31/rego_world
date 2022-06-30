// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor3.h"

// Sets default values
AMyActor3::AMyActor3()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//바람개비
	root = CreateDefaultSubobject<USceneComponent>(TEXT("MyRoot"));
	RootComponent = root;

	pinwheel = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("pinwheel"));
	
	static ConstructorHelpers::FObjectFinder<UStaticMesh> T_pinwheel(TEXT("StaticMesh'/Game/Pinwheel/pinwheel.pinwheel'"));
	
	pinwheel->SetStaticMesh((UStaticMesh*)T_pinwheel.Object);
	pinwheel->AttachTo(root);

	t0 = 69.5;
	t1 = t0+1.0f;
}

// Called when the game starts or when spawned
void AMyActor3::BeginPlay()
{
	Super::BeginPlay();
	time = 0.f;

}

// Called every frame
void AMyActor3::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (HasActorBegunPlay())
	{
		time += DeltaTime;

		if (time < t0) {

		}
		else if (time < t1) {
			pinwheel->SetSimulatePhysics(true);
			pinwheel->SetMassOverrideInKg(NAME_None, 10.f);

			FVector torque;
			FVector axis(1.0f, 1.0f, 0);
			axis.Normalize();
			magnitute = -30.f;
			torque = axis * magnitute;

			pinwheel->AddTorque(torque);
			
			FVector F(0.f, 0.f, 980.f);
			pinwheel->AddForce(F);
		}
		else {
			pinwheel->SetSimulatePhysics(true);
			FVector F(0.f, 0.f, 980.f);
			pinwheel->AddForce(F);
		}
	}
}

