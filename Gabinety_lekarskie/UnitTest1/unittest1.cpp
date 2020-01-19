#include "pch.h"
#include "CppUnitTest.h"
#include "../Paragon.h"
#include "../Ubezpieczenie.h"
#include "../Platnosc.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;
namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			Platnosc p;
			float f = 0;
			Assert::AreEqual(p.ile(), f);

		}

	};
}