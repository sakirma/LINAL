#pragma once

#include "CoreMinimal.h"

#include "FSVector3.h"

#include "FSMatrix.generated.h"

/**
* 
*/
USTRUCT()
struct FSMatrix
{
	GENERATED_BODY()


public:
	float Matrix[4][4];

	FORCEINLINE FSMatrix();
	
	FORCEINLINE FSMatrix::FSMatrix(const FSVector3& X, const FSVector3& Y, const FSVector3& Z, const FSVector3& W);
};

