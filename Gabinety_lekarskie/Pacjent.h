#pragma once
#include "Osoba.h"
#include "Recepta.h"
#include "Lekarz.h"
#include "Zwolnienie.h"

class Pacjent :
	public Osoba
{
public:
	Pacjent();
	Pacjent(string h, string im, string naz, string ad, string nr, string pesel, float saldo);
	~Pacjent();


	bool Rezerwuj_termin(Lekarz&, int nr);
	float Wyswietl_saldo();
	void Zwieksz_saldo(float);
	bool Czy_Pesel(string p);

private:
	float saldo;
	bool ubezp = false;

};

