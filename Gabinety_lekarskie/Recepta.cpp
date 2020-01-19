#include "Recepta.h"
#include <iostream>
#include "Lekarz.h"
#include <ctime>  

using namespace std;
Recepta::Recepta()
{
}


Recepta::~Recepta()
{
}
void Recepta::Stworz_recepte(string imie,string nazw, int pesel, Lekarz lekarz,string nazwa) {
	this->imie = imie;
	this->nazwisko = nazwisko;
	this->PESEL = pesel;
	this->lekarz = lekarz;
	this->data_wydania = 0;
	this->nazwa_leku = nazwa;


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
