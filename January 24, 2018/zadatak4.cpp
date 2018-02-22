/*
Napisati program koji od korisnika zahtijeva unos niza od najviše 20 realnih brojeva u rasponu od -100 do 100. 
U slučaju da korisnik unese bilo koji broj izvan datog raspona korisnik ponavlja unos tog elementa niza. 
Također, unos je moguće prekinuti prije nego što se dostigne kapacitet niza unosom broja 0 koji ne treba 
da bude element niza i služi samo za prekid. Nakon toga, program računa aritmetičku sredinu unesenih brojeva, 
te iz niza izbacuje sve one elemente čija je udaljenost od aritmetičke sredine veća od 10, na način da se sačuva 
redoslijed dodavanja elemenata. Implementaciju uraditi upotrebom sljedećih funkcija:
•	void unos (double[], int, int&); gdje je treći parametar stvarna veličina niza nakon unosa;
•	double aritmeticka_sredina(double[], int);
•	void ukloni(double[], int, double, int&); gdje je drugi parametar aritmetička sredina, a posljednji veličina 
niza nakon uklanjanja elemenata.
U glavnom programu testirati dostupne funkcije, te obaviti ispis elemenata niza nakon uklanjanja vodeći se datim 
primjerom izlaza.
Unesite elemente niza: 2.5 -8.9 15.89 16.78 34 25 11 0
Aritmeticka sredina elemenata niza iznosi: 13.75
Sadrzaj niza nakon uklanjanja: 15.89 16.78 11.00
*/


#include <iostream>
using namespace std;


const int var = 8;

bool unos(double niz[var])
{
	int brojac = 0;
	for (int i = 0; i < var; i++)
	{
		do
		{
			cin >> niz[i];
			if (niz[i] == 0)
			{
				return brojac;
			}
		} while (niz[i] < -100 || niz[i] > 100);
		brojac++;
	}
	system("CLS");
	return brojac;
}

double aritmetrickaSredina(double niz[var])
{
	double suma, brojac;
	suma = brojac = 0;
	for (int i = 0; i < var && niz[i] != 0; i++)
	{
		suma += niz[i];
		brojac++;
	}
	return suma / brojac;
}

void ukloni(double niz[], double ar, int &brojac)
{//2.5 -8.9 15.89 16.78 34 25 11 0
	for (int i = 0; i < var; i++)
	{
		if (!(niz[i] + 10 > ar && niz[i] - 10 < ar))
		{
			niz[i] = 0;
		}
	}
}

void ispis(double niz[])
{
	for (int i = 0; i < var; i++)
	{
		if (niz[i] != 0)
		{
			cout << niz[i] << " ";
		}
	}
}
int main()
{
	double niz[var];
	int brojac = unos(niz);
	cout << "aritmetrickaSredina: " << aritmetrickaSredina(niz) << endl;
	ukloni(niz, aritmetrickaSredina(niz), brojac);
	ispis(niz);
	system("PAUSE");
	return 0;
}