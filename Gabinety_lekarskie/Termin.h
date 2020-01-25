#pragma once
#include <iostream>
using namespace std;
class Termin
{
public:
	Termin();
	Termin(int h, int min, string d);
	~Termin();
	void Rezerwuj();
	bool Czy_wolny();
	void Pesel(string);
	bool Czy_Pesel(string);
	string Print_Pesel();

	friend ostream & operator<<(ostream &, const Termin &);

	
private:

	string PESEL_pac;
	bool wolny;
	string dzien;
	int h;
	int min;
	
};

