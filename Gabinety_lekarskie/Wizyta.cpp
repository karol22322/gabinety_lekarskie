#include "Wizyta.h"
#include "Zwolnienie.h"
#include "Recepta.h"
#include <list>


using namespace std;

list<Zwolnienie> zwolnienia;
list<Recepta> recepty;
Wizyta::Wizyta()
{
}

Wizyta::~Wizyta()
{
}


void wyswietl_recepty() {
	for (list<Recepta>::iterator iter = recepty.begin(); iter != recepty.end(); ) {
		iter->Recepta::Wydrukuj_recepte();
		iter++;
	}
	
}
void wyswietl_zwolnienia() {
	for (list<Zwolnienie>::iterator iter = zwolnienia.begin(); iter != zwolnienia.end(); ) {
		iter->Zwolnienie::Wydrukuj_zwolnienie();
		iter++;
	}
}

void dodaj_zwolnienie(Zwolnienie zw) {
	zwolnienia.push_back(zw);
}

void dodaj_recepte(Recepta re) {
	recepty.push_back(re);
}