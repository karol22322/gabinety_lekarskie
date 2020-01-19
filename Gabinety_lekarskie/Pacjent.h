#pragma once
#include "Osoba.h"
#include "Recepta.h"
class Pacjent :
	public Osoba
{
public:
	Pacjent();
	Pacjent(string h, string im, string naz, string ad, string nr, string pesel);
	~Pacjent();


	void Rezerwuj_termin();
	//void Wydrukuj_recepte(Recepta r);
	void Wydrukuj_zwolnienie();
	int Print_id();
	float Wyswietl_saldo();




private:
	int id;
	float saldo;

};

