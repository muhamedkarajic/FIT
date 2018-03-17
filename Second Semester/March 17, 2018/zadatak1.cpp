#include <iostream>
using namespace std;

struct Kategorija {
	char * oznakaKategorije;//A,A1,B,B1,C1E,...
	char datumPolaganja[11];//27.06.2015
};

struct Kandidat {
	
	//parametars
	char *imePrezime;
	Kategorija * polozene[10];
	int brPolozenih = 0;//brojac

	//methods
	void unos_polozene(int n)
	{
		for (int i = 0; i < n; i++)
		{
			polozene[brPolozenih] = new Kategorija;

			cout << "Unesi datum polaganja: ";
			cin.getline(polozene[brPolozenih]->datumPolaganja, 10);

			polozene[brPolozenih]->oznakaKategorije = new char[3];
			cout << "Unesi oznaku kategorije: ";
			cin >> polozene[brPolozenih]->oznakaKategorije;
			cin.ignore();

			brPolozenih++;
		}
	}
};

//kreirati funkcije za unos i ispis kategorije i kandidata
void unos_kategorije(Kategorija);
void unos(Kandidat *);
void ispis(Kandidat);


void dodajKategorijuKandidatu(Kandidat * niz, int max) {

	//Na pocetku funkcija ispisuje ime i prezime svih unesenih kandidata
	for (int i = 0; i < max; i++)
		cout << i + 1  << ". " <<  niz[i].imePrezime << endl;


	//Nakon odabira nekog od kandidata sa liste, funkcija treba omoguciti
	int x;
	cout << "Odaberi nekog od kandidata sa liste: ";
	cin >> x;
	cin.ignore();
	cout << "IME I PREZIME: " << niz[--x].imePrezime << endl;
	//inicijalizaciju podataka o novopolozenoj kategoriji
	niz[x].unos_polozene(1);
}

void pretragaPoKategorijama(Kandidat * niz, int max) {

	bool test = true;
	char oznaka[3];
	while (test == true)
	{
		//Na pocetku funkcije korisnik unosi oznaku kategorije za koju ce vrsiti pretragu. 
		cout << "Unesi oznaku kategorije: ";
		cin.getline(oznaka, 3);

		//Nakon unosa, funkcija pretrazuje podatke te ispisuje ime i prezime kandidata koji je polozio trazenu kategoriju
		for (int i = 0; i < max; i++)
			for (size_t j = 0; j < niz[i].brPolozenih; j++)
				if (strcmp(niz[i].polozene[j]->oznakaKategorije, oznaka)==0)
				{
					cout << " - " << niz[i].imePrezime << endl;
					break;
				}

		cout << "Zelite li ponovo traziti po kategorijama(0-ne/1-da): ";
		cin >> test;
		cin.ignore();

		system("cls");
		//Funkcija treba omoguciti korisniku da vise puta izvrsi pretragu
	}
}

void pretragaPoDatumuPolaganja(Kandidat * niz, int max) {

	//Na pocetku funkcije korisnik unosi datum polaganja po kome se vrsi pretraga
	cout << "Unesi datum polaganja kako bi se izvrsila pretraga: ";
	char datum[11];
	cin.getline(datum, 11);

	//Nakon unosa, funkcija pretrazuje datume polaganja svih kategorija kandidata.
	//Ako je neki od kandidata polagao na trazeni datum (bilo koju kategoriju)funkcija
	//treba da ispise:ime i prezime kandidata, te listu svih kategorija koje je taj
	//kandidat polozio bez obzira na period. Sve pomenute ispise vrsiti unutar funkcije
	for (int i = 0; i < max; i++)
		for (int j = 0; j < niz[i].brPolozenih; j++)		
			if (strcmp(niz[i].polozene[j]->datumPolaganja, datum) == 0)
			{
				ispis(niz[i]);
				break;
			}
}

void main()
{
	//Korisniku omoguciti da odredi broj kandidata cije ce podatke inicijalizovati.
	
	int n;
	cout << "Unesi broj kandidata: ";
	cin >> n;
	cin.ignore();
	
	//Nakon inicijalizacije podataka o kandidata demonstrirati koristenje svih globalnih funkcija
	Kandidat *k = new Kandidat[n];
	for (int i = 0; i < n; i++)
		unos(&k[i]);
	
	system("cls");

	for (int i = 0; i < n; i++)
	{
		ispis(k[i]);
		cout << endl;
	}

	dodajKategorijuKandidatu(k,n);

	system("cls");
	for (int i = 0; i < n; i++)
	{
		ispis(k[i]);
		cout << endl;
	}

	system("PAUSE>0");
	system("CLS");
	pretragaPoDatumuPolaganja(k, n);
	system("PAUSE>0");
	system("CLS");

	pretragaPoKategorijama(k, n);


	cout << endl;
	system("PAUSE>0");
}

void unos(Kandidat *k)
{
	k->imePrezime = new char[10];
	
	cout << "Unesi ime i prezime: ";
	cin.getline(k->imePrezime, 10);

	cout << "Unesi broj polozenih: ";
	int len;
	cin >> len;
	cin.ignore();

	k->unos_polozene(len);
}
void ispis(Kandidat k)
{
	cout << "Ime i prezime: " << k.imePrezime << endl;
	const int len = k.brPolozenih;
	
	cout << "- Polozeni:" << endl;
	for (int i = 0; i < len; i++)
	{
		cout << "Datum polaganja: " << k.polozene[i]->datumPolaganja << endl;
		cout << "Oznaka kategrorije: " << k.polozene[i]->oznakaKategorije << endl;
	}
}