// Fill out your copyright notice in the Description page of Project Settings.


#include "MyMissileComponent.h"

// Sets default values for this component's properties
UMyMissileComponent::UMyMissileComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	STransform = CreateDefaultSubobject<USTransform>(TEXT("STransform"));
	// ...
}


// Called when the game starts
void UMyMissileComponent::BeginPlay()
{
	Super::BeginPlay();
}


// Called every frame
void UMyMissileComponent::TickComponent(float                        DeltaTime, ELevelTick TickType,
                                        FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if(!IsFired)
		return;
	
	STransform->CurrentPosition += Direction * DeltaTime * Speed;


	USTransform::TransformVector(Vertices,
	                             STransform->CurrentPosition,
	                             STransform->CurrentScale);

	const FVector v = Vertices[0].ToFVector();

	GetOwner()->SetActorLocation(v, false, nullptr, ETeleportType::None);
}

void UMyMissileComponent::Fire(float speed, FSVector3 direction)
{
	this->Speed     = speed;
	this->Direction = direction;

	STransform->CurrentPosition = Vertices[0] = FSVector3::FromFVector(GetOwner()->GetActorLocation());


	FRotator Rot = FRotationMatrix::MakeFromX(Direction.ToFVector()).Rotator();
	GetOwner()->SetActorRotation(Rot);

	Rot = FRotationMatrix::MakeFromY(Direction.ToFVector()).Rotator();
	GetOwner()->SetActorRotation(Rot);

	Rot = FRotationMatrix::MakeFromZ(Direction.ToFVector()).Rotator();
	GetOwner()->SetActorRotation(Rot);

	IsFired = true;
}
