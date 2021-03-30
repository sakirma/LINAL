#pragma once
#include <vector>


struct FSVector4;

struct FSVector3
{
public:
	float X, Y, Z;

	FORCEINLINE FSVector3();

	FORCEINLINE FSVector3(float X, float Y, float Z);

public:
	FORCEINLINE FSVector3 operator+(const FSVector3& V) const;

	FORCEINLINE FSVector3 operator-(const FSVector3& V) const;

	FORCEINLINE FSVector3 operator-() const;

	FORCEINLINE FSVector3 operator*(const FSVector3& V) const;

	FORCEINLINE FSVector3 operator*(const float& Scalar) const;

	FORCEINLINE FSVector3 operator=(const FSVector4& V);

	FORCEINLINE bool       operator==(const FSVector3& SVector3) const;
	FORCEINLINE FSVector3 operator+=(const FSVector3& Value);

	FORCEINLINE FSVector3 operator/(float Division) const;
	FORCEINLINE FSVector3 operator/=(float Division);


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
