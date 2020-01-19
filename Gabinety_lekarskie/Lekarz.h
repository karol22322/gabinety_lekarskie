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
	string specjalizacja;
	Lekarz();
	Lekarz(string h, string im, string naz, string ad, string nr, string pesel, string spec);
	~Lekarz();
	void Wyswietl_dane();
	void Wystaw_recepte();
	void Wystaw_zwolnienie(Zwolnienie);
	Pacjent Pobierz_dane_pacjenta(int);
	friend void wyborp();

private:
	int id;
};

