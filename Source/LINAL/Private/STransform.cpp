// Fill out your copyright notice in the Description page of Project Settings.


#include "STransform.h"

#include "FSMatrix.h"

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

	FSMatrix m1 = FSMatrix(
		FSVector3(2.f,3.f,3.f),
		FSVector3(3.f,2.f,3.f),
		FSVector3(3.f,3.f,3.f),
		FSVector3(2.f,2.f,2.f)
		);

	FSMatrix m2 = FSMatrix(
		FSVector3(3.f,3.f,3.f),
		FSVector3(3.f,3.f,3.f),
		FSVector3(2.f,2.f,3.f),
		FSVector3(3.f,3.f,2.f)
		);
	
	FSMatrix rm = m1 * m2;

	FSMatrix scalarM = FSMatrix();

	scalarM = m1 * 2.0f;
}


// Called every frame
void USTransform::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

