#include "Tests/FLinalUnitTest.h"

#include <math.h>

#include "MAth/FSMatrix.h"
#include "STransform.h"

#if WITH_DEV_AUTOMATION_TESTS
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FLinalTest1, "LINAL.Matrix Empty Matrix",
                                 EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FLinalTest1::RunTest(const FString& Parameters)
{
	FSMatrix M1{};

	for (int i = 0; i < 16; i++)
	{
		if (M1.M[i] != 0)
		{
			return false;
		}
	}

	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FLinalTest2, "LINAL.Matrix Multiplication",
                                 EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FLinalTest2::RunTest(const FString& Parameters)
{
	const FSMatrix M1 = {
		FSVector3(123, 23, 25),
		FSVector3(4124, 2341, 21),
		FSVector3(23, 231, 23),
		FSVector3(123, 123, 123),
	};

	const FSMatrix M2 = {
		FSVector3(789, 7, 89),
		FSVector3(78, 9, 7089),
		FSVector3(78, 898, 7),
		FSVector3(312, 231, 231),
	};

	FSMatrix Result = M1 * M2;

	return Result.Matrix[0][0] == 100791 && Result.Matrix[0][1] == 23518 && Result.Matrix[0][2] == 174169 &&
		Result.Matrix[0][3] == 0 && Result.Matrix[1][0] == 3438072 && Result.Matrix[1][1] == 68795 &&
		Result.Matrix[1][2] == 16962532 && Result.Matrix[1][3] == 0 && Result.Matrix[2][0] == 37959 &&
		Result.Matrix[2][1] == 22894 && Result.Matrix[2][2] == 1639767 && Result.Matrix[2][3] == 0 &&
		Result.Matrix[3][0] == 116547 && Result.Matrix[3][1] == 112653 && Result.Matrix[3][2] == 883986 &&
		Result.Matrix[3][3] == 1;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FLinalTest3, "LINAL.Matrix Multiplication *=",
                                 EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FLinalTest3::RunTest(const FString& Parameters)
{
	FSMatrix M1 = {
		FSVector3(123, 23, 25),
		FSVector3(4124, 2341, 21),
		FSVector3(23, 231, 23),
		FSVector3(123, 123, 123),
	};

	const FSMatrix M2 = {
		FSVector3(789, 7, 89),
		FSVector3(78, 9, 7089),
		FSVector3(78, 898, 7),
		FSVector3(312, 231, 231),
	};

	M1 *= M2;

	const FSMatrix ExpectedResult = {
		FSVector4(100791, 23518, 174169, 0),
		FSVector4(3438072, 68795, 16962532, 0),
		FSVector4(37959, 22894, 1639767, 0),
		FSVector4(116547, 112653, 883986, 1),
	};

	return M1 == ExpectedResult;
}


IMPLEMENT_SIMPLE_AUTOMATION_TEST(FLinalTest4, "LINAL.Matrix Scaling",
                                 EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FLinalTest4::RunTest(const FString& Parameters)
{
	FSMatrix M1 = FSMatrix::Scale(FSVector3(1, 2, 1));

	FSVector3 V{2, 2, 2};

	V = M1.TransformVector(V);

	return V.X == 2 && V.Y == 4 && V.Z == 2;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FLinalTest5, "LINAL.Matrix Transform",
                                 EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FLinalTest5::RunTest(const FString& Parameters)
{
	FSMatrix M1 = {
		FSVector4(1, 0, 0, 4),
		FSVector4(0, 1, 0, -2),
		FSVector4(0, 0, 1, 3),
		FSVector4(0, 0, 0, 1),
	};

	FSVector3 V{2, 2, 2};

	V = M1.TransformVector(V);

	return V.X == 6 && V.Y == 0 && V.Z == 5;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FLinalTest6, "LINAL.Matrix Transform Square",
                                 EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FLinalTest6::RunTest(const FString& Parameters)
{
	std::vector<FSVector3> Square = {
		{2, 2, 0},
		{5, 2, 0},
		{2, 5, 0},
		{5, 5, 0}
	};

	const FSVector3 Scale = FSVector3(2, 2, 1);

	USTransform::TransformVector(Square, USTransform::Center(Square), Scale);

	return Square[0] == FSVector3(0.5f, 0.5f, 0) && Square[1] == FSVector3(6.5f, 0.5f, 0) &&
		Square[2] == FSVector3(0.5f, 6.5f, 0) && Square[3] == FSVector3(6.5f, 6.5f, 0);
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FLinalTest7, "LINAL.Matrix Rotation Matrix",
                                 EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FLinalTest7::RunTest(const FString& Parameters)
{
	FSMatrix RotationMatrixX = FSMatrix::GetRotationX(60);
	FSMatrix RotationMatrixY = FSMatrix::GetRotationY(60);
	FSMatrix RotationMatrixZ = FSMatrix::GetRotationZ(60);

	float X[] = {
		roundf(RotationMatrixX.Matrix[1][1] * 100) / 100,
		roundf(RotationMatrixX.Matrix[2][2] * 100) / 100
	};

	float Y[] = {
		roundf(RotationMatrixY.Matrix[0][0] * 100) / 100,
		roundf(RotationMatrixY.Matrix[2][2] * 100) / 100
	};

	float Z[] = {
		roundf(RotationMatrixZ.Matrix[0][0] * 100) / 100,
		roundf(RotationMatrixZ.Matrix[1][1] * 100) / 100
	};

	if (X[0] != 0.5f && X[1] != 0.5f)
	{
		return false;
	}

	if (Y[0] != 0.5f && Y[1] != 0.5f)
	{
		return false;
	}

	if (Z[0] != 0.5f && Z[1] != 0.5f)
	{
		return false;
	}

	return true;
}


IMPLEMENT_SIMPLE_AUTOMATION_TEST(FLinalTest8, "LINAL.Matrix Centrum Matrix",
                                 EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FLinalTest8::RunTest(const FString& Parameters)
{
	const std::vector<FSVector3> Square = {
		{2, 2, 0},
		{5, 2, 0},
		{2, 5, 0},
		{5, 5, 0}
	};

	return USTransform::Center(Square) == FSVector3(3.5f, 3.5f, 0.0f);
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FLinalTest9, "LINAL.Matrix Calculation Rotation",
                                 EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FLinalTest9::RunTest(const FString& Parameters)
{
	const FSVector3 Center{-10, -10, -5.4545455};
	FSVector3       Right{0, 1, 0};

	FSVector3 Vertex = FSVector3(0, 0, 0);

	Right.Normalize();

	const auto M = USTransform::RotateMatrix(Right, Center, 180);

	Vertex       = M.TransformVector(Vertex);
	const int FX = Vertex.Z;
	if (FX == -10 && Vertex.X == -20)
	{
		return true;
	}

	return false;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FLinalTest10, "LINAL.Matrix Dot Product",
                                 EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FLinalTest10::RunTest(const FString& Parameters)
{
	const FSVector3 V1 = FSVector3::Forward;
	const FSVector3 V2 = -FSVector3::Forward;

	return FSVector3::DotProduct(V1, V2) == -1;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FLinalTest11, "LINAL.Matrix Cross Product",
                                 EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FLinalTest11::RunTest(const FString& Parameters)
{
	FSVector3 V1 = FSVector3::Forward;
	FSVector3 V2 = FSVector3::Right;

	const auto Up = FSVector3::CrossProduct(V1, V2);

	V1 = FSVector3::Up;
	V2 = FSVector3::Right;

	const auto Backwards = FSVector3::CrossProduct(V1, V2);

	if (Up != FSVector3::Up || Backwards != -FSVector3::Forward)
	{
		return false;
	}

	return true;
}

#endif //WITH_DEV_AUTOMATION_TESTS
