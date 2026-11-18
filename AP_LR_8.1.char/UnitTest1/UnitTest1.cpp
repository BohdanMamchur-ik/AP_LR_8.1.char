#include "pch.h"
#include "CppUnitTest.h"
#include "../AP_LR_8.1.char/AP_LR_8.1.char.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest81Char
{
	TEST_CLASS(UnitTest81Char)
	{
	public:

		TEST_METHOD(TestCountAndChangeChar)
		{
			char str[101] = "abbbbcddddde";

			int count = Count(str);
			Assert::AreEqual(2, count);

			char* res = Change(str);
			Assert::AreEqual("ab**c**de", str);
			Assert::AreEqual("ab**c**de", res);
		}
	};
}