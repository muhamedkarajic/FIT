#include <iostream>
using namespace std;

/*
Dat je cjelobrojni niz od 6 elemenata.
a) Napišite program koji će omogućiti korisniku da unese vrijednosti članova niza te provjeriti i ispisati najveći i najmanji član niza.
b) Riješite problem uz pomoć funkcija.

POŠTUJUĆI SVE FAZE PROCESA PROGRAMIRANJA!

*/

void unosNiza(int niz[], int var)
{
	for (int i = 0; i < var; i++)
	{
		cout << "niz[" << i << "] = ";
		cin >> niz[i];
	}
}
int najveciBroj(int niz[], int var)
{
	int najveci = niz[0];

	for (size_t i = 0; i < length; i++)
	{

	}


	return najveci;
}

int main()
{
	const int var = 7;
	int niz[var], broj;

	unosNiza(niz, var);

	cout << "Unesi broj: ";
	cin >> broj;

	cout << "Brojac: " << brojac(niz, var, broj) << endl;

	cout << rekurzivno(niz, var, broj, 0) << endl;

	system("PAUSE");
	return 0;
}