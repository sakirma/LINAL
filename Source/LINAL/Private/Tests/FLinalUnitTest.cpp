#include "Tests/FLinalUnitTest.h"

#include "FSMatrix.h"

#if WITH_DEV_AUTOMATION_TESTS


IMPLEMENT_SIMPLE_AUTOMATION_TEST(FPlaceholderTest, "TestGroup.TestSubgroup.Placeholder Test", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FPlaceholderTest::RunTest(const FString& Parameters)
{
	FSMatrix m1{};
	
	for(int i = 0; i < 16; i++)
	{
		if(m1.M[i] != 0)
		{
			return false;
		}
	}
	
	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FPlaceholderTest2, "TestGroup.TestSubgroup.Placeholder Test2", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FPlaceholderTest2::RunTest(const FString& Parameters)
{
	FSMatrix m1{};
	
	for(int i = 0; i < 16; i++)
	{
		if(m1.M[i] != 0)
		{
			return false;
		}
	}
	
	return true;
}

#endif //WITH_DEV_AUTOMATION_TESTS