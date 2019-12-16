#pragma once
#include "Osoba.h"
#include "Recepta.h"
#include "Zwolnienie.h"
class Pacjent :
	public Osoba
{
public:
	Pacjent();
	~Pacjent();
	void Dodaj_pacjenta();
	void Zmien_haslo(int);
	void Wyswietl_dane();
	void Rezerwuj_termin();
	void Wydrukuj_recepte(Recepta);
	void Wydrukuj_zwolnienie(Zwolnienie);

private:
	unsigned int PESEL;
};

