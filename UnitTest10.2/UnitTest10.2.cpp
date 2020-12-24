#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest102
{
	TEST_CLASS(UnitTest102)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			std::string str = "..\\Files\\Input.txt";
			std::string res = "..\\Files\\Output.txt";

			Assert::AreEqual(res, str);
		}
	};
}
