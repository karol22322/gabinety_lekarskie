#include "Zwolnienie.h"
#include <iostream>



Zwolnienie::Zwolnienie()
{
	Pacjent();
}


Zwolnienie::~Zwolnienie()
{
}

void Zwolnienie::Stworz_zwolnienie(string imie, string nazw, int pesel, Lekarz lekarz, string opis) {
	this->imie = imie;
	this->nazwisko = nazwisko;
	this->PESEL = pesel;
	this->lekarz = lekarz;
	this->data_wystawienia = 0;
	this->termin_zwolnienia = 0;
	this->tresc = opis;


}


void Zwolnienie::Wydrukuj_zwolnienie() {
	cout << "Wydruk recepty" << endl;
	cout << "Imie: " << imie << endl;
	cout << "Nazwisko: " << nazwisko << endl;
	cout << "PESEL: " << PESEL << endl;
	cout << "Lekarz: " << lekarz << endl;
	cout << "Data wystawienia: " << data_wystawienia << endl;
	cout << "Termin zwolnienia: " << termin_zwolnienia << endl;
	cout << "Tresc: " << tresc << endl << endl;
}
