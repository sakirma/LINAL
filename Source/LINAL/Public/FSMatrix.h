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

	FSMatrix operator*(const float& Scalar) const
	{
		FSMatrix Result;
		auto& NewMatrix = Result.Matrix;
		const auto& LMtr = Matrix;

		for (int x = 0; x < 4; x++)
		{
			for (int y = 0; y < 4; y++)
			{
				NewMatrix[x][y] = LMtr[x][y] * Scalar;
			}
		}

		return Result;
	}
};

#include "FSMatrix.inl"
