#include "pch.h"
#include "CppUnitTest.h"
#include "../Termin.h"



using namespace Microsoft::VisualStudio::CppUnitTestFramework;
namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			Termin t;
			bool ter = true;
			Assert::AreEqual(t.Czy_wolny(), ter);

		}

	};
}