#include "Pacjent.h"
#include <iostream>


Pacjent::Pacjent()
{
}


Pacjent::~Pacjent()
{
}

void Pacjent::Dodaj_pacjenta() {


}
void Pacjent::Zmien_haslo(int pesel) {


}
void Pacjent::Wyswietl_dane() {
	cout << "Dane pacjenta: " << endl << endl;
	cout << "Imie: " << imie << endl;
	cout << "Nazwisko: " << nazwisko << endl;
	cout << "PESEL: " << PESEL << endl;
	cout << "Adres: " << adres << endl;
	cout << "Numer telefonu: " << nrTel << endl << endl;

}
void Pacjent::Rezerwuj_termin() {


}
void Pacjent::Wydrukuj_recepte(Recepta recepta) {
	recepta.Wydrukuj_recepte();

}
void Pacjent::Wydrukuj_zwolnienie(Zwolnienie zwolnienie) {


}
