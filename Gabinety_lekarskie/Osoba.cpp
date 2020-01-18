#include <string>
#include "Osoba.h"
#include <iostream>


using namespace std;


Osoba::Osoba() {
	
	licznik++;

}

Osoba::Osoba(string h, string im, string naz, string ad, string nr, string pesel):haslo(h), imie(im), nazwisko(naz), adres(ad), nrTel(nr), PESEL(pesel) {
	licznik++;
}

Osoba::~Osoba() {
}
int Osoba::licznik = 0;



void Osoba::Dodaj_osobe() {
	cout << "Imi�: ";
	cin >> imie;
	cout << "Nazwisko: ";
	cin >> nazwisko;
	cout << "Numer telefonu: "; 
	int x;
	do {
		
		cin >> nrTel;
		x = 0;
		for (int i = 0; i < static_cast<int>(nrTel.size()); i++) {
			if (nrTel[i] < '0' || nrTel[i] > '9') {
				x++;
			}
		}
	} while (x > 0);

	
	cout << "Adres zamieszkania: ";
	cin >> adres;
	cout << "PESEL: ";
	cin >> PESEL;
}

void Osoba::Tworz_konto() {

	switch (Tworz_haslo()) {
	case(0):
		Tworz_haslo();
		break;
	case(1):
		break;
	}


	Dodaj_osobe();


}

bool Osoba::Tworz_haslo() {
	string pass[2];
	cout << "Utw�rz has�o (co najmniej 10 znak�w): ";
	cin >> pass[0];
	while (pass[0].length() < 10) {
		cout << "Has�o jest za kr�tkie" << endl;
		cin >> pass[0];
	}

	cout << "Potw�rz has�o: ";
	cin >> pass[1];
	while (pass[0] != pass[1]) {
		cout << "Podane has�a nie zgadzaj� si�! Je�li chcesz wprowadzi� inne has�o wpisz x" << endl;
		cin >> pass[1];
		if (pass[1][0] == 'x') return false;
	}
	haslo = pass[0];
	return true;

}

void Osoba::Zmien_haslo() {
	string pass;
	cout << "Podaj stare has�o: ";
	cin >> pass;
	if (pass == haslo) {
		cout << "Podaj nowe has�o: ";
		cin >> haslo;
	}
	else {
		cout << "B��dne has�o!" << endl;
	}
}

void Osoba::Wyswietl_dane() {
	cout << "Dane pacjenta: " << endl << endl;
	cout << "Imie: " << imie << endl;
	cout << "Nazwisko: " << nazwisko << endl;
	cout << "PESEL: " << PESEL << endl;
	cout << "Adres: " << adres << endl;
	cout << "Numer telefonu: " << nrTel << endl << endl;

}



const string Osoba::haslo_admin = "admin123";

bool Osoba::admin(string pass) {
	if (haslo_admin == pass)
		return true;
	else
		return false;
}

ostream& operator<<(ostream& os, const Osoba& oso)
{
	os << oso.haslo << ' ' << oso.imie << ' ' << oso.nazwisko << ' ' << oso.adres << ' ' << oso.nrTel << ' ' << oso.PESEL;
	return os;
}