// Fill out your copyright notice in the Description page of Project Settings.


#include "STransform.h"

#include "Math/FSMatrix.h"

// Sets default values for this component's properties
USTransform::USTransform()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	// ...
}


// Called when the game starts
void USTransform::BeginPlay()
{
	Super::BeginPlay();
}


// Called every frame
void USTransform::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

FSMatrix USTransform::RotateMatrix(const FSVector3& RotationAxis, const FSVector3& Centre, const double& Degrees)
{
	const FSMatrix Origin = FSMatrix::Transform(-Centre);

	const FSMatrix M1 = FSMatrix::GetRotationM1(RotationAxis);

	const FSMatrix M2 = FSMatrix::GetRotationM2(RotationAxis);

	const FSMatrix M3 = FSMatrix::GetRotationX(Degrees);

	const FSMatrix M4 = FSMatrix::GetRotationM4(RotationAxis);

	const FSMatrix M5 = FSMatrix::GetRotationM5(RotationAxis);

	const FSMatrix Back = FSMatrix::Transform(Centre);

	FSMatrix Result = M1 * Origin;
	Result          = M2 * Result;
	Result          = M3 * Result;
	Result          = M4 * Result;
	Result          = M5 * Result;
	Result          = Back * Result;

	return Result;
}

FSVector3 USTransform::Center(const std::vector<FSVector3>& Array)
{
	FSVector3 Result;
	for (auto& Vector : Array)
	{
		Result += Vector;
	}
	Result /= Array.size();

	return Result;
}

void USTransform::TransformVector(std::vector<FSVector3>& Array, const FSVector3& NewPosition, const FSVector3& Scale)
{
	const FSVector3 C = Center(Array);

	const FSMatrix MCenter = FSMatrix::Transform(-C);

	const FSMatrix S = FSMatrix::Scale(Scale);

	const FSMatrix MPosition = FSMatrix::Transform(NewPosition);

	//                     [ x ]
	// (S * T1) * T2 = M * | y |
	//                     [ z ]
	const FSMatrix M = MPosition * (S * MCenter);

	for (int i = 0; i < Array.size(); i++)
	{
		Array[i] = M.TransformVector(Array[i]);
	}
}

void USTransform::Scale(std::vector<FSVector3>& Array, const FSVector3& Scale)
{
	TransformVector(Array, Center(Array), Scale);
}

FSVector3 USTransform::Up() const
{
	return FSVector3(FsLineUp->Start.X - FsLineUp->End.X,
	                 FsLineUp->Start.Y - FsLineUp->End.Y,
	                 FsLineUp->Start.Z - FsLineUp->End.Z);
}

FSVector3 USTransform::Right() const
{
	return FSVector3(FsLineRight->Start.X - FsLineRight->End.X,
	                 FsLineRight->Start.Y - FsLineRight->End.Y,
	                 FsLineRight->Start.Z - FsLineRight->End.Z);
}

FSVector3 USTransform::Forward() const
{
	return FSVector3(FsLineForward->Start.X - FsLineForward->End.X,
	                 FsLineForward->Start.Y - FsLineForward->End.Y,
	                 FsLineForward->Start.Z - FsLineForward->End.Z);
}
