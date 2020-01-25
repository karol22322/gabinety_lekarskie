#pragma once
#include <iostream>
using namespace std;

using namespace std;
class Recepta
{
public:
	Recepta(string* l, int ile, string PESEL);
	~Recepta();

	bool Czy_Pesel(string);
	
private:
	
	string PESEL;
	string lekarstwo[10];
};

