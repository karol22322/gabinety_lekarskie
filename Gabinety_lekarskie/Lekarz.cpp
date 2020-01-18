#include "Lekarz.h"



Lekarz::Lekarz()
{
	id = licznik;
}

Lekarz::Lekarz(string h, string im, string naz, string ad, string nr, string pesel, string spec): Osoba(h, im, naz, ad, nr, pesel), specjalizacja(spec)
{
	id = licznik;
}


Lekarz::~Lekarz()
{
}

void Lekarz::Wyswietl_dane() {
	cout << "Dane lekarza: " << endl << endl;
	cout << "Imie: " << imie << endl;
	cout << "Nazwisko: " << nazwisko << endl;
	cout << "PESEL: " << PESEL << endl;
	cout << "Adres: " << adres << endl;
	cout << "Numer telefonu: " << nrTel << endl;
	cout << "Specjalizacja: " << specjalizacja << endl << endl;

}

void Lekarz::Wystaw_recepte() {
	Recepta* r = new Recepta;

}