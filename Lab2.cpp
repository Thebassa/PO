#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>

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

using namespace std;

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

 samochod::samochod(float ciezar, int pojemnosc) {
	this->ciezar = ciezar;
	this->moc = (pojemnosc * WSPOLCZYNNIK_MOCY);
	this->kmnakg = this->moc / this->ciezar;
	this->predkosc_maksymalna = this->kmnakg * WSPOLCZYNNK_PREDKOSCI;
	cout << "Moc = " << this->moc << "\n";
	cout << "Hp per kg = " << this->kmnakg << "\n";
	cout << "Predkosc maksymalna = " << this->predkosc_maksymalna << "\n";
	cout << "Sterowanie:\n";
	cout << "Strzalka do gory: gaz, strzalka w dol: spowolnienie, spacja: pokaz status\n"; //zamiast komend wybrano sterowanie klawiatura
	this->predkosc_aktualna = 0;
	this->otwarcie_zaworu = 0;
	this->pokonna_odleglosc = 0;
};

void samochod::dodaj_gazu() {
	cout << "dodano gazu\n";
	if (this->otwarcie_zaworu < 100)
		this->otwarcie_zaworu = this->otwarcie_zaworu + 10;
	else
		cout << "juz osiagnieto predkosc maksymalna\n";
}

void samochod::przyhamuj() {
	cout << "zachamowano" << "\n";
	if (this->otwarcie_zaworu > 0)
		this->otwarcie_zaworu = this->otwarcie_zaworu - 10;
	else
		cout << "juz osiagnieto predkosc minimalna\n";
}

void samochod::pokaz_status()
{
	cout << "Otwarcie zaworu to  " << this->otwarcie_zaworu << "\npredkosc to " << this->predkosc_aktualna << "\n";
	cout << "Pokonano " << this->pokonna_odleglosc/1000 <<" km\n\n";
}
void samochod::jedz()
{
	while(this->pokonna_odleglosc/1000 < ODLEGLOSC_DO_POKONANIA)
	{ 
		char znak = getch(); //note: z niewiadomego powodu za kazdym razem getch pobiera dwa znaki, wlasciwy i 32
			if (znak == STRZALKA_UP || znak == STRZALKA_DOWN || znak == SPACJA){
				if (znak == STRZALKA_UP)
					this->dodaj_gazu();
				if (znak == STRZALKA_DOWN)
					this->przyhamuj();
				this->predkosc_aktualna = this->predkosc_maksymalna * (this->otwarcie_zaworu / 100);
				this->pokonna_odleglosc = this->pokonna_odleglosc + ((this->predkosc_aktualna * PRZELICZNIK_PREDKOSCI) * CZAS_SKOKU);
				//this->pokaz_status(); //debug
				if (znak == SPACJA)
					this->pokaz_status();
			}
	}

}

int main()
{
	samochod *cooper = new samochod(CIEZAR, POJEMNOSC);
	cooper->jedz();
	cout << "GRATULACJE! Przejechano trase";
	getchar();
}
