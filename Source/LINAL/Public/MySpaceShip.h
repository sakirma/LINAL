// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "FSLine.h"
#include "GameFramework/Pawn.h"
#include "Math/FSVector3.h"

#include "MySpaceShip.generated.h"

UCLASS()
class LINAL_API AMySpaceShip : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMySpaceShip();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void         DrawCube();

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY()
	ULineBatchComponent* LineBatchComponent;

private:
	std::vector<FSVector3> Vertices {
		FSVector3(0, 0, 0),
		FSVector3(0, 0, -20),
		FSVector3(-20, 0, -20),
		FSVector3(-20, 0, 0),
		FSVector3(0, -20, 0),
		FSVector3(0, -20, -20),
		FSVector3(-20, -20, -20),
		FSVector3(-20, -20, 0),
		
		FSVector3(20, -10, -10),
		FSVector3(-40, -10, -10),
		
		FSVector3(-10, -10, 40),
	};

	std::vector<FSLine> Lines {
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

		// Wing Right
		{Vertices[8], Vertices[5]},
		{Vertices[8], Vertices[4]},
		{Vertices[8], Vertices[0]},
		{Vertices[8], Vertices[1]},

		// Wing Left
		{Vertices[9], Vertices[7]},
		{Vertices[9], Vertices[6]},
		{Vertices[9], Vertices[3]},
		{Vertices[9], Vertices[2]},

		// Nose
		{Vertices[10], Vertices[0]},
		{Vertices[10], Vertices[4]},
		{Vertices[10], Vertices[7]},
		{Vertices[10], Vertices[3]},
	};
};