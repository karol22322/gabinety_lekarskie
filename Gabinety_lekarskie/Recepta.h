#pragma once
#include <string>
#include "Lekarz.h"
using namespace std;
class Recepta
{
public:
	Recepta();
	~Recepta();
	void Wydrukuj_recepte();
	void Stworz_recepte(string imie, string nazw, int pesel, Lekarz lekarz,string nazwa);
private:
	string imie;
	string nazwisko;
	unsigned int PESEL;
	string lekarz;
	string nazwa_leku;
	int data_wydania; 
};

