#pragma once
#include <string>
using namespace std;



class Osoba
{
public:
	Osoba();
	~Osoba();
protected:
	string imie;
	string nazwisko;
	string adres;
	unsigned int nrTel;
};

