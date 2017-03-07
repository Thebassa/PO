#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class wynik
{
public:
	wynik(int N);
	void show();
	void showAll();
	void inicjalizuj() { this->ilosc_elementow = 0; }
	int dopisz(float liczba);
	int usun();

private:
	float* dane;
	int ilosc_elementow;
	int daneSize;
	int ilosc() { return ilosc_elementow; };
};

wynik::wynik(int N) {
	this->dane = new float[N];
	for (int i = 0; i<N; i++) {
		this->dane[i] = 0;
	}
	this->ilosc_elementow = 0;
	this->daneSize = N;
}

void wynik::show() {
	for (int i = 0; i<(ilosc()); i++) {
		cout << "Element [" << i << "] = " << dane[i] << endl;
	}
	cout << "------------------------" << endl;
}

void wynik::showAll() {
	for (int i = 0; i<(this->daneSize); i++) {
		cout << "Element [" << i << "] = " << dane[i] << endl;
	}
	cout << "------------------------" << endl;
}

int wynik::usun() {
	if (this->ilosc() == 0) {
		return 1;
	}
	else {
		this->dane[this->ilosc() - 1] = 0;
		this->ilosc_elementow--;
		return 0;
	}
}
int wynik::dopisz(float liczba) {
	if (this->ilosc_elementow < this->daneSize) {
		this->dane[this->ilosc_elementow] = liczba;
		this->ilosc_elementow++;
		return 0;
	}
	else {
		return 1;
	}
}

int main()
{
	srand(time(NULL));

	wynik* encja = new wynik(10);
	encja->dopisz(2);
	encja->dopisz(5);
	encja->show();
	encja->showAll();
	while (!encja->dopisz((rand() % 100) + 0)) {};
	encja->show();
	encja->usun();
	encja->usun();
	encja->usun();
	encja->show();
	return 0;
}
