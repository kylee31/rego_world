// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor2.h"

// Sets default values
AMyActor2::AMyActor2()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	root = CreateDefaultSubobject<USceneComponent>(TEXT("MyRoot"));
	RootComponent = root;

	mesh1 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MyMesh1"));

	//ÀÌ·ת1
	key0 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("key0"));
	key1 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("key1"));
	key2 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("key2"));
	key3 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("key3"));
	key4 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("key4"));
	key5 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("key5"));
	key6 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("key6"));
	key7 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("key7"));
	key8 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("key8"));
	key9 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("key9"));
	key10 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("key10"));
	key11 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("key11"));

	static ConstructorHelpers::FObjectFinder<UStaticMesh> PlaneAsset(TEXT("StaticMesh'/Game/Toy_airplane/airplane.airplane'"));

	if (PlaneAsset.Succeeded()) {
		UStaticMesh* m = PlaneAsset.Object;

		mesh1->SetStaticMesh(m);
		key0->SetStaticMesh(m);
		key1->SetStaticMesh(m);
		key2->SetStaticMesh(m);
		key3->SetStaticMesh(m);
		key4->SetStaticMesh(m);
		key5->SetStaticMesh(m);
		key6->SetStaticMesh(m);
		key7->SetStaticMesh(m);
		key8->SetStaticMesh(m);
		key9->SetStaticMesh(m);
		key10->SetStaticMesh(m);
		key11->SetStaticMesh(m);
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("PlaneAsset Fail"));
	}

	mesh1->AttachTo(root);
	key0->AttachTo(root);
	key1->AttachTo(root);
	key2->AttachTo(root);
	key3->AttachTo(root);
	key4->AttachTo(root);
	key5->AttachTo(root);
	key6->AttachTo(root);
	key7->AttachTo(root);
	key8->AttachTo(root);
	key9->AttachTo(root);
	key10->AttachTo(root);
	key11->AttachTo(root);

	key0->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, 100.f), FRotator(0.0f, 0.0f, 0.0f));
	key1->SetRelativeLocationAndRotation(FVector(100.0f, 100.0f, 200.f), FRotator(0.0f, 30.0f, 90.0f));
	key2->SetRelativeLocationAndRotation(FVector(100.0f, 100.0f, 300.f), FRotator(0.0f, 30.0f, 90.0f));
	key3->SetRelativeLocationAndRotation(FVector(100.0f, 100.0f, 300.f), FRotator(0.0f, 0.0f, 0.0f));
	key4->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, 100.f), FRotator(0.0f, 0.0f, 0.0f));
	key5->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, 100.f), FRotator(0.0f, 0.0f, 0.0f));
	key6->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, 100.f), FRotator(0.0f, 0.0f, 0.0f));
	key7->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, 100.f), FRotator(0.0f, 0.0f, 0.0f));
	key8->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, 100.f), FRotator(0.0f, 0.0f, 0.0f));
	key9->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, 100.f), FRotator(0.0f, 0.0f, 0.0f));
	key10->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, 100.f), FRotator(0.0f, 0.0f, 0.0f));
	key11->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, 100.f), FRotator(0.0f, 0.0f, 0.0f));

	t0 = 33.0f; //+27.5
	t1 = t0 + 2.f;
	t2 = t1 + 2.f;
	t3 = t2 + 2.f;
	t4 = t3 + 2.f;
	t5 = t4 + 2.f;
	t6 = t5 + 2.f;
	t7 = t6 + 2.0f;
	t8 = t7 + 2.0f;
	t9 = t8 + 2.0f;
	t10 = t9 + 2.0f;
	t11 = t10 + 8.0f;
}

// Called when the game starts or when spawned
void AMyActor2::BeginPlay()
{
	Super::BeginPlay();

	time = 0.f;
	
	if (camera_actor) {
		GetWorld()->GetFirstPlayerController()->SetViewTarget(camera_actor);
		plane_to_cam = (camera_actor->GetActorLocation() - key0->GetComponentLocation());
	}
}

// Called every frame
void AMyActor2::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	time += DeltaTime;

	FVector p0 = key0->GetRelativeLocation();
	FVector p1 = key1->GetRelativeLocation();
	FVector p2 = key2->GetRelativeLocation();
	FVector p3 = key3->GetRelativeLocation();
	FVector p4 = key4->GetRelativeLocation();
	FVector p5 = key5->GetRelativeLocation();
	FVector p6 = key6->GetRelativeLocation();
	FVector p7 = key7->GetRelativeLocation();
	FVector p8 = key8->GetRelativeLocation();
	FVector p9 = key9->GetRelativeLocation();
	FVector p10 = key10->GetRelativeLocation();
	FVector p11 = key11->GetRelativeLocation();

	FQuat q0 = FQuat(key0->GetRelativeRotation());
	FQuat q1 = FQuat(key1->GetRelativeRotation());
	FQuat q2 = FQuat(key2->GetRelativeRotation());
	FQuat q3 = FQuat(key3->GetRelativeRotation());
	FQuat q4 = FQuat(key4->GetRelativeRotation());
	FQuat q5 = FQuat(key5->GetRelativeRotation());
	FQuat q6 = FQuat(key6->GetRelativeRotation());
	FQuat q7 = FQuat(key7->GetRelativeRotation());
	FQuat q8 = FQuat(key8->GetRelativeRotation());
	FQuat q9 = FQuat(key9->GetRelativeRotation());
	FQuat q10 = FQuat(key10->GetRelativeRotation());
	FQuat q11 = FQuat(key11->GetRelativeRotation());

	FVector p;
	FQuat q;

	if (time < t0) {
		p = key0->GetRelativeLocation();
		q = FQuat(key0->GetRelativeRotation());
	}
	else if (time < t1) {
		p = FMath::CubicCRSplineInterpSafe(p0, p0, p1, p2, t0 - 1.f, t0, t1, t2, time);
		q = FMath::CubicCRSplineInterpSafe(q0, q0, q1, q2, t0 - 1.f, t0, t1, t2, time);
	}
	else if (time < t2) {
		p = FMath::CubicCRSplineInterpSafe(p0, p1, p2, p3, t0, t1, t2, t3, time);
		q = FMath::CubicCRSplineInterpSafe(q0, q1, q2, q3, t0, t1, t2, t3, time);
	}
	else if (time < t3) {
		p = FMath::CubicCRSplineInterpSafe(p1, p2, p3, p4, t1, t2, t3, t4, time);
		q = FMath::CubicCRSplineInterpSafe(q1, q2, q3, q4, t1, t2, t3, t4, time);
	}
	else if (time < t4) {
		p = FMath::CubicCRSplineInterpSafe(p2, p3, p4, p5, t2, t3, t4, t5, time);
		q = FMath::CubicCRSplineInterpSafe(q2, q3, q4, q5, t2, t3, t4, t5, time);
	}
	else if (time < t5) {
		p = FMath::CubicCRSplineInterpSafe(p3, p4, p5, p6, t3, t4, t5, t6, time);
		q = FMath::CubicCRSplineInterpSafe(q3, q4, q5, q6, t3, t4, t5, t6, time);
	}
	else if (time < t6) {
		p = FMath::CubicCRSplineInterpSafe(p4, p5, p6, p7, t4, t5, t6, t7, time);
		q = FMath::CubicCRSplineInterpSafe(q4, q5, q6, q7, t4, t5, t6, t7, time);
	}
	else if (time < t7) {
		p = FMath::CubicCRSplineInterpSafe(p5, p6, p7, p8, t5, t6, t7, t8, time);
		q = FMath::CubicCRSplineInterpSafe(q5, q6, q7, q8, t5, t6, t7, t8, time);
	}
	else if (time < t8) {
		p = FMath::CubicCRSplineInterpSafe(p6, p7, p8, p9, t6, t7, t8, t9, time);
		q = FMath::CubicCRSplineInterpSafe(q6, q7, q8, q9, t6, t7, t8, t9, time);
	}
	else if (time < t9) {
		p = FMath::CubicCRSplineInterpSafe(p7, p8, p9, p10, t7, t8, t9, t10, time);
		q = FMath::CubicCRSplineInterpSafe(q7, q8, q9, q10, t7, t8, t9, t10, time);
	}
	else if (time < t10) {
		p = FMath::CubicCRSplineInterpSafe(p8, p9, p10, p11, t8, t9, t10, t11, time);
		q = FMath::CubicCRSplineInterpSafe(q8, q9, q10, q11, t8, t9, t10, t11, time);
	}
	else if (time < t11) {
		p = FMath::CubicCRSplineInterpSafe(p9, p10, p11, p11, t9, t10, t11, t11+1.f, time);
		q = FMath::CubicCRSplineInterpSafe(q9, q10, q11, q11, t9, t10, t11, t11+1.f, time);
	}
	else {
		p = key11->GetRelativeLocation();
		q = FQuat(key11->GetRelativeRotation());
	}

	key0->SetVisibility(false);
	key1->SetVisibility(false);
	key2->SetVisibility(false);
	key3->SetVisibility(false);
	key4->SetVisibility(false);
	key5->SetVisibility(false);
	key6->SetVisibility(false);
	key7->SetVisibility(false);
	key8->SetVisibility(false);
	key9->SetVisibility(false);
	key10->SetVisibility(false);
	key11->SetVisibility(false);
	
	mesh1->SetRelativeLocationAndRotation(p, q);

	if (camera_actor) {

		FVector world_plane_p = mesh1->GetComponentLocation();
		camera_actor->SetActorLocation(world_plane_p + plane_to_cam);
	}
}


