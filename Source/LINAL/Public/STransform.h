// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include <vector>

#include "Math/FSVector3.h"
#include "FSLine.h"

struct FSMatrix;


#include "Components/ActorComponent.h"
#include "STransform.generated.h"

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class LINAL_API USTransform : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	USTransform();

	FSVector3 CurrentPosition = FSVector3(0, 0, 0);
	FSVector3 CurrentScale    = FSVector3(1, 1, 1);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;

	static FSVector3 Center(const std::vector<FSVector3>& Array);
	static FSMatrix RotateMatrix(const FSVector3& RotationAxis, const FSVector3& Centre, const double& Degrees);
	static void TransformVector(std::vector<FSVector3>& Array, const FSVector3& NewPosition, const FSVector3& Scale);
	static void Scale(std::vector<FSVector3>& Array, const FSVector3& Scale);

	FSLine *FsLineUp;
	FSLine *FsLineForward;
	FSLine *FsLineRight;
	
	FSVector3 Up() const;;
	FSVector3 Right() const;
	FSVector3 Forward() const;
};
