#pragma once
#include <ctime>
#include <iostream>
#include "Ubezpieczenie.h"

class Platnosc
{
protected:
	float kwota;
	time_t dataPlatnosci;
	bool status;

public:
	float ile();
	void Wniosek(Ubezpieczenie &ub);
	void Gotowka(float oplata);
	void Karta();
	void paragon(bool stat);
	
	

public:
	Platnosc();
	Platnosc(float kw);
	~Platnosc();
};

