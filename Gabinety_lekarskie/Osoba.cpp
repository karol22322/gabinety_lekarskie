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
	cout << "Imiê: ";
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

void Osoba::Edytuj_dane() {
	string napis;
	cout << "Podaj has³o: ";
	cin >> napis;
	if (napis == haslo) {
		int i;
		cout << "Imiê(1), Nazwisko(2), Adres(3), Numer telefonu(4): ";
		cin >> i;
		cout << "WprowadŸ nowe dane: ";
		switch (i) {
		case 1: {
			cin >> imie;
			break;
		}
		case 2: {
			cin >> nazwisko;
			break;
		}
		case 3: {
			cin >> adres;
			break;
		}
		case 4: {
			cin >> nrTel;
			break;
		}
		}
	}
	else {
		cout << "B³êdne has³o!" << endl;
	}
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
	cout << "Utwórz has³o (co najmniej 10 znaków): ";
	cin >> pass[0];
	while (pass[0].length() < 10) {
		cout << "Has³o jest za krótkie" << endl;
		cin >> pass[0];
	}

	cout << "Potwórz has³o: ";
	cin >> pass[1];
	while (pass[0] != pass[1]) {
		cout << "Podane has³a nie zgadzaj¹ siê! Jeœli chcesz wprowadziæ inne has³o wpisz x" << endl;
		cin >> pass[1];
		if (pass[1][0] == 'x') return false;
	}
	haslo = pass[0];
	return true;

}

void Osoba::Zmien_haslo() {
	string pass;
	cout << "Podaj stare has³o: ";
	cin >> pass;
	if (pass == haslo) {
		cout << "Podaj nowe has³o: ";
		cin >> haslo;
	}
	else {
		cout << "B³êdne has³o!" << endl;
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