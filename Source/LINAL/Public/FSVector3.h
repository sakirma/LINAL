// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


struct FSVector3
{

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


#include "FSVector3.inl"