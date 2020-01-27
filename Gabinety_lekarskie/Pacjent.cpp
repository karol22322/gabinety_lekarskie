#include "Pacjent.h"



Pacjent::Pacjent(): saldo(0.0), ubezp(true) {}

Pacjent::Pacjent(string h, string im, string naz, string ad, string nr, string pesel, float saldo): Osoba(h, im, naz, ad, nr, pesel), saldo(saldo) {
}

Pacjent::~Pacjent()
{

}


bool Pacjent::Czy_Pesel(string p) {
	if (p == PESEL)
		return true;
	else
		return false;
}

float Pacjent::Wyswietl_saldo() {
	return saldo;
}


bool Pacjent::Rezerwuj_termin(Lekarz &l, int nr) {
	int i = (nr - 1) % 12;
	int j = (nr - 1) / 12;
	
	if (l.termin[i][j].Czy_wolny() == true) {
		l.termin[i][j].Rezerwuj();
		l.termin[i][j].Pesel(this->PESEL);
		//cout << l.termin[i][j] << endl;
		

		return 1;
	}
	else
		cout << "Ten termin jest ju¿ przez kogoœ zajêty" << endl;
	return 0;


}

void Pacjent::Zwieksz_saldo(float k) {
	saldo += k;
}


