#include "Math/FSMatrix.h"

#include <valarray>

#include "Math/FSVector4.h"
#include "Math/FSVector3.h"

FSVector4 FSMatrix::TransformVector(const FSVector4& Vector) const
{
	FSVector4 Result;
	
	Result.X = Matrix[0][0] * Vector.X + Matrix[0][1] * Vector.Y + Matrix[0][2] * Vector.Z + Matrix[0][3] * Vector.W;
	Result.Y = Matrix[1][0] * Vector.X + Matrix[1][1] * Vector.Y + Matrix[1][2] * Vector.Z + Matrix[1][3] * Vector.W;
	Result.Z = Matrix[2][0] * Vector.X + Matrix[2][1] * Vector.Y + Matrix[2][2] * Vector.Z + Matrix[2][3] * Vector.W;
	Result.W = Matrix[3][0] * Vector.X + Matrix[3][1] * Vector.Y + Matrix[3][2] * Vector.Z + Matrix[3][3] * Vector.W;

	return Result;
}

FSMatrix::FSMatrix(): Matrix{}, M{}{}

FSMatrix::FSMatrix(const FSVector3& X, const FSVector3& Y, const FSVector3& Z, const FSVector3& W)
{
	Matrix[0][0] = X.X;
	Matrix[0][1] = X.Y;
	Matrix[0][2] = X.Z;
	Matrix[0][3] = 0.0f;

	Matrix[1][0] = Y.X;
	Matrix[1][1] = Y.Y;
	Matrix[1][2] = Y.Z;
	Matrix[1][3] = 0.0f;

	Matrix[2][0] = Z.X;
	Matrix[2][1] = Z.Y;
	Matrix[2][2] = Z.Z;
	Matrix[2][3] = 0.0f;

	Matrix[3][0] = W.X;
	Matrix[3][1] = W.Y;
	Matrix[3][2] = W.Z;
	Matrix[3][3] = 1.0f;
}

FSMatrix::FSMatrix(const FSVector4& X, const FSVector4& Y, const FSVector4& Z, const FSVector4& W)
{
	Matrix[0][0] = X.X;
	Matrix[0][1] = X.Y;
	Matrix[0][2] = X.Z;
	Matrix[0][3] = X.W;

	Matrix[1][0] = Y.X;
	Matrix[1][1] = Y.Y;
	Matrix[1][2] = Y.Z;
	Matrix[1][3] = Y.W;

	Matrix[2][0] = Z.X;
	Matrix[2][1] = Z.Y;
	Matrix[2][2] = Z.Z;
	Matrix[2][3] = Z.W;

	Matrix[3][0] = W.X;
	Matrix[3][1] = W.Y;
	Matrix[3][2] = W.Z;
	Matrix[3][3] = W.W;
}


FSMatrix FSMatrix::operator*(const FSMatrix& ROther) const
{
	FSMatrix    Result;
	auto&       NewMatrix = Result.Matrix;
	const auto& RMtr      = ROther.Matrix;
	const auto& LMtr      = Matrix;

	for (int x = 0; x < 4; x++)
	{
		for (int y = 0; y < 4; y++)
		{
			NewMatrix[x][y] =
				LMtr[x][0] * RMtr[0][y] +
				LMtr[x][1] * RMtr[1][y] +
				LMtr[x][2] * RMtr[2][y] +
				LMtr[x][3] * RMtr[3][y];
		}
	}

	return Result;
}


FSMatrix FSMatrix::operator*=(const FSMatrix& ROther)
{
	*this = *this * ROther;
	return *this;
}

FSMatrix FSMatrix::operator*(const float& Scalar) const
{
	FSMatrix    Result;
	auto&       NewMatrix = Result.Matrix;
	const auto& LMtr      = Matrix;

	for (int x = 0; x < 4; x++)
	{
		for (int y = 0; y < 4; y++)
		{
			NewMatrix[x][y] = LMtr[x][y] * Scalar;
		}
	}

	return Result;
}

FSMatrix FSMatrix::operator*=(const float& Scalar)
{
	*this = *this * Scalar;
	return *this;
}

bool FSMatrix::operator==(const FSMatrix& MOther)
{
	for (int x = 0; x < 4; x++)
	{
		for (int y = 0; y < 4; y++)
		{
			if (Matrix[x][y] != MOther.Matrix[x][y])
			{
				return false;
			}
		}
	}
	return true;
}



FSMatrix FSMatrix::Transform(const FSVector3& Vector)
{
	return FSMatrix(
		FSVector4(1.f, 0, 0, Vector.X),
		FSVector4(0, 1.f, 0, Vector.Y),
		FSVector4(0, 0, 1.f, Vector.Z),
		FSVector4(0, 0, 0, 1.f)
	);
}

FSMatrix FSMatrix::Scale(const FSVector3& Scale)
{
	return FSMatrix {
		FSVector4(Scale.X, 0, 0, 0),
        FSVector4(0, Scale.Y, 0, 0),
        FSVector4(0, 0, Scale.Z, 0),
        FSVector4(0, 0, 0, 1),
    };
}

FSMatrix FSMatrix::GetRotationX(const double AngleXDegrees)
{
	const double A = AngleXDegrees / 180 * PI;

	const FSMatrix Result{
		FSVector4(1.f, 0, 0, 0),
		FSVector4(0.f, cos(A), -sin(A), 0),
		FSVector4(0.f, sin(A), cos(A), 0),
		FSVector4(0.f, 0, 0, 1.f)
	};

	return Result;
}

FSMatrix FSMatrix::GetRotationY(const double AngleYDegrees)
{
	const double A = AngleYDegrees / 180 * PI;

	const FSMatrix Result{
		FSVector4(cos(A), 0.f, sin(A), 0.f),
		FSVector4(0.f, 1.f, 0.f, 0.f),
		FSVector4(-sin(A), 0.0f, cos(A), 0.f),
		FSVector4(0.f, 0.f, 0.f, 1.f)
	};

	return Result;
}

FSMatrix FSMatrix::GetRotationZ(const double AngleZDegrees)
{
	const double A = AngleZDegrees / 180 * PI;

	const FSMatrix Result{
		FSVector4(cos(A), -sin(A), 0.0f, 0.f),
		FSVector4(sin(A), cos(A), 0.f, 0.f),
		FSVector4(0.0f, 0.0f, 1.f, 0.f),
		FSVector4(0.f, 0.f, 0.f, 1.f)
	};

	return Result;
}

FSMatrix FSMatrix::GetRotationM1(const FSVector3& RotationAxis)
{
	const double XZ = std::sqrt(RotationAxis.X * RotationAxis.X + RotationAxis.Z * RotationAxis.Z);

	if (XZ == 0)
	{
		return FSMatrix(
			FSVector4(1, 0, 0, 0),
			FSVector4(0, 1, 0, 0),
			FSVector4(0, 0, 1, 0),
			FSVector4(0, 0, 0, 1)
		);
	}

	return FSMatrix(
		FSVector4(RotationAxis.X / XZ, 0, RotationAxis.Z / XZ, 0),
		FSVector4(0, 1, 0, 0),
		FSVector4(-RotationAxis.Z / XZ, 0, RotationAxis.X / XZ, 0),
		FSVector4(0, 0, 0, 1)
	);
}

FSMatrix FSMatrix::GetRotationM2(const FSVector3& RotationAxis)
{
	const double XZ  = std::sqrt(RotationAxis.X * RotationAxis.X + RotationAxis.Z * RotationAxis.Z);
	const double XYZ = std::sqrt(
		RotationAxis.X * RotationAxis.X + RotationAxis.Y * RotationAxis.Y + RotationAxis.Z * RotationAxis.Z);

	return FSMatrix(
		FSVector4(XZ / XYZ, RotationAxis.Y / XYZ, 0, 0),
		FSVector4(-RotationAxis.Y / XYZ, XZ / XYZ, 0, 0),
		FSVector4(0, 0, 1, 0),
		FSVector4(0, 0, 0, 1)
	);
}

FSMatrix FSMatrix::GetRotationM4(const FSVector3& RotationAxis)
{
	const double XZ  = std::sqrt(RotationAxis.X * RotationAxis.X + RotationAxis.Z * RotationAxis.Z);
	const double XYZ = std::sqrt(
		RotationAxis.X * RotationAxis.X + RotationAxis.Y * RotationAxis.Y + RotationAxis.Z * RotationAxis.Z);

	return FSMatrix(
		FSVector4(XZ / XYZ, -RotationAxis.Y / XYZ, 0, 0),
		FSVector4(RotationAxis.Y / XYZ, XZ / XYZ, 0, 0),
		FSVector4(0, 0, 1, 0),
		FSVector4(0, 0, 0, 1)
	);
}

FSMatrix FSMatrix::GetRotationM5(const FSVector3& RotationAxis)
{
	const double XZ = std::sqrt(RotationAxis.X * RotationAxis.X + RotationAxis.Z * RotationAxis.Z);

	if (XZ == 0)
	{
		return FSMatrix(
			FSVector4(1, 0, 0, 0),
			FSVector4(0, 1, 0, 0),
			FSVector4(0, 0, 1, 0),
			FSVector4(0, 0, 0, 1)
		);
	}

	return FSMatrix(
		FSVector4(RotationAxis.X / XZ, 0, -RotationAxis.Z / XZ, 0),
		FSVector4(0, 1, 0, 0),
		FSVector4(RotationAxis.Z / XZ, 0, RotationAxis.X / XZ, 0),
		FSVector4(0, 0, 0, 1)
	);
}