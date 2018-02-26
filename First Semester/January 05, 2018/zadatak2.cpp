#include <iostream>
using namespace std;

/*
Napišite program koji će omogućiti unos:
o	niza 7 cijelih brojeva pomoću funkcije: void unos (int [], int);
te izračunati i ispisati sljedeće:
o	aritmetičku sredinu neparnih elemenata niza uz pomoć funkcije:
float aritmeticka(int [], int);
o	koliko ima pozitivnih brojeva uz pomoć funkcije:
int pozitivnih(int [], int);
o	sve članove niza koji u na mjestu desetica imaju znamenku 4 uz pomoć funkcije:
int znamenka4(int [], int)

*/

const int var = 7;
float aritmeticka(int niz[])
{
	int suma = 0;
	int brojac = 0;
	for (int i = 0; i < var; i++)
	{
		if (niz[i] %2 != 0)
		{
			suma += niz[i];
			brojac++;
		}
	}
	return suma / (float)brojac;
}
void ispis(int niz[])
{
	for (int i = 0; i < var; i++)
	{
		cout << niz[i] << " ";
	}
	cout << endl;
}

int pozitivnih(int niz[])
{
	int brojac = 0;
	for (int i = 0; i < var; i++)
	{
		if (niz[i] % 2 == 0)
		{
			brojac++;
		}
	}
	return brojac;
}

int znamenka4(int niz[])
{
	int brojac = 0;
	for (int i = 0; i < var; i++)
	{
		if (niz[i]/10%10 == 4)
		{
			brojac++;
		}
	}
	return brojac;
}
int main()
{
	int niz[var] = { 6,43,3,9,44,2,4 };
	ispis(niz);
	cout << "Aritmetricka suma neparnih cifara je: " << aritmeticka(niz) << endl;
	cout << "Pozitivnih elemenata niz ima: " << pozitivnih(niz) << endl;
	cout << "Brojevi koji na mjestu desetica imaju znamenku 4: " << znamenka4(niz) << endl;

	cout << endl;
	system("PAUSE");
	return 0;
}