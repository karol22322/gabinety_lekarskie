#include "Pacjent.h"
#include "Lekarz.h"
#include <string>
#include <list>
#include <vector>
#include <fstream>
#include <ctime>

using namespace std;


list<Pacjent> pacjenci;
list<Lekarz> lekarze;

fstream baza;
fstream wizyty;



void wyborp2(char x, string PESEL, string h, bool s = true) {
	if (s == false)
		x = '1';
	else {
		cout << "\nSaldo(1)\nZmiana has³a(2)\nMoje dane(3)\nEdycja danych(4)\nNowa wizyta(5)\nMoje wizyty(6)\nLekarze(7)\nMoje recepty(8)\nZwolnienia(9)\nWyjœcie(x)\n";
		cin >> x;
	}
	
	switch (x) {
	case('1'): {
		for (list<Pacjent>::iterator iter = pacjenci.begin(); iter != pacjenci.end(); iter++) {

			if (PESEL == iter->PESEL) {
				cout << "Twoje saldo: " << iter->Wyswietl_saldo() << endl;

				cout << "Czy chcesz do³adowaæ swoje konto z po³¹czonej do konta karty?(t/n) Ostro¿nie, wp³aconych œrodków nie mo¿na wyp³aciæ" << endl;
				char n;
				cin >> n;
				switch (n) {
				case('t'):
					cout << "Na jak¹ kwotê? ";
					float kwota;
					cin >> kwota;
					if (kwota > 0)
						iter->Zwieksz_saldo(kwota);
					else
						cout << "Nieprawid³owa kwota" << endl;
					break;
				case('n'):
					break;

				}


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
							baza << "p " << *iter << ' ' << iter->Wyswietl_saldo();
						}
						else {
							baza << linijki[i];
						}
					}
					else {
						if (i == j) {
							baza << "p " << *iter << ' ' << iter->Wyswietl_saldo() << endl;
						}
						else {
							baza << linijki[i] << endl;
						}
					}

				}
				cout << endl;


				if (iter->Wyswietl_saldo() < 100) {
					x = 'x';

				}

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
	case('5'): {
		string specjal;
		cout << "Podaj specjalizacjê lekarza: ";
		cin >> specjal;
		for (list<Lekarz>::iterator iter = lekarze.begin(); iter != lekarze.end(); iter++) {
			if (specjal == iter->specjal()) {
				cout << iter->imie << ' ' << iter->nazwisko << ' ' << iter->specjal() << endl;
				int i = 0;
				int j = 0;
				while (j < 5) {
					while (i < 12) {
						cout << i + 1 + j * 12 << ") " << iter->termin[i][j] << endl;
						i++;
					}
					i = 0;
					j++;
				}
				for (list<Pacjent>::iterator pac = pacjenci.begin(); pac != pacjenci.end(); pac++) {

					if (PESEL == pac->PESEL) {
						cout << "Podaj numer wolnego terminu: (koszt wizyty 50 z³otych, kwota zostanie pobrana automatycznie z konta po rejestracji)";
						int nr;
						cin >> nr;
						if (pac->Rezerwuj_termin(*iter, nr)) {
							pac->Zwieksz_saldo(-50);
							wizyty.open("wizyty.txt", ios::out | ios::app);
							wizyty << endl << PESEL << ' ' << nr << ' ' << iter->specjal();
							wizyty.close();
						}
					}
				}

			}

		}


		break;
	}
	case('6'): {
		
		for (list<Lekarz>::iterator iter = lekarze.begin(); iter != lekarze.end(); iter++) {
			int i = 0;
			int j = 0;


			while (j < 5) {
				while (i < 12) {
					if (iter->termin[i][j].Czy_Pesel(PESEL)) {
						cout << iter->imie << ' ' << iter->nazwisko << ' ' << iter->specjal() << endl;
						cout << i + 1 + j * 12 << ") " << iter->termin[i][j] << endl << endl;

					}
					i++;
					
				}
				i = 0;
				j++;
			}

		}
		break;
	}
	case('7'): {
		for (list<Lekarz>::iterator iter = lekarze.begin(); iter != lekarze.end(); iter++) {
			cout << iter->imie << ' ' << iter->nazwisko << ' ' << iter->specjal() << endl;
		}
		break;
	}
	case('8'): {
		cout << "Recepty: " << endl;
		fstream recepty;
		recepty.open("recepty.txt", ios::in);
		string temp;
		while (recepty.good()) {
			recepty >> temp;
			if (temp == PESEL) {
				int i;
				recepty >> i;
				while (i != 0) {
					recepty >> temp;
					cout << temp << ' ';
					i--;
				}
				cout << endl;
			}
		}
		recepty.close();
		break;
	}
	case('9'): {
		cout << "Zwolnienia: " << endl;
		fstream zwolnienia;
		zwolnienia.open("zwolnienia.txt", ios::in);
		string temp;
		while (zwolnienia.good()) {
			zwolnienia >> temp;
			if (temp == PESEL) {
				string i, j;
				zwolnienia >> i >> j;
				cout << i << '-' << j << endl;
			
			}
		}
		zwolnienia.close();
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
					system("CLS");
					if (iter->Wyswietl_saldo() < -100) {
						bool s = false;
						cout << "Masz ponad 100 z³otych zad³u¿enia, by korzystaæ z systemu, sp³aæ najpierw d³ug." << endl << endl;
						wyborp2(x, PESEL, h, s);
					}
					else	
						wyborp2(x, PESEL, h);
					
				}
			}

		}

		if (i == 0)
			cout << "Nie posiadasz jeszcze konta" << endl;
	}
	}
}

void wyborl2(char x, string PESEL, string h) {
	cout << "Zmiana has³a(1)\nMoje dane(2)\nEdycja danych(3)\nWizyty(4)\nRecepty(5)\nZwolnienia(6)\nP³atnoœci(7)\nWyjœcie(x)\n";
	cin >> x;
	switch (x) {
	case('1'): {
		for (list<Lekarz>::iterator iter = lekarze.begin(); iter != lekarze.end(); ++iter) {

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
	case('4'): {
		for (list<Lekarz>::iterator iter = lekarze.begin(); iter != lekarze.end(); iter++) {
			if (iter->Czy_Pesel(PESEL)) {


				int i = 0;
				int j = 0;


				while (j < 5) {
					while (i < 12) {
						if (!iter->termin[i][j].Czy_wolny()) {
							cout << iter->termin[i][j] << endl;
							for (list<Pacjent>::iterator pac = pacjenci.begin(); pac != pacjenci.end(); ++pac) {
								if (pac->Czy_Pesel(iter->termin[i][j].Print_Pesel())) {
									pac->Wyswietl_dane();
								} 

							}
							

						}
						i++;

					}
					i = 0;
					j++;
				}



			}
		}
	}
	case('5'): {
		for (list<Lekarz>::iterator iter = lekarze.begin(); iter != lekarze.end(); iter++) {
			if (iter->Czy_Pesel(PESEL)) {
				iter->Wystaw_recepte();
			}
		}
		break;
	}
	case ('6'): {
		for (list<Lekarz>::iterator iter = lekarze.begin(); iter != lekarze.end(); iter++) {
			if (iter->Czy_Pesel(PESEL)) {
				iter->Wystaw_zwolnienie();
			}
		}
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
	float saldo;
	while (baza.good()) {
		baza >> a;
		if (a == "p") {
			baza >> b >> c >> d >> e >> f >> g >> saldo;
			Pacjent* p = new Pacjent(b, c, d, e, f, g, saldo);
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
	
	wizyty.open("wizyty.txt", ios::in);
	int B;
	while (wizyty.good()) {
		wizyty >> a >> B >> c;
		for (list<Lekarz>::iterator iter = lekarze.begin(); iter != lekarze.end(); iter++) {
			if (iter->specjal() == c) {
				for (list<Pacjent>::iterator pac = pacjenci.begin(); pac != pacjenci.end(); pac++) {

					if (pac->Czy_Pesel(a)) {
						pac->Rezerwuj_termin(*iter, B);
					}
				}
			}
		}
	}
	wizyty.close();

	

	

	cout << "Pacjent(1) czy lekarz(2)?" << endl;
	int i;
	cin >> i;
	switch (i) {
	case(1): {
		
		wyborp();
		break;
	}
	case(2):
		
		wyborl();
		break;
	}
		

	
	

	
	return 0;
}



