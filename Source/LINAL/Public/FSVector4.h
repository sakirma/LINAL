#pragma once
#include "FSVector3.h"


/**
 * 
 */
class FSVector4
{
public:
	float X, Y, Z, W;

	FORCEINLINE FSVector4();
	
	FORCEINLINE FSVector4(float X, float Y, float Z, float W);
	
	FORCEINLINE FSVector4(const FSVector3& InVector, float W = 1.0f);

public:
	FORCEINLINE FSVector4 operator+(const FSVector4& V) const;
	
	FORCEINLINE FSVector4 operator-(const FSVector4& V) const;
	
	FORCEINLINE FSVector4 operator*(const FSVector4& V) const;
	
	FORCEINLINE FSVector4 operator*(const float& Scale) const;

	
	
};

#include "FSVector4.inl"