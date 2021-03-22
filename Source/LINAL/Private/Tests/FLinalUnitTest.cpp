#include "Tests/FLinalUnitTest.h"

#include "FSMatrix.h"

#if WITH_DEV_AUTOMATION_TESTS
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FLinalTest1, "LINAL.Matrix Empty Matrix", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FLinalTest1::RunTest(const FString& Parameters)
{
	FSMatrix M1{};
	
	for(int i = 0; i < 16; i++)
	{
		if(M1.M[i] != 0)
		{
			return false;
		}
	}
	
	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FLinalTest2, "LINAL.Matrix Multiplication", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
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

	if(Result.Matrix[0][0] == 100791 && Result.Matrix[0][1] == 23518 && Result.Matrix[0][2] == 174169 && Result.Matrix[0][3] == 0 &&
		Result.Matrix[1][0] == 3438072 && Result.Matrix[1][1] == 68795 && Result.Matrix[1][2] == 16962532 &&  Result.Matrix[1][3] == 0 &&
		Result.Matrix[2][0] == 37959 && Result.Matrix[2][1] == 22894 && Result.Matrix[2][2] == 1639767 &&  Result.Matrix[2][3] == 0 &&
		Result.Matrix[3][0] == 116547 && Result.Matrix[3][1] == 112653 && Result.Matrix[3][2] == 883986 &&  Result.Matrix[3][3] == 1)
	{
		return true;
	} 
	
	return false;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FLinalTest3, "LINAL.Matrix Multiplication *=", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
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

	if(M1.Matrix[0][0] == 100791 && M1.Matrix[0][1] == 23518 && M1.Matrix[0][2] == 174169 && M1.Matrix[0][3] == 0 &&
        M1.Matrix[1][0] == 3438072 && M1.Matrix[1][1] == 68795 && M1.Matrix[1][2] == 16962532 &&  M1.Matrix[1][3] == 0 &&
        M1.Matrix[2][0] == 37959 && M1.Matrix[2][1] == 22894 && M1.Matrix[2][2] == 1639767 &&  M1.Matrix[2][3] == 0 &&
        M1.Matrix[3][0] == 116547 && M1.Matrix[3][1] == 112653 && M1.Matrix[3][2] == 883986 &&  M1.Matrix[3][3] == 1)
	{
		return true;
	} 
	
	return false;
}

#endif //WITH_DEV_AUTOMATION_TESTS