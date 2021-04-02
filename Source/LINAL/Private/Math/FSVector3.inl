#pragma once

#include "FSVector3.h"
#include "FSVector4.h"


FORCEINLINE FSVector3::FSVector3(): X(0), Y(0), Z(0)
{
}

FORCEINLINE FSVector3::FSVector3(const float X, const float Y, const float Z): X(X), Y(Y), Z(Z)
{
}

FORCEINLINE FSVector3 FSVector3::operator+(const FSVector3& V) const
{
	return FSVector3(X + V.X, Y + V.Y, Z + V.Z);
}

FORCEINLINE FSVector3 FSVector3::operator-(const FSVector3& V) const
{
	return FSVector3(X - V.X, Y - V.Y, Z - V.Z);
}

FORCEINLINE FSVector3 FSVector3::operator+=(const FSVector3& Value)
{
	*this = *this + Value;
	return *this;
}

FORCEINLINE FSVector3 FSVector3::operator/(float Division) const
{
	return FSVector3(X / Division, Y / Division, Z / Division);
}

FORCEINLINE FSVector3 FSVector3::operator/=(float Division)
{
	*this = *this / Division;
	return *this;
}

inline FVector FSVector3::ToFVector() const
{
	return FVector(Z, X, Y);
}

FORCEINLINE FSVector3 FSVector3::operator-() const
{
	return FSVector3(-X, -Y, -Z);
}

FORCEINLINE FSVector3 FSVector3::operator*(const FSVector3& V) const
{
	return FSVector3(X * V.X, Y * V.Y, Z * V.Z);	
}

FORCEINLINE FSVector3 FSVector3::operator*(const float& Scalar) const
{
	return FSVector3(X * Scalar, Y * Scalar, Z * Scalar);
}

FORCEINLINE FSVector3 FSVector3::operator=(const FSVector4& V)
{
	X = V.X;
	Y = V.Y;
	Z = V.Z;
	return *this;
}

FORCEINLINE bool FSVector3::operator==(const FSVector3& SVector3) const
{
	return X == SVector3.X && Y == SVector3.Y && Z == SVector3.Z;
}