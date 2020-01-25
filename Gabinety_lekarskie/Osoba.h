#pragma once
#include <iostream>
using namespace std;



class Osoba
{
public:
	Osoba();
	Osoba(string h, string im, string naz, string ad, string nr, string pesel);
	~Osoba();
	void Dodaj_osobe();
	void Tworz_konto();
	bool Tworz_haslo();
	void Zmien_haslo();
	void Wyswietl_dane();
	void Edytuj_dane();
	bool Czy_Pesel(string p);
	

	
	static bool admin(string pass);

	friend void wyborp();
	friend void wyborp2(char x, string p, string h, bool s);
	friend void wyborl();
	friend void wyborl2(char x, string p, string h);
	friend ostream& operator<<(ostream& os, const Osoba& oso);

	

	
protected:
	string imie;
	string nazwisko;
	string adres;
	string nrTel;
	string PESEL;
	string haslo;

private:
	const static string haslo_admin;
	
};

