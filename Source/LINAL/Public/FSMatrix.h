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
};

FORCEINLINE FSMatrix::FSMatrix()
{
}

FORCEINLINE FSMatrix::FSMatrix(const FSVector3& X, const FSVector3& Y, const FSVector3& Z, const FSVector3& W)
{
	FSVector3 v = FSVector3(1,1,1);
}