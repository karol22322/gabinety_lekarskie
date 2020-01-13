#include "CppUnitTest.h"
#include "../Gabinety_lekarskie/Paragon.h"
#include "../Gabinety_lekarskie/Ubezpieczenie.h"
#include "../Gabinety_lekarskie/Platnosc.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using system;
using system.io

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Platnosc p;
			float f = 0;
			Assert::AreEqual(p.ile() , f);
			
		}

	};
}