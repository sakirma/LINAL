#pragma once

#include "FSVector3.h"

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