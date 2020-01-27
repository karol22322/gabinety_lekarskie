#include "pch.h"
#include "CppUnitTest.h"
#include "../Recepta.h"
#include "../Recepta.cpp"
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
		TEST_METHOD(TestMethod2)
		{
			Termin t;
			t.Pesel("99803212");
			string pesel = "99803212";
			Assert::AreEqual(t.Print_Pesel(), pesel);

		}
		TEST_METHOD(TestMethod3)
		{
			Termin t(1,2,"W");
			t.Rezerwuj();
			bool ter = false;
			Assert::AreEqual(t.Czy_wolny(), false);

		}
		TEST_METHOD(TestMethod4)
		{
			Termin t(1, 2, "W");
			t.Pesel("99803212");
			string pesel = "99803212";
			bool ter = true;
			Assert::AreEqual(t.Czy_Pesel(pesel), true);

		}

		TEST_METHOD(TestMethod5)
		{
			string a[10];
			string p = "1234"
			Recepta r(a, 3, p);
			Assert::AreEqual(r.Czy_Pesel(p), true);

		}


	};
}