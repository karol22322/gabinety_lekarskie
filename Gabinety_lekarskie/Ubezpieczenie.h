#pragma once
#include <string>
class Ubezpieczenie
{
	int nrUb;
	std::string imie;
	std::string nazwisko;
	unsigned int PESEL;

public:
	Ubezpieczenie();
	~Ubezpieczenie();
};

