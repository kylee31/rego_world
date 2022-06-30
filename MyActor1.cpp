// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor1.h"
#include "DrawDebugHelpers.h"

// Sets default values
AMyActor1::AMyActor1()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	root = CreateDefaultSubobject<USceneComponent>(TEXT("MyRoot"));
	RootComponent = root;

	neck = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("neck"));
	left_shoulder = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("left_shoulder"));
	right_shoulder = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("right_shoulder"));
	left_wrist = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("left_wrist"));
	right_wrist = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("right_wrist"));
	body_waist = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("body_waist"));
	left_legjoint = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("left_legjoint"));
	right_legjoint = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("right_legjoint"));

	head = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("head"));
	body = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("body"));
	left_arm = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("left_arm"));
	right_arm = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("right_arm"));
	left_hand = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("left_hand"));
	right_hand = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("right_hand"));
	waist = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("waist"));
	leg = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("leg"));
	left_leg = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("left_leg"));
	right_leg = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("right_leg"));

	static ConstructorHelpers::FObjectFinder<UStaticMesh> R_head(TEXT("StaticMesh'/Game/Lego/legohead.legohead'"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> R_body(TEXT("StaticMesh'/Game/Lego/lego_obj_Box001.lego_obj_Box001'"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> R_leftarm(TEXT("StaticMesh'/Game/Lego/lego_obj_Box004.lego_obj_Box004'"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> R_rightarm(TEXT("StaticMesh'/Game/Lego/lego_obj_Box003.lego_obj_Box003'"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> R_lefthand(TEXT("StaticMesh'/Game/Lego/lego_obj_Cylinder004.lego_obj_Cylinder004'"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> R_righthand(TEXT("StaticMesh'/Game/Lego/lego_obj_Cylinder003.lego_obj_Cylinder003'"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> R_waist(TEXT("StaticMesh'/Game/Lego/lego_obj_Box002.lego_obj_Box002'"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> R_leg(TEXT("StaticMesh'/Game/Lego/lego_obj_Cylinder002.lego_obj_Cylinder002'"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> R_leftleg(TEXT("StaticMesh'/Game/Lego/lego_obj_Plane004.lego_obj_Plane004'"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> R_rightleg(TEXT("StaticMesh'/Game/Lego/lego_obj_Plane003.lego_obj_Plane003'"));

	head->SetStaticMesh((UStaticMesh*)R_head.Object);
	body->SetStaticMesh((UStaticMesh*)R_body.Object);
	left_arm->SetStaticMesh((UStaticMesh*)R_leftarm.Object);
	right_arm->SetStaticMesh((UStaticMesh*)R_rightarm.Object);
	left_hand->SetStaticMesh((UStaticMesh*)R_lefthand.Object);
	right_hand->SetStaticMesh((UStaticMesh*)R_righthand.Object);
	waist->SetStaticMesh((UStaticMesh*)R_waist.Object);
	leg->SetStaticMesh((UStaticMesh*)R_leg.Object);
	left_leg->SetStaticMesh((UStaticMesh*)R_leftleg.Object);
	right_leg->SetStaticMesh((UStaticMesh*)R_rightleg.Object);

	waist->AttachTo(root);
	
	neck->AttachTo(body);
	head->AttachTo(neck);
	
	left_shoulder->AttachTo(body);
	left_arm->AttachTo(left_shoulder);
	right_shoulder->AttachTo(body);
	right_arm->AttachTo(right_shoulder);

	left_wrist->AttachTo(left_arm);
	left_hand->AttachTo(left_wrist);
	right_wrist->AttachTo(right_arm);
	right_hand->AttachTo(right_wrist);
	
	body_waist->AttachTo(waist);
	body->AttachTo(body_waist);
	leg->AttachTo(waist);
	left_legjoint->AttachTo(leg);
	left_leg->AttachTo(left_legjoint);
	right_legjoint->AttachTo(leg);
	right_leg->AttachTo(right_legjoint);

	/*
	//방1
	//레고 위치 ((X=-805.000000,Y=-455.000000,Z=22.000000))
	//누워있기
	t0 = 6.0f;
	//상체 일으키기
	t1 = t0 + 1.5f;
	//정지상태
	t2 = t1 + 8.0f;
	//일어나서 걷기 (12)
	t3 = t2 + 1.0f;
	t4 = t3 + 1.0f;
	t5 = t4 + 1.0f;
	t6 = t5 + 1.0f;
	t7 = t6 + 1.0f;
	t8 = t7 + 1.0f;
	t9 = t8 + 1.0f;
	t10 = t9 + 1.0f;
	t11 = t10 + 1.0f;
	t12 = t11 + 1.0f;
	t13 = t12 + 1.0f;
	t14 = t13 + 1.0f;
	t15 = t14 + 38.0;
	t16 = t15 + 1.0;
	t17 = t16 + 1.0;
	t18 = t17 + 1.0;
	t19 = t18 + 1.0;
	t20 = t19 + 1.0;
	t21 = t20 + 1.0;
	t22 = t21 + 1.0;
	t23 = t22 + 1.0;
	t24 = t23 + 1.0;
	t25 = t24 + 2.0;
	*/
	
	
	//방2 시간, 눕기, 손 흔들기
	t0 = 1.0f;
	t1 = t0 + 1.f;
	t2 = t1 + 1.0f;
	t3 = t2 + 1.0f;
	t4 = t3 + 1.0f;
	t5 = t4 + 1.0f;
	t6 = t5 + 1.0f;
	t7 = t6 + 1.0f;
	t8 = t7 + 1.0f;

}

// Called when the game starts or when spawned
void AMyActor1::BeginPlay()
{
	Super::BeginPlay();
	time = 0.f;
	//빠르게 감기 (자연스러운 걷기 위해)
	GetWorldSettings()->SetTimeDilation(1.f);
	//방1일 때는 1.f로 설정
	//비행기는 1.3f로 설정
	//방2일 때는 2.f

	//selected viewport 카메라
	if (camera_actor) {
		GetWorld()->GetFirstPlayerController()->SetViewTarget(camera_actor);
	}
	
}

bool AMyActor1::ShouldTickIfViewportsOnly() const
{
	return true;
}

// Called every frame
void AMyActor1::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (HasActorBegunPlay())
	{
		time += DeltaTime;

		FRotator k0(0, 0, 0);
		FRotator k1(0, 0, 90);

		//leg & shoulder rotation
		FRotator k2(0, 0, 315);
		FRotator k3(0, 0, 360);
		FRotator k4(0, 0, 45);
		FRotator k5(0, 0, -45);

		//neck rotation
		FRotator k6(35, 0, 0);
		FRotator k7(60, 0, 0);

		//이동
		FVector k8(0, 25, 0);

		//wrist
		FRotator k9(90, 0, 0);
		
		FRotator k10(0, 0, 180);
		FRotator k11(0, 40, 0);
		FRotator k12(0, -40, 0);
		
		//


		float t;
		int n = 25;
		//int n = 25; (방1), n=20 (방2)

		//첫번째 방 
		if (time < t0) {
			waist->SetRelativeLocation(FVector(0,0,0));
			body_waist->SetRelativeRotation(k0);
		}
		//상체 일으키기
		else if (time < t1) {
			t = (time - t0) / (t1 - t0);
			FQuat q = FQuat::Slerp(FQuat(k0), FQuat(k1), t);
			body_waist->SetRelativeRotation(q);
		}
		else if (time < t2) {

		}
		//일어나기
		else if (time < t3) {
			t = (time - t2) / (t3 - t2);
			FQuat q = FQuat::Slerp(FQuat(k0), FQuat(k1), t);
			FQuat q2 = FQuat::Slerp(FQuat(k1), FQuat(k0), t);

			body_waist->SetRelativeRotation(q2);
			waist->SetRelativeRotation(q);
			waist->SetRelativeLocation(FVector(0, 0, -1));
		}
		//걷기 (오른발 앞)
		else if (time < t4) {
			t = (time - t3) / (t4 - t3);
			FQuat q = FQuat::Slerp(FQuat(k3), FQuat(k2), t);
			FQuat q2 = FQuat::Slerp(FQuat(k0), FQuat(k4), t);

			left_shoulder->SetRelativeRotation(q);
			right_shoulder->SetRelativeRotation(q2);

			right_legjoint->SetRelativeRotation(q);
			waist->SetRelativeLocation(FVector(0, 0 + (time - t3) * n, -2));
		}
		//걷기 (오른발 제자리, 왼발 뒤)
		else if (time < t5) {
			t = (time - t4) / (t5 - t4);
			FQuat q = FQuat::Slerp(FQuat(k2), FQuat(k3), t);
			FQuat q2 = FQuat::Slerp(FQuat(k4), FQuat(k0), t);
			FQuat q3 = FQuat::Slerp(FQuat(k0), FQuat(k4), t);

			left_shoulder->SetRelativeRotation(q);
			right_shoulder->SetRelativeRotation(q2);

			left_legjoint->SetRelativeRotation(q3);
			right_legjoint->SetRelativeRotation(q);
			waist->SetRelativeLocation(FVector(0, n + (time - t4) * n, -2));
		}
		//걷기 (왼발 제자리 + 왼발 앞)
		else if (time < t6) {
			t = (time - t5) / (t6 - t5);
			FQuat q = FQuat::Slerp(FQuat(k3), FQuat(k2), t);
			FQuat q2 = FQuat::Slerp(FQuat(k0), FQuat(k4), t);
			FQuat q3 = FQuat::Slerp(FQuat(k4), FQuat(k5), t);

			left_shoulder->SetRelativeRotation(q2);
			right_shoulder->SetRelativeRotation(q);

			left_legjoint->SetRelativeRotation(q3);
			waist->SetRelativeLocation(FVector(0, 2 * n + (time - t5) * n, -2));
		}
		//걷기 (왼발 제자리, 오른발 뒤)
		else if (time < t7) {
			t = (time - t6) / (t7 - t6);
			FQuat q = FQuat::Slerp(FQuat(k2), FQuat(k3), t);
			FQuat q2 = FQuat::Slerp(FQuat(k4), FQuat(k0), t);
			FQuat q3 = FQuat::Slerp(FQuat(k5), FQuat(k0), t);
			FQuat q4 = FQuat::Slerp(FQuat(k0), FQuat(k4), t);

			left_shoulder->SetRelativeRotation(q2);
			right_shoulder->SetRelativeRotation(q);

			left_legjoint->SetRelativeRotation(q3);
			right_legjoint->SetRelativeRotation(q4);
			waist->SetRelativeLocation(FVector(0, 3 * n + (time - t6) * n, -2));
		}
		//걷기 (오른발 제자리 + 오른발 앞)
		else if (time < t8) {
			t = (time - t7) / (t8 - t7);
			FQuat q = FQuat::Slerp(FQuat(k3), FQuat(k2), t);
			FQuat q2 = FQuat::Slerp(FQuat(k0), FQuat(k4), t);
			FQuat q3 = FQuat::Slerp(FQuat(k4), FQuat(k5), t);

			left_shoulder->SetRelativeRotation(q);
			right_shoulder->SetRelativeRotation(q2);

			right_legjoint->SetRelativeRotation(q3);
			waist->SetRelativeLocation(FVector(0, 4 * n + (time - t7) * n, -2));
		}
		//걷기 (오른발 제자리, 왼발 뒤), 비행기 방향으로 고개 돌리기
		else if (time < t9) {
			t = (time - t8) / (t9 - t8);
			FQuat q = FQuat::Slerp(FQuat(k2), FQuat(k3), t);
			FQuat q2 = FQuat::Slerp(FQuat(k4), FQuat(k0), t);
			FQuat q3 = FQuat::Slerp(FQuat(k5), FQuat(k0), t);
			FQuat q4 = FQuat::Slerp(FQuat(k0), FQuat(k4), t);
			FQuat q5 = FQuat::Slerp(FQuat(k0), FQuat(k6), t);

			left_shoulder->SetRelativeRotation(q);
			right_shoulder->SetRelativeRotation(q2);

			neck->SetRelativeRotation(q5);

			left_legjoint->SetRelativeRotation(q4);
			right_legjoint->SetRelativeRotation(q3);
			waist->SetRelativeLocation(FVector(0, 5 * n + (time - t8) * n, -2));
		}
		//걷기 (왼발 제자리 + 왼발 앞)
		else if (time < t10) {
			t = (time - t9) / (t10 - t9);
			FQuat q = FQuat::Slerp(FQuat(k3), FQuat(k2), t);
			FQuat q2 = FQuat::Slerp(FQuat(k0), FQuat(k4), t);
			FQuat q3 = FQuat::Slerp(FQuat(k4), FQuat(k5), t);

			left_shoulder->SetRelativeRotation(q2);
			right_shoulder->SetRelativeRotation(q);

			left_legjoint->SetRelativeRotation(q3);
			waist->SetRelativeLocation(FVector(0, 6 * n + (time - t9) * n, -2));
		}
		//걷기 (왼발 제자리 + 오른발 뒤)
		else if (time < t11) {
			t = (time - t10) / (t11 - t10);
			FQuat q = FQuat::Slerp(FQuat(k2), FQuat(k3), t);
			FQuat q2 = FQuat::Slerp(FQuat(k4), FQuat(k0), t);
			FQuat q3 = FQuat::Slerp(FQuat(k5), FQuat(k0), t);
			FQuat q4 = FQuat::Slerp(FQuat(k0), FQuat(k4), t);

			left_shoulder->SetRelativeRotation(q2);
			right_shoulder->SetRelativeRotation(q);

			left_legjoint->SetRelativeRotation(q3);
			right_legjoint->SetRelativeRotation(q4);
			waist->SetRelativeLocation(FVector(0, 7 * n + (time - t10) * n, -2));
		}
		//걷기 (오른발 제자리 + 오른발 앞), 비행기 방향으로 고개 돌리기
		else if (time < t12) {
			t = (time - t11) / (t12 - t11);
			FQuat q = FQuat::Slerp(FQuat(k3), FQuat(k2), t);
			FQuat q2 = FQuat::Slerp(FQuat(k0), FQuat(k4), t);
			FQuat q3 = FQuat::Slerp(FQuat(k4), FQuat(k5), t);
			FQuat q4 = FQuat::Slerp(FQuat(k6), FQuat(k7), t);

			left_shoulder->SetRelativeRotation(q);
			right_shoulder->SetRelativeRotation(q2);

			neck->SetRelativeRotation(q4);

			right_legjoint->SetRelativeRotation(q3);
			waist->SetRelativeLocation(FVector(0, 8 * n + (time - t11) * n, -2));
		}
		//걷기 (오른발 제자리 + 왼발 뒤)
		else if (time < t13) {
			t = (time - t12) / (t13 - t12);
			FQuat q = FQuat::Slerp(FQuat(k2), FQuat(k3), t);
			FQuat q2 = FQuat::Slerp(FQuat(k4), FQuat(k0), t);
			FQuat q3 = FQuat::Slerp(FQuat(k5), FQuat(k0), t);
			FQuat q4 = FQuat::Slerp(FQuat(k0), FQuat(k4), t);

			left_shoulder->SetRelativeRotation(q);
			right_shoulder->SetRelativeRotation(q2);

			left_legjoint->SetRelativeRotation(q4);
			right_legjoint->SetRelativeRotation(q3);
			waist->SetRelativeLocation(FVector(0, 9 * n + (time - t12) * n, -2));
		}
		//걷기 (왼발 제자리)
		else if (time < t14) {
			t = (time - t13) / (t14 - t13);
			FQuat q = FQuat::Slerp(FQuat(k3), FQuat(k2), t);
			FQuat q2 = FQuat::Slerp(FQuat(k0), FQuat(k4), t);
			FQuat q3 = FQuat::Slerp(FQuat(k4), FQuat(k0), t);

			left_shoulder->SetRelativeRotation(q2);
			right_shoulder->SetRelativeRotation(q);

			left_legjoint->SetRelativeRotation(q3);
			waist->SetRelativeLocation(FVector(0, 10 * n + (time - t13) * n, -2));
		}
		else if (time < t15) {
			head->SetVisibility(false);
			body->SetVisibility(false);
			left_arm->SetVisibility(false);
			right_arm->SetVisibility(false);
			left_hand->SetVisibility(false);
			right_hand->SetVisibility(false);
			waist->SetVisibility(false);
			leg->SetVisibility(false);
			left_leg->SetVisibility(false);
			right_leg->SetVisibility(false);
		}
		//내리기 (setvisibility, lego 원위치), 걷기 (오른발 앞)
		else if (time < t16) {
			head->SetVisibility(true);
			body->SetVisibility(true);
			left_arm->SetVisibility(true);
			right_arm->SetVisibility(true);
			left_hand->SetVisibility(true);
			right_hand->SetVisibility(true);
			waist->SetVisibility(true);
			leg->SetVisibility(true);
			left_leg->SetVisibility(true);
			right_leg->SetVisibility(true);

			t = (time - t15) / (t16 - t15);
			FQuat q = FQuat::Slerp(FQuat(k3), FQuat(k2), t);
			FQuat q2 = FQuat::Slerp(FQuat(k0), FQuat(k4), t);

			left_shoulder->SetRelativeRotation(q);
			right_shoulder->SetRelativeRotation(q2);

			neck->SetRelativeRotation(FRotator(0, 0, 0));

			right_legjoint->SetRelativeRotation(q);
			waist->SetRelativeLocation(FVector(960 + (time - t15) * n, 1264, 377));
			waist->SetRelativeRotation(FRotator(180, 90, -90));  //(y,z,x)
		}
		// 걷기 (오른발 제자리, 왼발 뒤)
		else if (time < t17) {
			t = (time - t16) / (t17 - t16);
			FQuat q = FQuat::Slerp(FQuat(k2), FQuat(k3), t);
			FQuat q2 = FQuat::Slerp(FQuat(k4), FQuat(k0), t);
			FQuat q3 = FQuat::Slerp(FQuat(k0), FQuat(k4), t);

			left_shoulder->SetRelativeRotation(q);
			right_shoulder->SetRelativeRotation(q2);

			left_legjoint->SetRelativeRotation(q3);
			right_legjoint->SetRelativeRotation(q);
			waist->SetRelativeLocation(FVector(960 + n + (time - t16) * n, 1264, 377));
		}
		//걷기 (왼발 제자리, 왼발 앞)
		else if (time < t18) {
			t = (time - t17) / (t18 - t17);
			FQuat q = FQuat::Slerp(FQuat(k3), FQuat(k2), t);
			FQuat q2 = FQuat::Slerp(FQuat(k0), FQuat(k4), t);
			FQuat q3 = FQuat::Slerp(FQuat(k4), FQuat(k5), t);

			left_shoulder->SetRelativeRotation(q2);
			right_shoulder->SetRelativeRotation(q);

			left_legjoint->SetRelativeRotation(q3);
			waist->SetRelativeLocation(FVector(960 + 2 * n + (time - t17) * n, 1264, 377));
		}
		//걷기 (왼발 제자리), 팔 뻗기 (오른팔)
		else if (time < t19) {
			t = (time - t18) / (t19 - t18);
			FQuat q = FQuat::Slerp(FQuat(k4), FQuat(k0), t);
			FQuat q2 = FQuat::Slerp(FQuat(k5), FQuat(k0), t);

			left_shoulder->SetRelativeRotation(q);

			left_legjoint->SetRelativeRotation(q2);
			waist->SetRelativeLocation(FVector(960 + 3 * n + (time - t18) * n, 1264, 380));
		}
		//바람개비 돌리기, 팔 뻗기 (제자리)
		else if (time < t20) {
			t = (time - t19) / (t20 - t19);
			FQuat q = FQuat::Slerp(FQuat(k2), FQuat(k3), t);

			right_shoulder->SetRelativeRotation(q);
		}
		// 걷기 (왼발 앞)
		else if (time < t21) {
			t = (time - t20) / (t21 - t20);
			FQuat q = FQuat::Slerp(FQuat(k3), FQuat(k2), t);
			FQuat q2 = FQuat::Slerp(FQuat(k0), FQuat(k4), t);
			FQuat q3 = FQuat::Slerp(FQuat(k0), FQuat(k5), t);

			left_shoulder->SetRelativeRotation(q2);
			right_shoulder->SetRelativeRotation(q);

			left_legjoint->SetRelativeRotation(q3);
			waist->SetRelativeLocation(FVector(960 + 4 * n + (time - t20) * n, 1264, 380));
		}
		//걷기 (왼발 제자리, 오른발 뒤)
		else if (time < t22) {
			t = (time - t21) / (t22 - t21);
			FQuat q = FQuat::Slerp(FQuat(k2), FQuat(k3), t);
			FQuat q2 = FQuat::Slerp(FQuat(k4), FQuat(k0), t);
			FQuat q3 = FQuat::Slerp(FQuat(k5), FQuat(k0), t);
			FQuat q4 = FQuat::Slerp(FQuat(k0), FQuat(k4), t);
			
			left_shoulder->SetRelativeRotation(q2);
			right_shoulder->SetRelativeRotation(q);

			right_legjoint->SetRelativeRotation(q4);
			left_legjoint->SetRelativeRotation(q3);
			waist->SetRelativeLocation(FVector(960 + 5 * n + (time - t21) * n, 1264, 380));
		}
		//걷기 (오른발 제자리, 오른발 앞)
		else if (time < t23) {
			t = (time - t22) / (t23 - t22);
			FQuat q = FQuat::Slerp(FQuat(k3), FQuat(k2), t);
			FQuat q2 = FQuat::Slerp(FQuat(k0), FQuat(k4), t);
			FQuat q3 = FQuat::Slerp(FQuat(k4), FQuat(k5), t);
			
			left_shoulder->SetRelativeRotation(q);
			right_shoulder->SetRelativeRotation(q2);

			right_legjoint->SetRelativeRotation(q3);
			waist->SetRelativeLocation(FVector(960 + 6 * n + (time - t22) * n, 1264, 380));
		}
		//문 열기 (손목 돌리기)
		else if (time < t24) {
			t = (time - t23) / (t24 - t23);
			FQuat q = FQuat::Slerp(FQuat(k4), FQuat(k0), t);
			//FQuat q2 = FQuat::Slerp(FQuat(k5), FQuat(k0), t);
			FQuat q3 = FQuat::Slerp(FQuat(k0), FQuat(k9), t);

			right_shoulder->SetRelativeRotation(q);
			left_wrist->SetRelativeRotation(q3);

			right_legjoint->SetRelativeRotation(FRotator(0,0,0));
			waist->SetRelativeLocation(FVector(1166, 1219, 380));
			waist->SetRelativeRotation(FRotator(0, 0, 90));  //(y,z,x)
		}
		else if (time < t25) {

		}
		else {
			head->SetVisibility(false);
			body->SetVisibility(false);
			left_arm->SetVisibility(false);
			right_arm->SetVisibility(false);
			left_hand->SetVisibility(false);
			right_hand->SetVisibility(false);
			waist->SetVisibility(false);
			leg->SetVisibility(false);
			left_leg->SetVisibility(false);
			right_leg->SetVisibility(false);
		}
		

		/*
		//두번째 방 상황 (레고 침대로 이동)
		if (time < t0) {
			body_waist->SetRelativeRotation(k0);
		}
		else if (time < t1) {
			t = (time - t0) / (t1 - t0);
			FQuat q = FQuat::Slerp(FQuat(k3), FQuat(k2), t);
			FQuat q2 = FQuat::Slerp(FQuat(k0), FQuat(k4), t);

			left_shoulder->SetRelativeRotation(q);
			right_shoulder->SetRelativeRotation(q2);

			right_legjoint->SetRelativeRotation(q);
			waist->SetRelativeLocation(FVector(0, 0, 0 + (time - t0) * n));
		}
		//걷기 (오른발 제자리, 왼발 뒤)
		else if (time < t2) {
			t = (time - t1) / (t2 - t1);
			FQuat q = FQuat::Slerp(FQuat(k2), FQuat(k3), t);
			FQuat q2 = FQuat::Slerp(FQuat(k4), FQuat(k0), t);
			FQuat q3 = FQuat::Slerp(FQuat(k0), FQuat(k4), t);

			left_shoulder->SetRelativeRotation(q);
			right_shoulder->SetRelativeRotation(q2);

			left_legjoint->SetRelativeRotation(q3);
			right_legjoint->SetRelativeRotation(q);
			waist->SetRelativeLocation(FVector(0, 0, n + (time - t1) * n));
		}
		//걷기 (왼발 제자리, 왼발 앞)
		else if (time < t3) {
			t = (time - t2) / (t3 - t2);
			FQuat q = FQuat::Slerp(FQuat(k3), FQuat(k2), t);
			FQuat q2 = FQuat::Slerp(FQuat(k0), FQuat(k4), t);
			FQuat q3 = FQuat::Slerp(FQuat(k4), FQuat(k5), t);

			left_shoulder->SetRelativeRotation(q2);
			right_shoulder->SetRelativeRotation(q);

			left_legjoint->SetRelativeRotation(q3);
			waist->SetRelativeLocation(FVector(0, 0, 2 * n + (time - t2) * n));
		}
		//걷기 (왼발 제자리, 오른발 뒤)
		else if (time < t4) {
			t = (time - t3) / (t4 - t3);
			FQuat q = FQuat::Slerp(FQuat(k2), FQuat(k3), t);
			FQuat q2 = FQuat::Slerp(FQuat(k4), FQuat(k0), t);
			FQuat q3 = FQuat::Slerp(FQuat(k5), FQuat(k0), t);
			FQuat q4 = FQuat::Slerp(FQuat(k0), FQuat(k4), t);

			left_shoulder->SetRelativeRotation(q2);
			right_shoulder->SetRelativeRotation(q);

			left_legjoint->SetRelativeRotation(q3);
			right_legjoint->SetRelativeRotation(q4);
			waist->SetRelativeLocation(FVector(0, 0, 3 * n + (time - t3) * n));
		}
		//걷기 (오른발 제자리 + 오른발 앞)
		else if (time < t5) {
			t = (time - t4) / (t5 - t4);
			FQuat q = FQuat::Slerp(FQuat(k3), FQuat(k2), t);
			FQuat q2 = FQuat::Slerp(FQuat(k0), FQuat(k4), t);
			FQuat q3 = FQuat::Slerp(FQuat(k4), FQuat(k5), t);

			left_shoulder->SetRelativeRotation(q);
			right_shoulder->SetRelativeRotation(q2);

			right_legjoint->SetRelativeRotation(q3);
			waist->SetRelativeLocation(FVector(0,0, 4 * n + (time - t4) * n));
		}
		//걷기 (오른발 제자리)
		else if (time < t6) {
			t = (time - t5) / (t6 - t5);
			FQuat q = FQuat::Slerp(FQuat(k2), FQuat(k3), t);
			FQuat q2 = FQuat::Slerp(FQuat(k4), FQuat(k0), t);
			FQuat q3 = FQuat::Slerp(FQuat(k5), FQuat(k0), t);

			left_shoulder->SetRelativeRotation(q);
			right_shoulder->SetRelativeRotation(q2);

			right_legjoint->SetRelativeRotation(q3);
			waist->SetRelativeLocation(FVector(0, 0, 5 * n + (time - t5) * n));
		}
		//걷기
		else if (time < t7) {

		}
		else {

		}
		*/

		/*
		//침대에 눕기
		if (time < t0) {
			body_waist->SetRelativeRotation(k0);
		}
		if (time < t1)
		{
			t = (time - t0) / (t1 - t0);
			FQuat q = FQuat::Slerp(FQuat(k1), FQuat(k0), t);
			body_waist->SetRelativeRotation(q);
		}
		else {

		}
		*/

		/*
		//레고 위에 앉아서 손 흔들기
		//
		if (time < t0) {
			waist->SetRelativeLocation(FVector(0, 0, 0));
			body_waist->SetRelativeRotation(k0);
		}
		//상체 일으키기
		else if (time < t1) {
			t = (time - t0) / (t1 - t0);
			FQuat q = FQuat::Slerp(FQuat(k0), FQuat(k1), t);
			body_waist->SetRelativeRotation(q);
		}
		else if (time < t2) {

		}
		//손 올리기
		else if (time < t3) {
			t = (time - t2) / (t3 - t2);
			FQuat q = FQuat::Slerp(FQuat(k0), FQuat(k10), t);
			left_shoulder->SetRelativeRotation(q);
		}
		//손 흔들기
		else if (time < t4) {
			t = (time - t3) / (t4 - t3);
			FQuat q = FQuat::Slerp(FQuat(k0), FQuat(k11), t);
			left_wrist->SetRelativeRotation(q);
		}
		else if (time < t5) {
			t = (time - t4) / (t5 - t4);
			FQuat q = FQuat::Slerp(FQuat(k11), FQuat(k12), t);
			left_wrist->SetRelativeRotation(q);
		}
		//손 내리기
		else if (time < t6) {
			t = (time - t5) / (t6 - t5);
			FQuat q = FQuat::Slerp(FQuat(k10), FQuat(k0), t);
			FQuat q2 = FQuat::Slerp(FQuat(k12), FQuat(k0), t);
			left_wrist->SetRelativeRotation(q2);
			left_shoulder->SetRelativeRotation(q);
		}
		else if (time < t7) {

		}
		//일어나기
		else if (time < t8) {
			t = (time - t7) / (t8 - t7);
			FQuat q = FQuat::Slerp(FQuat(k0), FQuat(k1), t);
			FQuat q2 = FQuat::Slerp(FQuat(k1), FQuat(k0), t);

			body_waist->SetRelativeRotation(q2);
			waist->SetRelativeRotation(q);
			waist->SetRelativeLocation(FVector(0, 0, 0 + (time - t7) * -10));
		}
		*/

	}

	if (camera_actor) {
		FVector world_lego_p = waist->GetComponentLocation();
	}

}

