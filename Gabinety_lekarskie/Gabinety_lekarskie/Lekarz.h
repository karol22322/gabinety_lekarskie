#pragma once
#include "Pracownik.h"
#include "Recepta.h"
#include "Zwolnienie.h"
#include "Pacjent.h"
#include <string>

using namespace std;
class Lekarz :
	public Pracownik
{
public:
	string specjalizacja;
	Lekarz();
	~Lekarz();
	void Wystaw_rezepte(Recepta);
	void Wystaw_zwolnienie(Zwolnienie);
	Pacjent Pobierz_dane_pacjenta(int);

private:
	unsigned int PESEL;
};

