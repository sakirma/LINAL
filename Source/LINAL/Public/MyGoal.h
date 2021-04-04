// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "STransform.h"

#include "GameFramework/Actor.h"
#include "MyGoal.generated.h"

UCLASS()
class LINAL_API AMyGoal : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AMyGoal();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void         DrawLines();


	UPROPERTY()
	ULineBatchComponent* LineBatchComponent;

private:
	float CurrentScale = 1;
	float CurrentTime = 1;

	
	UPROPERTY()
	USTransform* UsTransform;

	std::vector<FSVector3> OGVertices {
		FSVector3(0, 0, 0),
        FSVector3(0, 0, -100),
        FSVector3(-100, 0, -100),
        FSVector3(-100, 0, 0),
        FSVector3(0, -100, 0),
        FSVector3(0, -100, -100),
        FSVector3(-100, -100, -100),
        FSVector3(-100, -100, 0),
    };
	
	std::vector<FSVector3> Vertices {
		FSVector3(0, 0, 0),
		FSVector3(0, 0, -100),
		FSVector3(-100, 0, -100),
		FSVector3(-100, 0, 0),
		FSVector3(0, -100, 0),
		FSVector3(0, -100, -100),
		FSVector3(-100, -100, -100),
		FSVector3(-100, -100, 0),
	};

	std::vector<FSLine> Lines{
		{Vertices[0], Vertices[1]},
		{Vertices[1], Vertices[2]},
		{Vertices[2], Vertices[3]},
		{Vertices[3], Vertices[0]},

		{Vertices[0], Vertices[4]},
		{Vertices[1], Vertices[5]},
		{Vertices[2], Vertices[6]},
		{Vertices[3], Vertices[7]},

		{Vertices[4], Vertices[5]},
		{Vertices[5], Vertices[6]},
		{Vertices[6], Vertices[7]},
		{Vertices[7], Vertices[4]},
	};
};
