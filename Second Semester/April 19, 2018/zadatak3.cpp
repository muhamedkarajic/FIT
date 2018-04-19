/*
Koristeći prikazane strukture i globalne funkcije, napisati program prema sljedećim uputama:
- Funkcije Unos i Ispis strukture
Pregled treba da omoguće inicijalizaciju i ispis vrijednosti atributa Dijagnoza i CijenaPregleda.
- Funkcija Unos strukture Pacijent treba da omogući inicijalizaciju atributa ImePrezime, atribut
BrojPosjeta treba postaviti na vrijednost 0, te u dinamičkoj memoriji alocirati prostor potreban
za pohranu 10 pregleda pacijenta (ovo se odnosi na atribut PreglediPacijenta).
- Funkcija Ispis strukture Pacijent treba da ispiše vrijednosti atributa strukture uključujući
podatke o svim obavljenim pregledima pacijenta.
- Funkcija AddPregled treba da omogući dodavanje podataka tj. inicijalizaciju vrijednosti atributa
koji se odnose na novi pregled pacijenta. Tom prilikom koristiti odgovarajuće funkcije kreirane u
prethodnom dijelu programa.
- Funkcija GetUkupneTroskove treba da vrati sumu novca koju je pacijent uplatio tokom svih svojih
pregleda.
- Globalna funkcija PovratNovca omogućava korisniku da izvrši povrat novca svim pacijentima koji
su za svoje preglede (sve preglede) platili više od određene sume. Na samom početku, funkcija od
korisnika zahtijeva da unese sumu novca koja služi kao kriterij pretrage. Svim pacijentima koji su za
svoje preglede uplatili više od definirane sume novca, funkcija treba da ispiše ime i prezime, umanji
cijenu svakog od pregleda za 10%, te ispiše sumu novca koju je potrebno vratiti pacijentu (pacijentu
se vraća 10% od ukupne uplate).
- Unutar main funkcije:
• Korisniku omogućiti da definira broj pacijenata čije podatke želi inicijalizirati
• Svakom od pacijenata inicijalizira podatke o tri pregleda
• Korisniku omogućiti da pacijentima izvrši povrat novca
• Ukoliko je potrebno, izvršiti dealociranje memorijskog prostora
*/
#include <iostream>
using namespace std;


const char *crt = "\n- - - - - - - - - - - - - - - -\n";

struct Pregled {

	char * Dijagnoza;

	double CijenaPregleda;

	void Unos()
	{
		char temp[20];
		cout << "Unesi dijagnozu: ";
		cin.getline(temp, 20);
		Dijagnoza = new char[20];
		strcpy_s(Dijagnoza, 20, temp);

		cout << "Unesi cijenu pregleda: ";
		cin >> CijenaPregleda;
		cin.ignore();
	}

	void Ispis()
	{
		cout << "Dijagnoza: " << Dijagnoza << ": " << CijenaPregleda << "KM" << endl;
	}

};

struct Pacijent {

	char *ImePrezime;

	Pregled * PreglediPacijenta[10];

	int BrojPosjeta;

	void Unos()
	{
		char temp[20];
		ImePrezime = new char[20];

		cout << "Unesi ime i prezime pacijenta: ";
		cin.getline(temp, 20);
		strcpy_s(ImePrezime, 20, temp);

		for (int i = 0; i < 10; i++)
			PreglediPacijenta[i] = new Pregled;
		
		BrojPosjeta = 0;

	}

	void Ispis()
	{
		cout << crt;
		cout << ImePrezime << endl;
		for (int i = 0; i < BrojPosjeta; i++)
		{
			cout << i + 1 << ": ";
			PreglediPacijenta[i]->Ispis();

		}
		cout << crt;
	}

	void AddPregled()
	{
		PreglediPacijenta[BrojPosjeta]->Unos();
		BrojPosjeta++;
	}

	double GetUkupneTroskove()
	{
		double suma = 0;
		for (int i = 0; i < BrojPosjeta; i++)
		{
			suma += PreglediPacijenta[i]->CijenaPregleda;
		}
		return suma;
	}

};



//-Globalna funkcija PovratNovca omogućava korisniku da izvrši povrat novca svim pacijentima koji
//su za svoje preglede(sve preglede) platili više od određene sume.Na samom početku, funkcija od
//korisnika zahtijeva da unese sumu novca koja služi kao kriterij pretrage.
//Svim pacijentima koji su za
//svoje preglede uplatili više od definirane sume novca, funkcija treba da ispiše ime i prezime, umanji
//cijenu svakog od pregleda za 10 % , te ispiše sumu novca koju je potrebno vratiti pacijentu(pacijentu
//	se vraća 10 % od ukupne uplate).
void PovratNovca(Pacijent * pok, int max)
{
	double suma;
	double akcija = 40;
	double ukupniTroskovi;

	for (int i = 0; i < max; i++)
	{
		ukupniTroskovi = pok[i].GetUkupneTroskove();
		suma;
		cout << "Unesi sumu novca: ";
		cin >> suma;
		cin.ignore();

		if (suma > akcija)
			ukupniTroskovi = ukupniTroskovi - ukupniTroskovi / 10;

		cout << pok[i].ImePrezime << "je potrebno vratiti: " << suma - ukupniTroskovi << "KM" << endl;
	}
}

void Dealokacija(Pacijent &p)
{
	delete[] p.ImePrezime;
	p.ImePrezime = nullptr;

	for (int i = 0; i < p.BrojPosjeta; i++)
	{
		delete[] p.PreglediPacijenta[i]->Dijagnoza;
		p.PreglediPacijenta[i]->Dijagnoza = nullptr;

		delete p.PreglediPacijenta[i]; 
		p.PreglediPacijenta[i] = nullptr;
	}
}


//	- Unutar main funkcije:
//• Korisniku omogućiti da definira broj pacijenata čije podatke želi inicijalizirati
//• Svakom od pacijenata inicijalizira podatke o tri pregleda
//• Korisniku omogućiti da pacijentima izvrši povrat novca
//• Ukoliko je potrebno, izvršiti dealociranje memorijskog prostora
//*/
void main()
{



	int n;
	cout << "Unesi broj pacijenata: ";
	cin >> n;
	cin.ignore();
	cout << crt;

	Pacijent *pacijenit = new Pacijent[n];
	
	for (int i = 0; i < n; i++)
		pacijenit[i].Unos();
	cout << crt;

	for (int i = 0; i < n; i++)
		pacijenit[i].Ispis();
	cout << crt;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < 3; j++)
			pacijenit[i].AddPregled();
	cout << crt;

	PovratNovca(pacijenit, n);
	cout << crt;

	for (int i = 0; i < n; i++)
		Dealokacija(pacijenit[i]);

	system("PAUSE");
}