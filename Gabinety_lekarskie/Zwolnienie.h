#pragma once
#include "Pacjent.h"
#include <string>
using namespace std;

class Zwolnienie: public Pacjent
{
public:
	Zwolnienie();
	~Zwolnienie();
	void Wydrukuj_zwolnienie();
	void Zwolnienie::Stworz_zwolnienie(string imie, string nazw, int pesel, Lekarz lekarz, string opis);

private:
	string imie;
	string nazwisko;
	unsigned int PESEL;
	string lekarz;
	int data_wystawienia;
	int termin_zwolnienia; 
	string tresc;




};

