#pragma once

#include "FSVector4.h"
#include "FSVector3.h"

FORCEINLINE FSVector4::FSVector4(): X(0), Y(0), Z(0), W(0)
{
}

FORCEINLINE FSVector4::FSVector4(const float X, const float Y, const float Z, const float W): X(X), Y(Y), Z(Z), W(W)
{
}

FORCEINLINE FSVector4::FSVector4(const FSVector3& InVector, const float W) : X(InVector.X), Y(InVector.Y),
                                                                             Z(InVector.Z),
                                                                             W(W)
{
}

FORCEINLINE FSVector4 FSVector4::operator+(const FSVector4& V) const
{
	return FSVector4(X + V.X, Y + V.Y, Z + V.Z, W + V.W);
}

FORCEINLINE FSVector4 FSVector4::operator-(const FSVector4& V) const
{
	return FSVector4(X - V.X, Y - V.Y, Z - V.Z, W - V.W);
}

FORCEINLINE FSVector4 FSVector4::operator*(const FSVector4& V) const
{
	return FSVector4(X * V.X, Y * V.Y, Z * V.Z, W * V.W);
}

FORCEINLINE FSVector4 FSVector4::operator*(const float& Scale) const
{
	return FSVector4(X + Scale, Y + Scale, Z + Scale, W + Scale);
}

FORCEINLINE FSVector4 FSVector4::operator=(const FSVector3& V3)
{
	X = V3.X;
	Y = V3.Y;
	Z = V3.Z;
	W = 1.f;
	return *this;
}
