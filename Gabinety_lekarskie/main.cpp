#pragma warning(disable : 4996)
#include "Pacjent.h"
#include "Paragon.h"
#include "Ubezpieczenie.h"
#include "Platnosc.h"
#include "Lekarz.h"
#include <list>
#include <vector>
#include <fstream>
#include <ctime>

using namespace std;


list<Pacjent> pacjenci;
list<Lekarz> lekarze;

fstream baza;

void wyswietl_lekarzy() {
	for (list<Lekarz>::iterator iter = lekarze.begin(); iter != lekarze.end(); ++iter ) {
		iter->Lekarz::Wyswietl_dane();
	}
}

void wyswietl_pacjentow() {
	for (list<Pacjent>::iterator iter = pacjenci.begin(); iter != pacjenci.end(); ++iter) {
		iter->Wyswietl_dane();
		
	}
}


void wyborp2(char x, string PESEL, string h) {
	cout << "\nSaldo(1)\nZmiana has³a(2)\nMoje dane(3)\nEdycja danych(4)\nWizyty(5)\nTerminarz(6)\nLekarze(7)\nMoje recepty i zwolnienia(8)\nWyjœcie(x)\n";
	cin >> x;
	switch (x) {
	case('1'): {
		for (list<Pacjent>::iterator iter = pacjenci.begin(); iter != pacjenci.end(); iter++) {

			if (PESEL == iter->PESEL) {
				cout <<"Twoje saldo: "<< iter->Wyswietl_saldo() << endl;
			}
			
		}
		break;


	}
	case('2'): {
		for (list<Pacjent>::iterator iter = pacjenci.begin(); iter != pacjenci.end(); ++iter) {

			if (PESEL == iter->PESEL) {
				iter->Zmien_haslo();
				baza.open("Baza.txt", ios::in);

				string linia;
				vector<string> linijki;
				while (getline(baza, linia))                     //wczytywanie z pliku
				{
					linijki.push_back(linia);
				}
				baza.close();
				baza.open("Baza.txt", ios::out);


				unsigned i = 0;
				for (i = 0; i < linijki.size(); i++)
				{
					if (linijki[i].find(iter->PESEL) != string::npos)         //jakiœ sposób znalezienia liniki, któr¹ chcesz zmieniæ
						break;
				}
				int j = i;

				for (unsigned i = 0; i < linijki.size(); i++) //wypisanie i wpisanie do pliku
				{
					if (i + 1 == linijki.size()) {
						if (i == j) {
							baza << "p " << *iter;
						}
						else {
							baza << linijki[i];
						}
					}
					else {
						if (i == j) {
							baza << "p " << *iter << endl;
						}
						else {
							baza << linijki[i] << endl;
						}
					}

				}
				cout << endl;
			}
		}
		break;

	}

	case('3'): {

		int i = 0;
		for (list<Pacjent>::iterator iter = pacjenci.begin(); iter != pacjenci.end(); iter++) {

			if (PESEL == iter->PESEL) {
				iter->Wyswietl_dane();
			}	
		}
		break;
	}

	case('4'): {
		int i = 0;
		for (list<Pacjent>::iterator iter = pacjenci.begin(); iter != pacjenci.end(); ++iter) {

			if (PESEL == iter->PESEL) {
				i++;
				iter->Edytuj_dane();
				baza.open("Baza.txt", ios::in);

				string linia;
				vector<string> linijki;
				while (getline(baza, linia))                     //wczytywanie z pliku
				{
					linijki.push_back(linia);
				}
				baza.close();
				baza.open("Baza.txt", ios::out);


				unsigned i = 0;
				for (i = 0; i < linijki.size(); i++)
				{
					if (linijki[i].find(iter->PESEL) != string::npos)         //jakiœ sposób znalezienia liniki, któr¹ chcesz zmieniæ
						break;
				}
				int j = i;

				for (unsigned i = 0; i < linijki.size(); i++) //wypisanie i wpisanie do pliku
				{
					if (i + 1 == linijki.size()) {
						if (i == j) {
							baza << "p " << *iter;
						}
						else {
							baza << linijki[i];
						}
					}
					else {
						if (i == j) {
							baza << "p " << *iter << endl;
						}
						else {
							baza << linijki[i] << endl;
						}
					}

				}
				cout << endl;
			}
		}
		if (i == 0)
			cout << "Nie ma konta o danym numerze PESEL" << endl;
		break;

	}

	case('6'): {
		
		

		break;
	}
	case('7'): {
		for (list<Lekarz>::iterator iter = lekarze.begin(); iter != lekarze.end(); iter++) {
			cout << iter->imie << ' ' << iter->nazwisko << ' ' << iter->specjal() << endl;
		}
		break;
	}
			 
	}
	if (x != 'x')
		wyborp2(x, PESEL, h);
}

void wyborp() {
	char x;
	string PESEL;
	string h;
	cout << "\nCo chcesz zrobiæ?" << endl;
	cout << "Za³o¿enie konta(1)\nLogowanie(2)\n";
	cin >> x;
	switch (x) {
	case('1'): {
		Pacjent p;
		p.Tworz_konto();
		pacjenci.push_back(p);
		baza.open("Baza.txt", ios::out | ios::app);
		baza << "\np " << p;

		break;
	}
	case('2'): {
		cout << "Podaj PESEL: ";
		cin >> PESEL;
		
		
		int i = 0;
		for (list<Pacjent>::iterator iter = pacjenci.begin(); iter != pacjenci.end(); ++iter) {

			if (PESEL == iter->PESEL) {
				i++;
				cout << "Podaj has³o: ";
				cin >> h;
				if (h != iter->haslo) {
					cout << "B³êdne has³o";
				}
				else {
					wyborp2(x, PESEL, h);
					
				}
			}

		}

		if (i == 0)
			cout << "Nie posiadasz jeszcze konta" << endl;
	}
	}
}

void wyborl2(char x, string PESEL, string h){
	cout << "Zmiana has³a(1)\nMoje dane(2)\nEdycja danych(3)\nWizyty(4)\nTerminarz(5)\nMoi pacjenci(6)\nRecepty(7)\nZwolnienia(8)\nWyjœcie(x)\n";
	cin >> x;
	switch (x) {
	case('1'): {
		for (list<Lekarz>::iterator iter = lekarze.begin(); iter != lekarze.end(); ++iter) {

			if (PESEL == iter->PESEL) {
				iter->Zmien_haslo();
				baza.open("Baza.txt", ios::in);

				string linia;
				vector<string> linijki;
				while (getline(baza, linia))                     //zczytywanie z pliku
				{
					linijki.push_back(linia);
				}
				baza.close();
				baza.open("Baza.txt", ios::out);


				unsigned i = 0;
				for (i = 0; i < linijki.size(); i++)
				{
					if (linijki[i].find(iter->PESEL) != string::npos)         //jakiœ sposób znalezienia liniki, któr¹ chcesz zmieniæ
						break;
				}
				int j = i;

				for (unsigned i = 0; i < linijki.size(); i++) //wypisanie i wpisanie do pliku
				{
					if (i + 1 == linijki.size()) {
						if (i == j) {
							baza << "l " << *iter;
						}
						else {
							baza << linijki[i];
						}
					}
					else {
						if (i == j) {
							baza << "l " << *iter << endl;
						}
						else {
							baza << linijki[i] << endl;
						}
					}

				}
				cout << endl;
			}
		}
		break;

	}
	case('2'): {
		for (list<Lekarz>::iterator iter = lekarze.begin(); iter != lekarze.end(); iter++) {

			if (PESEL == iter->PESEL) {
				iter->Wyswietl_dane();
			}
		}
		break;
	}
	case('3'): {
		int i = 0;
		for (list<Lekarz>::iterator iter = lekarze.begin(); iter != lekarze.end(); ++iter) {

			if (PESEL == iter->PESEL) {
				i++;
				iter->Edytuj_dane();
				baza.open("Baza.txt", ios::in);

				string linia;
				vector<string> linijki;
				while (getline(baza, linia))                     //wczytywanie z pliku
				{
					linijki.push_back(linia);
				}
				baza.close();
				baza.open("Baza.txt", ios::out);


				unsigned i = 0;
				for (i = 0; i < linijki.size(); i++)
				{
					if (linijki[i].find(iter->PESEL) != string::npos)         //jakiœ sposób znalezienia liniki, któr¹ chcesz zmieniæ
						break;
				}
				int j = i;

				for (unsigned i = 0; i < linijki.size(); i++) //wypisanie i wpisanie do pliku
				{
					if (i + 1 == linijki.size()) {
						if (i == j) {
							baza << "l " << *iter;
						}
						else {
							baza << linijki[i];
						}
					}
					else {
						if (i == j) {
							baza << "l " << *iter << endl;
						}
						else {
							baza << linijki[i] << endl;
						}
					}

				}
				cout << endl;
			}
		}
		if (i == 0)
			cout << "Nie ma konta o danym numerze PESEL" << endl;
		break;

	
	}
	}
	if (x != 'x') {
		wyborl2(x, PESEL, h);
	}

}

void wyborl(){
	cout << "Podaj has³o admina: ";
	string haslo;
	cin >> haslo;
	if (Osoba::admin(haslo) == true) {
			char x;
			string PESEL;
			string h;
			cout << "\nCo chcesz zrobiæ?" << endl;
			cout << "Za³o¿enie konta(1)\nLogowanie(2)\n";
			cin >> x;
			switch (x) {
			case('1'): {
				Lekarz l;
				l.Tworz_konto();
				l.Wprowadz_specjalizacje();
				lekarze.push_back(l);
				baza.open("Baza.txt", ios::out | ios::app);
				baza << "\nl " << l;

				break;
			}
			case('2'): {
				cout << "Podaj PESEL: ";
				cin >> PESEL;

				int i = 0;
				for (list<Lekarz>::iterator iter = lekarze.begin(); iter != lekarze.end(); ++iter) {

					if (PESEL == iter->PESEL) {
						i++;
						cout << "Podaj has³o: ";
						cin >> h;
						if (h != iter->haslo) {
							cout << "B³êdne has³o";
						}
						else {
							wyborl2(x, PESEL, h);

						}
					}

				}

				if (i == 0)
					cout << "Nie posiadasz jeszcze konta" << endl;
			}
			}
		}
	
	else
		cout << "B³êdne has³o" << endl;
}




int main() {
	setlocale(LC_ALL, "pl_PL");

	
	baza.open("Baza.txt", ios::in);
	string a, b, c, d, e, f, g, h;
	while (baza.good()) {
		baza >> a;
		if (a == "p") {
			baza >> b >> c >> d >> e >> f >> g;
			Pacjent* p = new Pacjent(b, c, d, e, f, g);
			pacjenci.push_back(*p);
			delete p;
		}
		if (a == "l") {
			baza >> b >> c >> d >> e >> f >> g >> h;
			Lekarz* l = new Lekarz(b, c, d, e, f, g, h);
			lekarze.push_back(*l);
			delete l;
		}
		
	}
	baza.close();
	


	

	cout << "Pacjent(0), lekarz(1) czy pracownik(2)?" << endl;
	int i;
	cin >> i;
	switch (i) {
	case(0): {
		
		wyborp();
		break;
	}
	case(1):
		
		wyborl();
		
		
		break;
	}
		

	
	


	system("PAUSE");
	return 0;
}



