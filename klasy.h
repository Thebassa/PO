#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>

using namespace std;

#define CIEZAR 1040 //kg
#define POJEMNOSC 1600 //cm3
#define WSPOLCZYNNIK_MOCY 0.07 //aproksymowany
#define WSPOLCZYNNK_PREDKOSCI 1900 //aproksymowany
#define PRZELICZNIK_PREDKOSCI 0.277777778 //do zamiany z kmph na mps
#define ODLEGLOSC_DO_POKONANIA 5 //km
#define CZAS_SKOKU 5//sec
#define STRZALKA_UP 72
#define STRZALKA_DOWN 80
#define SPACJA 32

class samochod {
public:
	samochod(float ciezar, int pojemnosc);
	void jedz();

private:
	//
	// stale samochodu
	//
	//ciezar samochodu w kilogramach
	float ciezar;
	//pojemnosc silnika w centymetrach szesciennych
	int pojemnosc;
	//moc samochodu w koniach mechanicznych
	float moc;
	//stosunek mocy do ciezaru w konach mechanicznych na kilogram
	float kmnakg;
	//predkosc maksymalna w kmph
	float predkosc_maksymalna;
	//
	// zmienne
	//
	float predkosc_aktualna; //kmph
	float otwarcie_zaworu; //procenty
	float pokonna_odleglosc; //metry
							 //
							 // metody
							 //
	void dodaj_gazu();
	void przyhamuj();
	void pokaz_status();
};