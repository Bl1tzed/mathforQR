#include "pch.h"
#include "CppUnitTest.h"
#include "../math/Source.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
		std:double b = 2.5;
			Assert::AreEqual(b, bruh());
		}
	};
}
