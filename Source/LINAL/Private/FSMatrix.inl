// Fill out your copyright notice in the Description page of Project Settings.


#pragma once

#include "FSMatrix.h"

FORCEINLINE FSMatrix::FSMatrix()
{
}

FORCEINLINE FSMatrix::FSMatrix(const FSVector3& X, const FSVector3& Y, const FSVector3& Z, const FSVector3& W)
{
	Matrix[0][0] = X.X; Matrix[0][1] = X.Y;  Matrix[0][2] =  X.Z;  Matrix[0][3] = 0.0f;
	Matrix[1][0] = Y.X; Matrix[1][1] = Y.Y;  Matrix[1][2] =  Y.Z;  Matrix[1][3] = 0.0f;
	Matrix[2][0] = Z.X; Matrix[2][1] = Z.Y;  Matrix[2][2] =  Z.Z;  Matrix[2][3] = 0.0f;
	Matrix[3][0] = W.X; Matrix[3][1] = W.Y;  Matrix[3][2] =  W.Z;  Matrix[3][3] = 1.0f;
}