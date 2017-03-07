#include <iostream>
#include <cstdlib>
#include <ctime>

#define N 10
using namespace std;

class wynik {
public:
	void wydrukuj();
	void inicjalizacja();
	bool dopisz(float liczba);
	bool usun();

private:
	float dane[N];
	int ilosc_elementow;
	int ilosc() {
		return this->ilosc_elementow;
	};

};

void wynik::wydrukuj() {
	cout << "ilosc = " << this->ilosc() << '\n';
	for (int i = 0; i < this->ilosc(); i++)
	{
		cout << dane[i] << '\n';
	}
};

void wynik::inicjalizacja() {
	this->ilosc_elementow = 0;
};

bool wynik::dopisz(float liczba) {
	if (this->ilosc_elementow < N)
	{
		this->dane[this->ilosc_elementow] = liczba;
		this->ilosc_elementow++;
		return false;
	}
	else
	{
		return true;
	}
};

bool wynik::usun()
{
	if (this->ilosc_elementow == 0)
	{
		return true;
	}
	else
	{
		this->ilosc_elementow--;
		return false;
	}

}

int main()
{
	int i = 0;
	bool flaga=false;
	wynik *wyniki = new wynik;
	wyniki->inicjalizacja();
	while (!flaga)
	{
		i++;
		flaga = wyniki->dopisz(i);
	}
	wyniki->wydrukuj();
	wyniki->usun();
	wyniki->wydrukuj();

	getchar();
}
