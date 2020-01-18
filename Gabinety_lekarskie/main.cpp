#include "Pacjent.h"
#include "Paragon.h"
#include "Ubezpieczenie.h"
#include "Platnosc.h"
#include "Lekarz.h"
#include <list>
#include <fstream>

using namespace std;


list<Pacjent> pacjenci;
list<Lekarz> lekarze;

fstream baza;

void wyswietl_lekarzy() {
	for (list<Lekarz>::iterator iter = lekarze.begin(); iter != lekarze.end(); ) {
		iter->Lekarz::Wyswietl_dane();
		iter++;
	}
}

void wyswietl_pacjentow() {
	for (list<Pacjent>::iterator iter = pacjenci.begin(); iter != pacjenci.end(); ) {
		iter->Wyswietl_dane();
		iter++;
	}
}


void wybor() {
	int x;
	cout << "\nCo chcesz zrobiæ?" << endl;
	cout << "Za³o¿yæ konto (1)\n Zmieniæ has³o(2)\nWyœwietliæ swoje dane(3)\n";
	cin >> x;
	switch (x) {
	case(1): {
		
		Pacjent p;
		p.Tworz_konto();
		pacjenci.push_back(p);
		baza.open("Baza.txt", ios::out | ios::app);
		baza <<"\np " << p;


		break;
	}
	case(3): {
		cout << "Podaj PESEL: ";
		string x;
		
		for (list<Pacjent>::iterator iter = pacjenci.begin(); iter != pacjenci.end(); ) {
			cin >> x;
			if (x == iter->PESEL) {
				cout << "Podaj has³o: ";
				cin >> x;
				if (x == iter->haslo) {
					iter->Wyswietl_dane();
					break;
				}
				else {
					cout << "B³êdne has³o" << endl;
					break;
				}
			}
			else {
				cout << "Nie ma konta o danym numerze PESEL" << endl;
				break;
			}

			}
			
		}
	}
	return;
	wybor();

}


int main() {
	setlocale(LC_ALL, "pl_PL");

	
	baza.open("Baza.txt", ios::in);
	string a, b, c, d, e, f, g, h;
	while (baza) {
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
		
		wybor();
		break;
	}
	case(1):

		
		cout << "Podaj has³o admina: ";
		string haslo;
		cin >> haslo;
		if (Osoba::admin(haslo) == true) {
			Lekarz* l = new Lekarz;
		}
		else
			cout << "B³êdne has³o" << endl;
		break;
	}
		

	
	wyswietl_pacjentow();


	system("PAUSE");
	return 0;
}