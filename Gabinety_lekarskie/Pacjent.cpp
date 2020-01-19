#include "Pacjent.h"


Pacjent::Pacjent():saldo(0.0)
{
	id = licznik;
	//Osoba();

}
Pacjent::Pacjent(string h, string im, string naz, string ad, string nr, string pesel): Osoba(h, im, naz, ad, nr, pesel), saldo(0.0), id(licznik) {
}

Pacjent::~Pacjent()
{

}




float Pacjent::Wyswietl_saldo() {
	return saldo;
}


void Pacjent::Rezerwuj_termin() {


}
//void Pacjent::Wydrukuj_recepte(Recepta recepta) {


//}
void Pacjent::Wydrukuj_zwolnienie() {


}

int Pacjent::Print_id() {
	return id;
}