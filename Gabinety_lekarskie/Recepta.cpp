#include "Recepta.h"




Recepta::Recepta(string* l, int ile, string PESEL): PESEL(PESEL){
	for (int i = 0; i < ile; i++) {
		lekarstwo[i] = l[i];
	}
}


Recepta::~Recepta()
{
}

bool Recepta::Czy_Pesel(string p) {
	if (p == PESEL) {
		return true;
	}
	else {
		return false;
	}
}


