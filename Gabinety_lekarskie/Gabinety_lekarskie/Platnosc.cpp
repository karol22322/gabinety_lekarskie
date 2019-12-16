#include "Platnosc.h"
#include "Paragon.h"




void Platnosc::Wniosek(Ubezpieczenie &ub) {
	
}

void Platnosc::Gotowka(float oplata) {
	if (oplata >= kwota) {
		status = true;
		std::cout << "Reszta: " << oplata - kwota << std::endl;
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

float Platnosc::ile() {
	return this->kwota;
}

Platnosc::Platnosc()
{
	kwota = 0;
	dataPlatnosci = NULL;
}
Platnosc::Platnosc(float kw )
{
	kwota = kw;
	dataPlatnosci = time(NULL);
	std::cout << dataPlatnosci;
}


Platnosc::~Platnosc()
{
}
