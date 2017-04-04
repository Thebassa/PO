#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>

using namespace std;

class Rachunek {
	public:
	float srodki;
	float odsetki;
	float oprocentowanie;
	int dzien;
	void dodaj_dni(int dni);
	void wplata(float kwota);
	void kapitalizacja();
	Rachunek(float a = 0, float b = 0, float c = 0) : oprocentowanie(a), srodki(b), odsetki(c) { cout << "Sworzono rachunek "; }
	//Rachunek() { srodki = 0; odsetki = 0; oprocentowanie = 0; cout << "Sworzono rachunek" << endl; }
};

class Lokata_odsetkowa :public Rachunek {
public:
	Lokata_odsetkowa(float aa = 0, float bb = 0, float cc = 0): Rachunek(aa,bb,cc){ cout << "typu lokata odsetkowa" << endl; }
	void wyplata(float kwota);
};

class Ror :public Rachunek {
public:
	Ror(float aa = 0, float bb = 0, float cc = 0) : Rachunek(aa, bb, cc) { cout << "typu Ror" << endl; }
	void wyplata(float kwota);
};

class Lokata :public Rachunek {
public:
	int termin;
	bool miesieczna; //true dla miesiecznej, false dla kwartalnej
	Lokata(bool m = true, float aa = 0, float bb = 0, float cc = 0) : miesieczna(m), Rachunek(aa, bb, cc) { 
		if (miesieczna)
			termin = 30;
		else 
			termin = 90;
	cout << "typu lokata" << endl; }
	void wyplata(float kwota);
};