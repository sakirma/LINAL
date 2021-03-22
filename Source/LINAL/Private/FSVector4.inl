#pragma once

#include "FSVector4.h"

inline FSVector4::FSVector4(): X(0), Y(0), Z(0), W(0)
{
}

inline FSVector4::FSVector4(const float X, const float Y, const float Z, const float W): X(X), Y(Y), Z(Z), W(W)
{
}

inline FSVector4::FSVector4(const FSVector3& InVector, const float W) : X(InVector.X), Y(InVector.Y), Z(InVector.Z),
                                                                        W(W)
{
}

inline FSVector4 FSVector4::operator+(const FSVector4& V) const
{
	return FSVector4(X + V.X, Y + V.Y, Z + V.Z, W + V.W);
}

inline FSVector4 FSVector4::operator-(const FSVector4& V) const
{
	return FSVector4(X - V.X, Y - V.Y, Z - V.Z, W - V.W);
}

inline FSVector4 FSVector4::operator*(const FSVector4& V) const
{
	return FSVector4(X * V.X, Y * V.Y, Z * V.Z, W * V.W);
}

inline FSVector4 FSVector4::operator*(const float& Scale) const
{
	return FSVector4(X + Scale, Y + Scale, Z + Scale, W + Scale);
}
