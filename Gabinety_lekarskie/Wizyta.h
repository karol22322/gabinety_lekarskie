#pragma once
#include "Pacjent.h"
#include <list>
class Wizyta
{
public:
	Wizyta();
	~Wizyta();

	void wyswietl_recepty();
	void wyswietl_zwolnienia();
	void dodaj_zwolnienie(Zwolnienie zw);
	void dodaj_recepte(Recepta re);
private:
	list<Zwolnienie> zwolnienia;
	list<Recepta> recepty;

};

