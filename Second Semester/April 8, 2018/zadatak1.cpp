/*Kreirajte niz objekata ljubimac(o broju objekata odlučuje korisnik) sa sljedećim obilježjima :
•	ime,
•	dob(u mjesecima)
•	vrsta
•	spol,
•	datum cijepljenja(3)(prethodno kreirati strukturu)
•	vrsta cijepljenja

Kreirajte :
•	fukciju za u za unos obilježja jednog objekta;
•	funkciju za ispis obilježja jednog objekta;
•	funkciju koja će pronaći i objekt(e) / ljubimca(e) one vrste koje korisnik odabere; za ispis koristite funkciju za ispis;
•	funkciju koja pronalazi sve ljubimce koji su cijepljeni na datum koji odabere korisnik; za ispis koristite funkciju za ispis;
•	funkciju čija je zadaća da pronađe ljubimca s najkraćim imenom;
•	funkciju koja će kreirati novi niz ljubimaca u kojem će se nalaziti podaci o ljubimcima koji su mlađi od 13 mjeseci;
•	fukciju koja će provjeriti postoje li dva ljubimca s istim imenom;
•	dealocirati sve dinamički kreirane objekte.*/

#include <iostream>
using namespace std;


void crta()
{
	cout << " - - - - - - - - - - - - - - - - " << endl;
}

struct Datum {
	int dan, mjesec, godina;
	void unos()
	{
		cin >> dan >> mjesec >> godina;
	}
	
	void ispis()
	{
		cout << "- datum: " << dan << "/" << mjesec << "/" << godina << endl;
	}

	

};

bool istiDatum(Datum Datum1, Datum Datum2)
{
	return Datum1.dan == Datum2.dan && Datum1.mjesec == Datum2.mjesec && Datum1.godina == Datum2.godina;
}

struct ljubimac
{
	char *ime;
	int dob;//(u mjesecima)
	char *vrsta;
	char spol;
	Datum datumCijepljenja;
	char *vrstaCijepljenja;

	void unos()
	{

		cout << "UENSI: " << endl;

		cout << "- ime: ";
		char temp[15];
		cin.getline(temp, 15);

		ime = new char[15];
		strcpy_s(ime, 15, temp);
		
		cout << "- vrstu: ";
		cin.getline(temp, 15);

		vrsta = new char[15];
		strcpy_s(vrsta, 15, temp);

		cout << "- spol: ";
		cin >> spol;

		cout << "- datum rođenja dd mm gggg: ";
		cin >> datumCijepljenja.dan >> datumCijepljenja.mjesec >> datumCijepljenja.godina;
		cin.ignore();

		cout << "- vrsta cijepljenja: ";
		cin.getline(temp, 15);
		vrstaCijepljenja = new char[15];
		strcpy_s(vrstaCijepljenja, 15, temp);


		cout << "- dob: ";
		cin >> dob;
		cin.ignore();
	}

	void ispis()
	{
		cout << "ISPIS: " << endl;
		cout << "- ime: " << ime << endl;
		cout << "- vrstu: " << vrsta << endl;
		cout << "- spol: " << spol << endl;
		cout << "- vrsta cijepljenja: " << vrstaCijepljenja << endl;
		datumCijepljenja.ispis();
		cout << "- dob: " << dob << endl;
		cout << endl;
	}

};

void pronadjiLjubimce(ljubimac *obj, int n)
{
	char temp[15];
	cout << "Uneski vrstu, kako bih se prema njoj napravila pretraga: ";
	cin.getline(temp, 15);
	

	cout << "Ljubimci pronadjeni: " << endl;
	
	for (size_t i = 0; i < n; i++)
		if (strcmp(obj[i].vrsta, temp) == 0)
			obj[i].ispis();
	
}

void cijepljeniDatuma(ljubimac *obj, int n)
{
	cout << "Unesi datum na kojeg hocete da pretrazite dd mm gggg: ";
	Datum temp;
	temp.unos();
	
	for (size_t i = 0; i < n; i++)
		if (istiDatum(temp,obj[i].datumCijepljenja))
			obj[i].ispis();
}

void najkraćeIme(ljubimac *obj, int n)
{
	int indeks = 0;

	for (int i = 1; i < n; i++)
		if (strlen(obj[indeks].ime) > strlen(obj[i].ime))
			indeks = i;

	cout << "Najkraće ime je: " << obj[indeks].ime << endl;
}

int brojac13Mj(ljubimac *obj, int n)
{
	int brojac = 0;

	for (int i = 0; i < n; i++)
		if (obj[i].dob < 13)
			brojac++;

	return brojac;
}

ljubimac *ispod13Mj(ljubimac *obj, int n, int brojac)
{
	ljubimac *temp = new ljubimac[brojac];

	int indeks = 0;

	for (int i = 0; i < n; i++)
		if (obj[i].dob < 13)
			temp[indeks++] = obj[i];

	return temp;
}

bool istaImena(ljubimac *obj, int n)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			if (i == j)
				continue;
			if (strcmp(obj[i].ime, obj[j].ime) == 0)
				return true;
		}


	return false;
}

void dealokacija(ljubimac *&obj, int n)
{
	for (int i = 0; i < n; i++)
	{
		delete[] obj[i].ime;
		delete[] obj[i].vrsta;
		delete[] obj[i].vrstaCijepljenja;
		obj[i].ime = nullptr;
		obj[i].vrsta = nullptr;
		obj[i].vrstaCijepljenja = nullptr;
	}
	delete[] obj;
	obj = nullptr;
}


int main()
{
	const int n = 3;
	ljubimac *ljubimci = new ljubimac[n];

	for (int i = 0; i < n; i++)
		ljubimci[i].unos();
	
	system("CLS");


	for (int i = 0; i < n; i++)
		ljubimci[i].ispis();
	

	
	crta();
	pronadjiLjubimce(ljubimci, n);
	crta();
	cijepljeniDatuma(ljubimci, n);
	crta();
	najkraćeIme(ljubimci, n);
	crta();

	int brojac = brojac13Mj(ljubimci, n);
	ljubimac *ljubimciMladi = nullptr;
	if (brojac != 0)
		ljubimciMladi = ispod13Mj(ljubimci, n, brojac);
	cout << "Mladi ljubimci: " << endl;
	for (int i = 0; i < brojac; i++)
		ljubimciMladi[i].ispis();
	crta();

	if (istaImena(ljubimci, n) == true)
		cout << "Postoje ljubimci sa istim imenima." << endl;

	dealokacija(ljubimci, n);
	if (brojac != 0)
		dealokacija(ljubimciMladi, brojac);

	system("PAUSE");
	return 0;
}