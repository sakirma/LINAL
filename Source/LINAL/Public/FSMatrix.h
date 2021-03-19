#pragma once


#include "FSVector3.h"

/**
* 
*/
struct FSMatrix
{
public:
	float Matrix[4][4];

	FORCEINLINE FSMatrix();

	FORCEINLINE FSMatrix(const FSVector3& X, const FSVector3& Y, const FSVector3& Z, const FSVector3& W);

	FORCEINLINE FSMatrix operator*(const FSMatrix& ROther) const;
	FORCEINLINE void operator*=(const FSMatrix& ROther);
	FORCEINLINE FSMatrix operator*(const float& Scalar) const;
	FORCEINLINE void operator*=(const float& Scalar);
};

#include "FSMatrix.inl"
