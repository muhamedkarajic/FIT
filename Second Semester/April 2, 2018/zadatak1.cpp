#include <iostream>
using namespace std;

struct Datum { int dan, mjesec, godina; };

struct Student {
	char indeks[9];//IB130130
	char imePrezime[30];
	Datum datumRodjenja;
};
char * GetSljedeciBrojIndeksa(char * posljednji) {
	/*Funkcija treba da vrati sljedeći broj indeksa (u odnosu na onaj koji je
	primljen kao parametar)prateći format IB130XXX pri cemu je fiksni dio u oznaci
	indeksa IB130, a posljednje 3 oznake se mijenjaju. Voditi racuna da broj indeksa
	uvijek posjeduje 8 znakova*/



	for (int i = strlen(posljednji)-1; i > 4; i--)
		if (posljednji[i] == '9')
			posljednji[i] = '0';
		else
		{
			posljednji[i] += 1;
			break;
		}
	return posljednji;
}
Student * GetStudentePoDatumuRodjenja(Student * lista, int max, Datum starijiOd, int &brojac) {
	/*Funkcija treba da vrati niz studenata koji su rođeni nakon datuma rođenja
	definisanog parametrom starijiOD. Ako ne postoji niti jedan student koji
	zadovoljava uslove pretrage, onda funkcija vraća NULL*/
		
	const int starijiOdDani = starijiOd.dan + starijiOd.mjesec * 30 + starijiOd.godina * 365;

	for (int i = 0; i < max; i++)
		if (lista[i].datumRodjenja.dan + lista[i].datumRodjenja.mjesec * 30 + lista[i].datumRodjenja.godina * 365 > starijiOdDani)
			brojac++;

	if (brojac == 0)
		return nullptr;

	Student *niz = new Student[brojac];
	int index = 0;
	for (int i = 0; i < max; i++)
		if (lista[i].datumRodjenja.dan + lista[i].datumRodjenja.mjesec * 30 + lista[i].datumRodjenja.godina * 365 > starijiOdDani)
			niz[brojac++] = lista[i];

	return niz;
}
int main() {
	//1. korisniku omoguciti da odredi koliko objekata tipa Student zeli kreirati.
	int n;
	cout << "Unesi broj studenata: ";
	cin >> n;
	cin.ignore();

	if (n<1)
		return 0;
	
	// Objekte kreirati u dinamickoj memoriji
	Student *niz = new Student[n];
	int duzinaIme = strlen(niz->imePrezime);

	//2. korisniku omoguciti da unutar main funkcije inicijalizuje vrijednosti
	// atributa svakog studenta. Tom prilikom iskoristiti funkciju
	// GetSljedeciBrojIndeksa

	cout << "1. student: ";

	cout << "Ime i prezime: ";
	cin.getline(niz[0].imePrezime, duzinaIme);

	strcpy_s(niz[0].indeks, "IB130130");
	cout << "Index: " << niz[0].indeks << endl;

	cout << "Datum rodjenja (dd mm gggg): ";
	cin >> niz[0].datumRodjenja.dan >> niz[0].datumRodjenja.mjesec >> niz[0].datumRodjenja.godina;
	cin.ignore();
	cout << endl;

	for (int i = 1; i < n; i++)
	{
		cout << i + 1 << ". student: ";

		cout << "Ime i prezime: ";
		cin.getline(niz[i].imePrezime, duzinaIme);

		cout << "Index: ";
		strcpy_s(niz[i].indeks, GetSljedeciBrojIndeksa(niz[i-1].indeks));

		cout << "Datum rodjenja (dd mm gggg): ";
		cin >> niz[i].datumRodjenja.dan >> niz[i].datumRodjenja.mjesec >> niz[i].datumRodjenja.godina;
		cin.ignore();
	}

	//3. korisniku omoguciti pretragu studenata po datumu rodjenja, te ispisati rezultat pretrage
	int brojac = 0;
	Student *nizPoDatumu = GetStudentePoDatumuRodjenja(niz, n, { 1,1,2017 }, brojac);

	if (nizPoDatumu != nullptr)
		for (int i = 0; i < brojac; i++)
			cout << nizPoDatumu[i].imePrezime << endl;

	//4. izvrsiti potrebne dealokacije
	delete[] niz;
	niz = nullptr;

	system("PAUSE");
	return 0;
}
 