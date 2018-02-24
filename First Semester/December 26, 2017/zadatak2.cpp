#include <iostream>
using namespace std;

/*
Napisi program koji omoguci kreitanje matrice 3x5. Svaki red u matrici 
predstavlja kandidata za gradonačelnika, a svaka od kolona irborno mjesto.
Elementi matrice predstavljaju broj glasova za pojedinog kandidata na određenom 
izbornom mjsetu.

Uz pomoć:
-void unos(int[]); omogućite unos postignutih rezultata glasanja za sve kandidate posebno; 
broj glasova može biti 0, ali ne može biti manji od toga
-int kandidat(int[][5]); pronaći kandidata koji je pobijedio na izborima
-int gubitnik(int[][5]); pronaći kandidata koji je imao najmanje glasova na izbornom mjestu kojeg odabere korisnik;
-int izborno1(int[][5]); ponaci izborno mjestu na kojem je izašao najmanje birača(izbornih mjesta ima 5).
-int izborno2(inz[][], int); zbrojati koliko je glasača ukupno glasalo na izbornom mjestu koje odabere 
korisnik(izbornih mjesta ima 5).
*/


const int red = 3, kolona = 5;

void unos(int niz[])
{
	for (int i = 0; i < kolona; i++)
	{
		do
		{
			cout << "niz[" << i << "] = ";
			cin >> niz[i];
		} while (niz[i] < 0);
	}
}

void ispis(int niz[][kolona])
{
	for (int i = 0; i < red; i++)
	{
		for (int j = 0; j < kolona; j++)
		{
			cout << niz[i][j] << " ";
		}
		cout << endl;
	}



}


int suma(int niz[])
{
	int suma = 0;
	for (int i = 0; i < kolona; i++)
	{
		suma = niz[i];
	}
	return suma;
}




int kandidat(int niz[][kolona])
{
	int suma0 = suma(niz[0]);
	int suma1 = suma(niz[1]);
	int suma2 = suma(niz[2]);



	if (suma0 > suma1 && suma0 > suma2)
		return 0;

	else if (suma1 > suma0 && suma1 > suma2)
		return 1;
	
	else
		return 2;
}

int gubitnik(int niz[][kolona])
{
	int odabirKolone;
	cout << "KOLONA MORA BITI MINIMUM: 0 ILI BAREM JEDNAKA: " << kolona << endl;

	do
	{
		cout << "Odaberi kolonu: ";
		cin >> odabirKolone;
	} while (odabirKolone < 0 || odabirKolone > kolona);

	int najmanji = niz[0][odabirKolone], redak=0;

	for (int i = 0; i < red; i++)
	{
		if (niz[i][odabirKolone] < najmanji)
		{
			najmanji = niz[i][odabirKolone];
			redak = i;
		}
	}

	cout << najmanji << endl;
	return redak;


}

int izborno1(int niz[][kolona])
{
	int najmanji = niz[0][0] + niz[1][0] + niz[2][0];
	int redak = 0;
	int varijabla;
	for (int j = 1; j < kolona; j++)
	{
		varijabla = 0;
		for (int i = 0; i < red; i++)
		{
			varijabla += niz[i][j];
		}
		if (varijabla < najmanji)
		{
			najmanji = varijabla;
			redak = j;
		}
	}

	return redak;
}

int izborno2(int niz[][], int odabirKolone)
{
	int suma = 0;

	cout << "KOLONA MORA BITI MINIMUM: 0 ILI BAREM JEDNAKA: " << kolona << endl;

	do
	{
		cout << "Odaberi kolonu: ";
		cin >> odabirKolone;
	} while (odabirKolone < 0 || odabirKolone > kolona);

	for (int i = 0; i < red; i++)
	{
		suma += niz[i][odabirKolone];
	}

	return suma;
}

int main()
{
	int niz[red][kolona];

	cout << "UNOS MORA BITI VECI ILI JEDNAK BROJU NULI." << endl << endl;
	for (int i = 0; i < red; i++)
	{
		cout << "Kandidat broj: " << i+1 << endl;
		unos(niz[i]);
	}

	cout << "Kandidat broj " << kandidat(niz) + 1 << " je pobjedio." << endl;


	ispis(niz);

	cout << "Kandidat je u tom mjestu " << gubitnik(niz) + 1 << " je izgubio." << endl;

	cout << "Najmanji red je : " << izborno1(niz) << endl;

	cout << "Suma je: " << izborno2(niz, odabirKolone)

	system("PAUSE");
	return 0;
}