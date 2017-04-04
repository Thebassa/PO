#include"klasy.h"

int main()
{
	//oprocentowanie, srodki, odsetki
	Lokata_odsetkowa *odsetkowa = new Lokata_odsetkowa(5,1000);
	Ror *ror = new Ror(5, 1000);
	//miesieczna(true/false), oprocentowanie, srodki, odsetki
	Lokata *lokata = new Lokata(true, 5,1000);
	//Rachunek *rachunek = new Rachunek(1.5);
	lokata->wplata(1000);
	cout << lokata->odsetki;
	getchar();
}
