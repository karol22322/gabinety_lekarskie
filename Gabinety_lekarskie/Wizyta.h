#pragma once
#include <time.h>
#include "Pacjent.h"
class Wizyta
{
public:
	Wizyta();
	~Wizyta();

	void Dodaj_wizyte();
	void Wczytaj_recepte();
	void Wczytaj_zwolnienie();
	void Oblicz_koszt(Pacjent);
private:
	int czas_rozp; // Do poprawy
	Pacjent pacjent;

};

