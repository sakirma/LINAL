// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FSVector3.generated.h"

/**
 * 
 */
USTRUCT()
struct FSVector3
{
	GENERATED_BODY()

public:
	float X, Y, Z;

	FORCEINLINE FSVector3();

	FORCEINLINE FSVector3(float X, float Y, float Z);

public:
	FORCEINLINE FSVector3 operator+(const FSVector3& V) const;
	
	FORCEINLINE FSVector3 operator-(const FSVector3& V) const;
	
	FORCEINLINE FSVector3 operator*(const FSVector3& V) const;
	
	
	FORCEINLINE FSVector3 operator-(const float& F) const;
	
	FORCEINLINE FSVector3 operator+(const float& F) const;
	
	FORCEINLINE FSVector3 operator*(const float& Scale) const;

public:
	static const FSVector3 Zero;

	static const FSVector3 Up;

	static const FSVector3 Down;

	static const FSVector3 Right;

	static const FSVector3 Left;

	static const FSVector3 Forward;

	static const FSVector3 Backward;
};

const FSVector3 FSVector3::Zero(0.0f, 0.0f, 0.0f);

const FSVector3 FSVector3::Up(0.0f, 0.0f, 1.0f);

const FSVector3 FSVector3::Down(0.0f, 0.0f, -1.0f);

const FSVector3 FSVector3::Right(0.0f, 1.f, 0.f);

const FSVector3 FSVector3::Left(0.0f, -1.f, 0.f);

const FSVector3 FSVector3::Forward(1.0f, 0.0f, 0.f);

const FSVector3 FSVector3::Backward(-1.0f, 0.0f, 0.f);

FORCEINLINE FSVector3::FSVector3(): X(0), Y(0), Z(0)
{
}

FORCEINLINE FSVector3::FSVector3(const float X, const float Y, const float Z): X(X), Y(Y), Z(Z)
{
}

inline FSVector3 FSVector3::operator+(const FSVector3& V) const
{
	return FSVector3(X + V.X, Y + V.Y, Z + V.Z);
}

inline FSVector3 FSVector3::operator-(const FSVector3& V) const
{
	return FSVector3(X - V.X, Y - V.Y, Z - V.Z);
}

inline FSVector3 FSVector3::operator*(const FSVector3& V) const
{
	return FSVector3(X * V.X, Y * V.Y, Z * V.Z);	
}

inline FSVector3 FSVector3::operator-(const float& F) const
{
	return FSVector3(X - F, Y - F, Z - F);
}

inline FSVector3 FSVector3::operator+(const float& F) const
{
	return FSVector3(X + F, Y + F, Z + F);
}

inline FSVector3 FSVector3::operator*(const float& Scale) const
{
	return FSVector3(X * Scale, Y * Scale, Z * Scale);
}
