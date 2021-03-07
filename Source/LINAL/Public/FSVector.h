// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FSVector.generated.h"

/**
 * 
 */
USTRUCT()
struct FSVector
{
	GENERATED_BODY()

public:
	float X, Y, Z;

	FORCEINLINE FSVector();

	FORCEINLINE FSVector(float X, float Y, float Z);

public:
	FORCEINLINE FSVector operator+(const FSVector& V) const;
	
	FORCEINLINE FSVector operator-(const FSVector& V) const;
	
	FORCEINLINE FSVector operator*(const FSVector& V) const;
	
	
	FORCEINLINE FSVector operator-(const float& F) const;
	
	FORCEINLINE FSVector operator+(const float& F) const;
	
	FORCEINLINE FSVector operator*(const float& Scale) const;

public:
	static const FSVector Zero;

	static const FSVector Up;

	static const FSVector Down;

	static const FSVector Right;

	static const FSVector Left;

	static const FSVector Forward;

	static const FSVector Backward;
};

const FSVector FSVector::Zero(0.0f, 0.0f, 0.0f);

const FSVector FSVector::Up(0.0f, 0.0f, 1.0f);

const FSVector FSVector::Down(0.0f, 0.0f, -1.0f);

const FSVector FSVector::Right(0.0f, 1.f, 0.f);

const FSVector FSVector::Left(0.0f, -1.f, 0.f);

const FSVector FSVector::Forward(1.0f, 0.0f, 0.f);

const FSVector FSVector::Backward(-1.0f, 0.0f, 0.f);

FORCEINLINE FSVector::FSVector(): X(0), Y(0), Z(0)
{
}

FORCEINLINE FSVector::FSVector(const float X, const float Y, const float Z): X(X), Y(Y), Z(Z)
{
}

inline FSVector FSVector::operator+(const FSVector& V) const
{
	return FSVector(X + V.X, Y + V.Y, Z + V.Z);
}

inline FSVector FSVector::operator-(const FSVector& V) const
{
	return FSVector(X - V.X, Y - V.Y, Z - V.Z);
}

inline FSVector FSVector::operator*(const FSVector& V) const
{
	return FSVector(X * V.X, Y * V.Y, Z * V.Z);	
}

inline FSVector FSVector::operator-(const float& F) const
{
	return FSVector(X - F, Y - F, Z - F);
}

inline FSVector FSVector::operator+(const float& F) const
{
	return FSVector(X + F, Y + F, Z + F);
}

inline FSVector FSVector::operator*(const float& Scale) const
{
	return FSVector(X * Scale, Y * Scale, Z * Scale);
}
