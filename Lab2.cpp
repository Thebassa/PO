#include"klasy.h"

int main()
{
	//samochod *cooper = new samochod(CIEZAR, POJEMNOSC);
	//cooper->jedz();
	//cout << "GRATULACJE! Przejechano trase";
	Str a("Marek");
	Str b("Wieckowkski");
	
	Kierowca *rajdowiec = new Kierowca();
	rajdowiec->wpisz(a, b, (long long int)91110122353);
	Kierowca *drugi_rajdowiec = new Kierowca("Robert", "Kubica", (long long int)91110122334);
	samochod *cooper = new samochod(CIEZAR, POJEMNOSC, *rajdowiec);
	samochod *f1 = new samochod(CIEZAR, POJEMNOSC, *drugi_rajdowiec);

	cooper->kierowca.drukuj();
	f1->kierowca.drukuj();

	Kierowca tymczasowa = cooper->kierowca;
	cooper->kierowca = f1->kierowca;
	f1->kierowca = tymczasowa;

	cooper->kierowca.drukuj();
	f1->kierowca.drukuj();
	getchar();
}
