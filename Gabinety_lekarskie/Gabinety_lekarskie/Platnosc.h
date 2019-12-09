#pragma once
#include <ctime>
#include "Ubezpieczenie.cpp"
class Platnosc
{
protected:
	float kwota;
	time_t dataPlatnosci;
	bool status;

public:
	void Wniosek(Ubezpieczenie &ub);
	void Gotowka(float oplata);
	void Karta();
	void paragon(bool stat);
	
	

public:
	Platnosc();
	~Platnosc();
};

