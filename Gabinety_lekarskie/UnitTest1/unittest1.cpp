#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Gabinety_lekarskie/Paragon.h"
#include "../Gabinety_lekarskie/Paragon.cpp"
#include "../Gabinety_lekarskie/Ubezpieczenie.h"
#include "../Gabinety_lekarskie/Ubezpieczenie.cpp"
#include "../Gabinety_lekarskie/Platnosc.h"
#include "../Gabinety_lekarskie/Platnosc.cpp"

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