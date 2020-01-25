#pragma once

#include "Recepta.h"
#include "Zwolnienie.h"
#include "Termin.h"
#include "Osoba.h"
#include <fstream>
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


	Termin termin[12][5];
	
	friend void wyborp();
	friend ostream& operator<<(ostream& os, const Lekarz& oso);

private:
	string specjalizacja;
};

