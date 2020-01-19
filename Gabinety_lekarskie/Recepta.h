#pragma once
#include <string>
#include "Lekarz.h"
#include "Pacjent.h"
using namespace std;
class Recepta
{
public:
	Recepta();
	~Recepta();
	
private:
	
	string nazwa_leku;
	int data_wydania = 0; // do poprawy
};

