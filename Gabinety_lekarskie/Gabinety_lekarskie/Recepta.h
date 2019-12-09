#pragma once
#include <string>
using namespace std;
class Recepta
{
public:
	Recepta();
	~Recepta();
	void Wydrukuj_recepte();
private:
	string imie;
	string nazwisko;
	unsigned int PESEL;
	string lekarz;
	string nazwa_leku;
	int data_wydania; // do poprawy
};

