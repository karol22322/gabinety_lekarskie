#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Gabinety_lekarskie/Zwolnienie.h"
#include "../Gabinety_lekarskie/Lekarz.h"
#include <iostream>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest2
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			std::string imie = "John";
			std::string nazwisko = "Miller";
			int pesel = 0;
			Zwolnienie zw;
			Lekarz lek1;
			zw.Stworz_zwolnienie("John", "Miller", 2233423,lek1, "Zwichniety nadgarstek");
			Assert::AreEqual(imie, zw.GetName());
			Assert::AreEqual(nazwisko, zw.GetSurname());
			Assert::AreEqual(pesel, zw.GetPESEL());
		}

	};
}