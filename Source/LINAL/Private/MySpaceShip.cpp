// Fill out your copyright notice in the Description page of Project Settings.


#include "MySpaceShip.h"

#include <vector>


#include "STransform.h"
#include "Components/LineBatchComponent.h"
#include "Kismet/GameplayStatics.h"
#include "MAth/FSMatrix.h"

// Sets default values
AMySpaceShip::AMySpaceShip()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	LineBatchComponent = CreateDefaultSubobject<ULineBatchComponent>(TEXT("LineBatcher"));
	UsTransform        = CreateDefaultSubobject<USTransform>(TEXT("USTransform"));
	CUsTransform       = CreateDefaultSubobject<USTransform>(TEXT("CUSTransform"));

	UsTransform->FsLineRight   = &Lines[1];
	UsTransform->FsLineUp      = &Lines[4];
	UsTransform->FsLineForward = &Lines[0];

	// Set this pawn to be controlled by the lowest-numbered player
	AutoPossessPlayer = EAutoReceiveInput::Player0;

	DrawLines();
}

// Called when the game starts or when spawned
void AMySpaceShip::BeginPlay()
{
	Super::BeginPlay();
	CameraManager = UGameplayStatics::GetPlayerCameraManager(GetWorld(), 0);
}


// Called every frame
void AMySpaceShip::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Spaceship
	{
		FSVector3 Forward = UsTransform->Forward();
		Forward.Normalize();

		FSVector3 Right = UsTransform->Right();
		Right.Normalize();

		FSVector3 Up = UsTransform->Up();
		Up.Normalize();

		UsTransform->CurrentPosition += (Forward * Input.Z + Right * Input.X + Up * Input.Y) * DeltaTime * 100.f *
			FULLTHRUSTERS;


		USTransform::TransformVector(Vertices,
		                             UsTransform->CurrentPosition,
		                             UsTransform->CurrentScale);


		LineBatchComponent->Flush();
		DrawLines();
	}


	// Spaceship Camera
	{
		CUsTransform->CurrentPosition += (FSVector3::Forward * CInput.Z + FSVector3::Right * CInput.X + FSVector3::Up *
			CInput.Y) * DeltaTime * 100.f;


		USTransform::TransformVector(CameraPosition,
		                             CUsTransform->CurrentPosition,
		                             FSVector3::One);

		const FVector v = CameraPosition[0].ToFVector();

		SetActorLocation(v, false, nullptr, ETeleportType::None);
	}
}

void AMySpaceShip::DrawLines()
{
	TArray<FBatchedLine> BatchedLines;
	for (auto i = 0; i < Lines.size(); i++)
	{
		FBatchedLine Line = FBatchedLine(Lines[i].Start.ToFVector(),
		                                 Lines[i].End.ToFVector(),
		                                 FLinearColor(1, 0, 0, 0),
		                                 0,
		                                 1,
		                                 4
		);
		BatchedLines.Add(Line);
	}
	LineBatchComponent->DrawLines(BatchedLines);
}

// Called to bind functionality to input
void AMySpaceShip::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("ForwardThrusters", this, &AMySpaceShip::MoveForward);
	PlayerInputComponent->BindAxis("SideThrusters", this, &AMySpaceShip::MoveSide);
	PlayerInputComponent->BindAxis("BottomThrusters", this, &AMySpaceShip::MoveUp);

	PlayerInputComponent->BindAxis("TurnYAxis", this, &AMySpaceShip::TurnYAxis);
	PlayerInputComponent->BindAxis("TurnXAxis", this, &AMySpaceShip::TurnXAxis);
	PlayerInputComponent->BindAxis("TurnZAxis", this, &AMySpaceShip::TurnZAxis);
	PlayerInputComponent->BindAxis("FULLTHRUSTERS", this, &AMySpaceShip::FullThrusters);

	PlayerInputComponent->BindAxis("CForwardThrusters", this, &AMySpaceShip::CMoveForward);
	PlayerInputComponent->BindAxis("CSideThrusters", this, &AMySpaceShip::CMoveSide);
	PlayerInputComponent->BindAxis("CBottomThrusters", this, &AMySpaceShip::CMoveUp);
}

void AMySpaceShip::MoveForward(const float Value)
{
	Input = FSVector3(Input.X, Input.Y, Value);
}


void AMySpaceShip::MoveSide(const float Value)
{
	Input = FSVector3(Value, Input.Y, Input.Z);
}


void AMySpaceShip::MoveUp(const float Value)
{
	Input = FSVector3(Input.X, Value, Input.Z);
}

void AMySpaceShip::TurnYAxis(const float Value)
{
	if (Value == 0)
	{
		return;
	}

	const FSVector3 Center = USTransform::Center(Vertices);
	FSVector3       Up     = UsTransform->Up();
	Up.Normalize();
	const auto M = USTransform::RotateMatrix(Up, Center, Value * 2.f);

	for (FSVector3& v : Vertices)
	{
		v = M.TransformVector(v);
	}
}

void AMySpaceShip::TurnXAxis(const float Value)
{
	if (Value == 0)
	{
		return;
	}

	const FSVector3 Center = USTransform::Center(Vertices);
	FSVector3       Right  = UsTransform->Right();
	Right.Normalize();
	const auto M = USTransform::RotateMatrix(Right, Center, Value * 2.f);

	for (FSVector3& v : Vertices)
	{
		v = M.TransformVector(v);
	}
}

void AMySpaceShip::TurnZAxis(const float Value)
{
	if (Value == 0)
	{
		return;
	}

	const FSVector3 Center  = USTransform::Center(Vertices);
	FSVector3       Forward = UsTransform->Forward();
	Forward.Normalize();
	const auto M = USTransform::RotateMatrix(Forward, Center, Value * 2.f);

	for (FSVector3& v : Vertices)
	{
		v = M.TransformVector(v);
	}
}

void AMySpaceShip::FullThrusters(const float Value)
{
	FULLTHRUSTERS = Value + 1;
}

void AMySpaceShip::CMoveForward(const float Value)
{
	CInput = FSVector3(CInput.X, CInput.Y, Value);
}

void AMySpaceShip::CMoveSide(const float Value)
{
	CInput = FSVector3(Value, CInput.Y, CInput.Z);
}

void AMySpaceShip::CMoveUp(const float Value)
{
	CInput = FSVector3(CInput.X, Value, CInput.Z);
}
