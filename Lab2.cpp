#include"klasy.h"

int main()
{
	samochod *cooper = new samochod(CIEZAR, POJEMNOSC);
	cooper->jedz();
	cout << "GRATULACJE! Przejechano trase";
	getchar();
}
