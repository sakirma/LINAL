#pragma once


#if WITH_DEV_AUTOMATION_TESTS

class FLinalUnitTest : public FAutomationTestBase 
{

	
public:
	FLinalUnitTest(const FString& InName, const bool bInComplexTask)
        : FAutomationTestBase(InName, bInComplexTask)
	{
	}
};

#endif //WITH_DEV_AUTOMATION_TESTS
