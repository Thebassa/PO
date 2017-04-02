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

class Str {
public:
	int dlugosc(char *wyraz);
	char *adres;
	int zapisanego_dlugosc();
	Str();
	void wpisz(char *wyraz);
	void drukuj();
	Str(char *napis);
	char *sklejanie(char *napis1, char *napis2);
	void doklej(char *napis);
};

class Kierowca {
private:
	Str imie;
	Str nazwisko;
	long long int pesel;
public:
	void drukuj();
	void wpisz(Str a, Str b, long long int c) {
		imie = a;
		nazwisko = b;
		pesel = c;
	}
	Kierowca() { cout << "Utworzono pustego kierowce dodaj jego imie i nazwisko metoda wpisz" << endl; }
	Kierowca(Str a, Str b, long long int c) : imie(a), nazwisko(b), pesel(c) {}
};

class samochod {
public:
	samochod(float ciezar, int pojemnosc, Kierowca kierowca);
	void jedz();
	Kierowca kierowca;

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
	void drukuj(char *strin, int masa);
	void drukuj(char *strin, float pojemnosc);
};
