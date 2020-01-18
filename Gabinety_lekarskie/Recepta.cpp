#include "Recepta.h"
#include <iostream>



Recepta::Recepta()
{
}


Recepta::~Recepta()
{
}

void Recepta::Wydrukuj_recepte() {
	cout << "Wydruk recepty" << endl;
	cout << "Imie: " << imie << endl;
	cout << "Nazwisko: " << nazwisko << endl;
	cout << "PESEL: " << PESEL << endl;
	cout << "Lekarz: " << lekarz << endl;
	cout << "Data wystawienia: " << data_wydania << endl;
	cout << "Nazwa leku: " << nazwa_leku << endl << endl;
}
