#include "Termin.h"


using namespace std;




Termin::Termin()
{
	h = 0;
	min = 0;
	wolny = true;
}

Termin::Termin(int H, int MIN, string D): h(H), min(MIN), dzien(D) {
	wolny = true;
}

Termin::~Termin()
{
}

void Termin::Rezerwuj() {
	wolny = false;
}

bool Termin::Czy_wolny() {
	if (wolny == true)
		return true;
	else
		return false;
}

string Termin::Print_Pesel() {
	return PESEL_pac;
}

void Termin::Pesel(string P) {
	PESEL_pac = P;
}

bool Termin::Czy_Pesel(string P) {
	if (PESEL_pac == P)
		return true;
	else
		return false;
}


ostream & operator<<(ostream &os, const Termin &ter) {
	if (ter.wolny == true) {
		if (ter.min == 0) {
			os << ter.h << ':' << ter.min << "0 " << ter.dzien << " wolny";
		}
		else
			os << ter.h << ':' << ter.min << ' ' << ter.dzien << " wolny";
	}
	else {
		if (ter.min == 0) {
			os << ter.h << ':' << ter.min << "0 " << ter.dzien << " zajêty";
		}
		else
			os << ter.h << ':' << ter.min << ' ' << ter.dzien << " zajêty";
	}
	return os;
	
}