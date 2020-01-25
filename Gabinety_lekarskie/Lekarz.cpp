#include "Lekarz.h"



Lekarz::Lekarz(){}

Lekarz::Lekarz(string h, string im, string naz, string ad, string nr, string pesel, string spec): Osoba(h, im, naz, ad, nr, pesel), specjalizacja(spec)
{
	string tab[5] = { "poniedzia³ek", "wtorek", "œroda", "czwartek", "pi¹tek" };
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 5; j++) {
			termin[2 * i][j] = Termin(9 + i, 0, tab[j]);
			termin[2 * i + 1][j] = Termin(9 + i, 30, tab[j]);
		}
	}
}


Lekarz::~Lekarz(){}



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
	fstream recepty;
	cout << "Podaj PESEL pacjenta" << endl;
	string p;
	cin >> p;
	cout << "Ile leków chcesz przepisaæ?(max. 10)" << endl;
	int i;
	cin >> i;
	string lek[10];
	int j = 0;
	recepty.open("recepty.txt", ios::app);
	recepty << p << ' ' << i << ' ';
	while (j < i) {
		
		cin >> lek[j];
		recepty << lek[j] << ' ';
		j++;
	}
	recepty << endl;
	recepty.close();
	Recepta r(lek, i, p);
	
}
void Lekarz::Wystaw_zwolnienie() {
	fstream zwolnienia;
	cout << "Podaj PESEL pacjenta" << endl;
	string p;
	cin >> p;
	string odkiedy, dokiedy;
	cout << "Od kiedy ma obowi¹zywaæ zwolnienie?" << endl;
	cin >> odkiedy;
	cout << "Do kiedy ma obowi¹zywaæ zwolnienie?" << endl;
	cin >> dokiedy;
	
	
	
	zwolnienia.open("zwolnienia.txt", ios::app);
	zwolnienia << p << ' ' << odkiedy << ' ' << dokiedy << endl;
	
	zwolnienia.close();
	Zwolnienie z(odkiedy, dokiedy, p);

}

void Lekarz::Wprowadz_specjalizacje() {
	cout << "Specjalizacja: ";
	cin >> specjalizacja;
}

string Lekarz::specjal() {
	return specjalizacja;
}


ostream& operator<<(ostream& os, const Lekarz& oso) {
	os << oso.haslo << ' ' << oso.imie << ' ' << oso.nazwisko << ' ' << oso.adres << ' ' << oso.nrTel << ' ' << oso.PESEL << ' ' << oso.specjalizacja;
	return os;
}