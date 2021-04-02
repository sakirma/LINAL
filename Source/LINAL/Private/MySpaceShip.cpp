// Fill out your copyright notice in the Description page of Project Settings.


#include "MySpaceShip.h"

#include <vector>


#include "SceneManagement.h"
#include "Components/LineBatchComponent.h"

// Sets default values
AMySpaceShip::AMySpaceShip()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	LineBatchComponent = CreateDefaultSubobject<ULineBatchComponent>(TEXT("LineBatcher"));
	DrawCube();
}

// Called when the game starts or when spawned
void AMySpaceShip::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AMySpaceShip::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

    
	LineBatchComponent->Flush();
    

	DrawCube();    	
}

void AMySpaceShip::DrawCube()
{
	TArray<FBatchedLine> BatchedLines;
	for (auto i = 0; i < Lines.size(); i++)
	{
		FBatchedLine Line = FBatchedLine(Lines[i].Start.ToFVector(),
            Lines[i].End.ToFVector(),
            FLinearColor(1, 0, 0, 0),
            0, // for long period draw
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

}

