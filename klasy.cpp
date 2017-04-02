#include"klasy.h"

//
//
// Klasa stringa
//
//

int Str::dlugosc(char *wyraz)
{
	int i = 0;
	//debug if (this->adres) {
	if (!wyraz) {
		return 0;
	}
	while (wyraz[i] != '\0')
	{
		i++;
	}
	return i;
}
int Str::zapisanego_dlugosc()
{
	return this->dlugosc(this->adres);
}
Str::Str()
{
	this->adres = NULL;
}

void Str::wpisz(char *wyraz)
{
	if (this->adres == NULL) {
		this->adres = new char(dlugosc(wyraz) + 1);
	}
	else if (this->dlugosc(this->adres)>this->dlugosc(wyraz))
	{
		delete[] this->adres;
		this->adres = new char[dlugosc(wyraz) + 1];
	}
	strcpy(this->adres, wyraz);
}

void Str::drukuj()
{
	cout << this->adres;
}

Str::Str(char *napis)
{
	this->adres = NULL;
	this->wpisz(napis);
};

char *Str::sklejanie(char *napis1, char *napis2) {
	//cout << "Debug A" << endl;
	int do_zarezerwowania = this->dlugosc(napis1) + this->dlugosc(napis2) + 1;
	//cout << "Debug dlugosci " << do_zarezerwowania << endl;
	char *do_zwrocenia = new char[do_zarezerwowania];
	int pozycja_stringa_docelowego = 0;
	int pozycja_stringa_zrodlowego = 0;
	while (pozycja_stringa_zrodlowego < this->dlugosc(napis1)) {
		do_zwrocenia[pozycja_stringa_docelowego] = napis1[pozycja_stringa_zrodlowego];
		pozycja_stringa_docelowego++;
		pozycja_stringa_zrodlowego++;
	}
	pozycja_stringa_zrodlowego = 0;
	while (pozycja_stringa_zrodlowego < this->dlugosc(napis2)) {
		do_zwrocenia[pozycja_stringa_docelowego] = napis2[pozycja_stringa_zrodlowego];
		pozycja_stringa_docelowego++;
		pozycja_stringa_zrodlowego++;
	}
	do_zwrocenia[pozycja_stringa_docelowego] = '\0';
	//cout << "Debug zawartosci " << do_zwrocenia << endl;

	return do_zwrocenia;
}
void Str::doklej(char *napis) {
	if (napis == NULL)
		return;
	if (this->adres == NULL)
		this->wpisz(napis);
	int do_zarezerwowania = this->dlugosc(napis) + this->dlugosc(this->adres) + 1;
	//cout << do_zarezerwowania << endl;

	char *temporarna = new char[do_zarezerwowania];
	char *temporarna2;
	temporarna2 = this->sklejanie(this->adres, napis);
	strcpy(temporarna, temporarna2);
	this->wpisz(temporarna);
	if (temporarna) {
		delete temporarna;
	}
	if (temporarna2) {
		delete temporarna2;
	}
}

//
//
// Klasa samochodu
//
//

samochod::samochod(float ciezar, int pojemnosc, Kierowca kierowca) {
	this->ciezar = ciezar;
	this->pojemnosc = pojemnosc;
	this->kierowca = kierowca;
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

void samochod::drukuj(char *strin, float masa)
{
	cout << strin << "[kg] to " << masa << "\n\n";
}
void samochod::drukuj(char *strin, int pojemnosc)
{
	cout << strin << "[ccm] to " << pojemnosc << "\n\n";
}

void samochod::pokaz_status()
{
	cout << "Otwarcie zaworu to  " << this->otwarcie_zaworu << "\npredkosc to " << this->predkosc_aktualna << "\n";
	cout << "Pokonano " << this->pokonna_odleglosc / 1000 << " km\n\n";
	this->drukuj("Pojemnosc", this->pojemnosc);
	this->drukuj("Masa", this->ciezar);
}
void samochod::jedz()
{
	while (this->pokonna_odleglosc / 1000 < ODLEGLOSC_DO_POKONANIA)
	{
		char znak = getch(); //note: z niewiadomego powodu za kazdym razem getch pobiera dwa znaki, wlasciwy i 32
		if (znak == STRZALKA_UP || znak == STRZALKA_DOWN || znak == SPACJA) {
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

//
//
// Klasa kierowcy
//
//
void Kierowca::drukuj() {
	cout << "Imie: " << imie.adres << ", Nazwisko: " << nazwisko.adres << ", Pesel:" << pesel << endl;
}
