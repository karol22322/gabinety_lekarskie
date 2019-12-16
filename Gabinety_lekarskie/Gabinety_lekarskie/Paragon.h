#pragma once
#include "Platnosc.h"
class Paragon: public Platnosc
{
	void Wydrukuj();
	friend void Platnosc::paragon(bool stat);
public:
	Paragon();
	~Paragon();
};

