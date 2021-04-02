// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include <vector>

struct FSMatrix;
struct FSVector3;


#include "Components/ActorComponent.h"
#include "STransform.generated.h"

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class LINAL_API USTransform : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	USTransform();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float                        DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;
	static FSVector3 Centre(const std::vector<FSVector3> Array);
	static FSMatrix  RotateMatrix(const FSVector3& RotationAxis, const FSVector3& Centre, const double& Degrees);
};
