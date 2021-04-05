// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "STransform.h"
#include "Components/ActorComponent.h"
#include "MyMissileComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class LINAL_API UMyMissileComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UMyMissileComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float                        DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;

	void Fire(float speed, FSVector3 direction);

	std::vector<FSVector3> Vertices {{0.f, 0.f, 0.f}};
	
	UPROPERTY()
	USTransform* STransform;

	FSVector3 Direction;

	float Speed;

	bool IsFired = false;
};
