#include "Platnosc.h"
#include "Paragon.h"



void Platnosc::Wniosek(Ubezpieczenie &ub) {
	
}

void Platnosc::Gotowka(float oplata) {
	if (oplata >= kwota) {
		status = true;
	}

}

void Platnosc::Karta() {
	;
}


void Platnosc::paragon(bool stat) {
	if (stat == true) {
		Paragon *p = new Paragon;
		p->Wydrukuj();
		delete p;
	}
}
Platnosc::Platnosc()
{
}


Platnosc::~Platnosc()
{
}
