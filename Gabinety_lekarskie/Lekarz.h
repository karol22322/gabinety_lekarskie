#pragma once
#include "Pracownik.h"
#include "Recepta.h"
#include "Zwolnienie.h"
#include "Pacjent.h"
#include <string>

using namespace std;
class Lekarz :
	public Osoba
{
public:
	
	Lekarz();
	Lekarz(string h, string im, string naz, string ad, string nr, string pesel, string spec);
	~Lekarz();
	void Wyswietl_dane();
	void Wystaw_recepte();
	void Wystaw_zwolnienie();
	void Wprowadz_specjalizacje();
	string specjal();
	
	friend void wyborp();
	friend ostream& operator<<(ostream& os, const Lekarz& oso);

private:
	int id;
	string specjalizacja;
};

