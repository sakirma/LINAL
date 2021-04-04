// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGoal.h"

#include "Components/LineBatchComponent.h"

// Sets default values
AMyGoal::AMyGoal()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	LineBatchComponent = CreateDefaultSubobject<ULineBatchComponent>(TEXT("LineBatcher"));
	UsTransform        = CreateDefaultSubobject<USTransform>(TEXT("USTransform"));
}

// Called when the game starts or when spawned
void AMyGoal::BeginPlay()
{
	Super::BeginPlay();


	USTransform::TransformVector(OGVertices,
	                             FSVector3(0, 0, 1000),
	                             FSVector3::One);
}

// Called every frame
void AMyGoal::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	Vertices = OGVertices;

	CurrentScale = sin(CurrentTime += DeltaTime) + 1;
	USTransform::Scale(Vertices, FSVector3::One * CurrentScale);

	LineBatchComponent->Flush();
	DrawLines();
}

void AMyGoal::DrawLines()
{
	TArray<FBatchedLine> BatchedLines;
	for (auto i = 0; i < Lines.size(); i++)
	{
		FBatchedLine Line = FBatchedLine(Lines[i].Start.ToFVector(),
		                                 Lines[i].End.ToFVector(),
		                                 FLinearColor(1, 0, 0, 0),
		                                 0,
		                                 4,
		                                 4
		);
		BatchedLines.Add(Line);
	}
	LineBatchComponent->DrawLines(BatchedLines);
}
