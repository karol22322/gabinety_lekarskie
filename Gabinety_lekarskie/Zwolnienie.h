#pragma once
#include <iostream>


using namespace std;

class Zwolnienie{
public:
	Zwolnienie(string, string, string);
	~Zwolnienie();

	bool Czy_Pesel(string p);
	

private:
	string odkiedy;
	string dokiedy;
	string PESEL;




};

