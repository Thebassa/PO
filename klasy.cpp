#include"klasy.h"

void Rachunek::wplata(float kwota){
	srodki += kwota;
}

void Rachunek::kapitalizacja() {
	odsetki = srodki * (oprocentowanie / 100) * (dzien / 365);
}
void Rachunek::dodaj_dni(int dni) {
	dzien += dni;
}

void Lokata_odsetkowa::wyplata(float kwota) {
	kapitalizacja();
	if(kwota <= odsetki) {
		cout << "Wyplacono " << kwota << endl;
		odsetki -= kwota;
	}
	else {
		cout << "Nie mozna wyplacic, kwota nie miesci sie w odsetkach" << endl;
	}
}

void Ror::wyplata(float kwota) {
	kapitalizacja();
	if (kwota <= odsetki + srodki) {
		cout << "Wyplacono " << kwota << endl;
		odsetki -= kwota;
		srodki -= ((-1)*odsetki);
		if (odsetki < 0)
			odsetki = 0;
	}
	else {
		cout << "Nie mozna wyplacic, kwota nie miesci sie w posiadanej kwocie" << endl;
	}
}

void Lokata::wyplata(float kwota) {
	kapitalizacja();
	if (dzien%termin != 0) {
		cout << "nie mozna wyplacic w tym terminie" << endl;
		return;
	}

	if (kwota <= odsetki + srodki) {
		cout << "Wyplacono " << kwota << endl;
		odsetki -= kwota;
		srodki -= ((-1)*odsetki);
		if (odsetki < 0)
			odsetki = 0;
	}
	else {
		cout << "Nie mozna wyplacic, kwota nie miesci sie w posiadanej kwocie" << endl;
	}
}