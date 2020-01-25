#include "Zwolnienie.h"




Zwolnienie::Zwolnienie(string o, string d, string p): odkiedy(o), dokiedy(d), PESEL(p){
}


Zwolnienie::~Zwolnienie(){
}

bool Zwolnienie::Czy_Pesel(string p) {
	if (p == PESEL) {
		return true;
	}
	else {
		return false;
	}
}