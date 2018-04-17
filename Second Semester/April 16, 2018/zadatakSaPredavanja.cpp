#include <iostream>
using namespace std;

const char * crt = "\n----------------------------\n";

struct Datum {
	int *_dan, *_mjesec, *_godina;
};

void Unos(Datum &d) {
	d._dan = new int;
	d._mjesec = new int;
	d._godina = new int;

	cin >> d._dan >> d._mjesec >> d._godina;
	cin.ignore();
}

void Ispis(Datum &d) {
	cout << *d._dan << "." << *d._mjesec << "." << *d._godina << endl;
}

void Dealociraj(Datum &d) {
	delete d._dan;
	delete d._mjesec;
	delete d._godina;
	d._dan = nullptr;
	d._mjesec = nullptr;
	d._godina = nullptr;
}

struct Ocjena
{
	int _ocjena; //1-5
	char *predmet;
	Datum _datum;
	bool _ostavljenDatum;
	//u slucaju da ucenik nije bio spreman odgovarati onda se evidentira samo datum, 
	//a provjerava znanja ostavlja za naredni put
};
void Unos(Ocjena &d)
{
	
	cout << "Da li je bio spreman odgovarati: ";
	cin >> d._ostavljenDatum;
	cin.ignore();
	
	char temp[50];
	cout << "Unesi predmet: ";
	cin.getline(temp, 50);
	d.predmet = new char[50];
	strcpy_s(d.predmet, 50, temp);
	Unos(d._datum);

	if (d._ostavljenDatum == false)
	{
		cout << "Unesite ocjenu: ";
		do
		{
			cin >> d._ocjena;
		} while (d._ocjena < 1 || d._ocjena > 5);
	}
	else {
		d._ocjena = 0;
	}
}

void Ispis(Ocjena &d)
{

	cout << "Predmet: " << d.predmet << endl;
	cout << "Datum: ";
	Ispis(d._datum);

	if (d._ostavljenDatum == false)
		cout << "Ocjena: " << d._ocjena << endl;
	else
		cout << "Ovaj ucenik treba da naknadno odgovara. " << endl;
}

void Dealociraj(Ocjena &d)
{
	delete[] d.predmet;
	d.predmet = nullptr;
	Dealociraj(d._datum);
}



struct Ucenik
{
	char _brojUDnevniku[15];
	char *_imePrezime;
	Ocjena *_ocjene;
	int _trenutnoOcjena;// 0? 
};



void Unos(Ucenik &d, const char* brojUDnevniku = nullptr) {
	if (brojUDnevniku == nullptr)
		strcpy_s(d._brojUDnevniku, 15, brojUDnevniku);

	d._imePrezime = new char[20];
	char temp[20];
	cout << "Unesi ime i prezime: ";
	cin.getline(temp, 20);
	strcpy_s(d._imePrezime, 20, temp);
	d._ocjene = nullptr;
	d._trenutnoOcjena = 0;
	
}

void Ispis(Ucenik &d)
{
	cout << "Broj u dnevniku: " << d._brojUDnevniku << endl;
	cout << "Ime i prezime: " << d._imePrezime << endl;
}

void Dealociraj(Ucenik &d)
{
	delete[] d._imePrezime;
	d._imePrezime = nullptr;

	for (int i = 0; i < d._trenutnoOcjena; i++)
	{
		Dealociraj(*d._ocjene);
	}
}
struct Odjeljenje
{
	char _oznaka[15]; // primer oznaka: a, b, I, II, Matematicari i sl.
	Ucenik *_ucenici[30]; // maksimalno 30 ucenika u odjeljenju
};


void Unos(Odjeljenje &d) {

}

void Ispis(Odjeljenje &d)
{

}

void Dealociraj(Odjeljenje &d)
{

}

struct Razred
{
	int _oznakaRazreda; //1, 2 i sl.
	Odjeljenje *_odjeljenja;
	int _trenutnoOdjeljenja;

};

void Unos(Razred &d) {

}

void Ispis(Razred &d) {

}

void Dealociraj(Razred &d) {

}

char *GenerisiNaredniBrojUDnevniku(Razred &razred, const char *oznakaOdjeljenja) x{




	return nullptr;
}

bool DodajOdjeljenje(Razred &razred, const char*oznakaOdjeljenja)
{
	return true;
}

bool dodajUcenika(Razred &razred, char *oznakaOdjeljenja, char *imePrezime)
{
	int lokacijaOdjeljenja = -1;
	for (int i = 0; i < razred._trenutnoOdjeljenja; i++)
	{
		if (strcmp(oznakaOdjeljenja, razred._odjeljenja[i]._oznaka) == 0)
		{
			lokacijaOdjeljenja = i;
			break;
		}
	}

	int lokacijaUcenika = -1;


	if (lokacijaOdjeljenja != -1)
	{
		for (int i = 0; i < 30; i++)
		{
			if (razred._odjeljenja[lokacijaOdjeljenja]._ucenici == nullptr)
			{
				lokacijaUcenika = i;
				break;
			}
		}
	}

	if (lokacijaUcenika != -1)
    {
		razred._odjeljenja[lokacijaOdjeljenja]._ucenici[lokacijaUcenika] = new Ucenik;
		if (lokacijaUcenika == 0)
		{
			const temp[20];
			cout << "Unesite prvi broj za odjeljenje: " << oznakaOdjeljenja << " -> ";
			Unos(*razred._odjeljenja[lokacijaOdjeljenja]._ucenici[lokacijaUcenika], temp);
		}
		else
		{
			Unos(*razred._odjeljenja[lokacijaOdjeljenja]._ucenici[lokacijaUcenika], GenerisiNaredniBrojUDnevniku(razred, oznakaOdjeljenja));

		}
		
	}

	return true;
}

bool DodajOcjenu(Razred &razred, char *imePrezime, Ocjena ocjena)
{

	/*Ocjena * temp = new Ocjena[razred._odjeljenja[0]._ucenici[1]->_trenutnoOcjena + 1];
	razred._odjeljenja[0]._ucenici[1]->_ocjene = */

	return true;
}

//ako se ne prosljedi ime i prezime, program treba
void PrikaziUspjeh(Razred &razred, char*imePrezime = nullptr)
{

}


//napisati rekurzivnu funkciju koja ce vratiti adresu odjeljenja sa najvecim prosjekom
int PrikaziMenu() {
	int izbor;
	cout << crt << "\t::MENU::" << crt;
	cout << "1. Dodaj odjeljenje" << endl;
	cout << "2. Dodaj ucenika" << endl;
	cout << "3. Prikazi uspijeh" << endl;
	cout << "4. Kraj programa" << crt;
	do {
		cout << "Unesi izbor -> ";
		cin >> izbor;
	} while (izbor < 1 || izbor>4);


	//1 moze uvijek
	//2 pokrenut == false
	//3 pokrenut == false
	//4 pokrenut == true

	system("cls");
	return izbor;
}

void main()
{
	int izbor = 0;
	Razred razred_1a;
	Unos(razred_1a);

	do
	{
		izbor = PrikaziMenu();
		if (izbor == 1)
		{
			
		}
		else if (izbor == 2)
		{
			
		}
	} while (izbor != 4);
	Dealociraj(razred_1a);
	system("PAUSE");
}