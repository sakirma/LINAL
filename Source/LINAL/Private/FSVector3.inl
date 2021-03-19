#pragma once

#include "FSVector3.h"

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