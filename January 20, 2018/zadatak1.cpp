#include <iostream>
#include <iomanip>
using namespace std;

/*
Napisati program koji će učitati cijeli broj n (1<n<10), (ukoliko unesena vrijednost nije unutar intervala,
učitavanje se treba ponavljati sve dok se ne unese ispravna vrijednost) i elemente matrice dimenzije kvadratne(nxn),
te ispisati je li matrica centralno simetricna s obzirom na sredisnji element. Ako jest, program treba ispisati 1, ako nije,
ispisati 0, a ako je broj redaka paran(pa nema središnjeg elementa) ispisati -1.

Koristiti zasebne funkcije za unos elemenata i provjeru simetricnosti.
*/
const int var = 10;
void unos(int niz[][var], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << "Unesi niz[" << i << "][" << j << "] = ";
			cin >> niz[i][j];
		}
		cout << endl;
	}
	system("CLS");
}

void ispis(int niz[][var], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << setw(7) << niz[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

bool simetricna(int niz[][var],int n)
{
	int r = n-1;
	n /= 2;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (niz[i][j] != niz[r-i][r-j])
				return false;
		}
	}
	return true;
}

int main()
{
	int n;
	int niz[var][var];

	cout << "NAPOMENA:(1<n<10)" << endl << endl;
	do
	{
		cout << "Unesi n = ";
		cin >> n;
	} while (n<1 || n > 10);
	system("CLS");


	if (n % 2 != 0)
	{
		unos(niz, n);
		ispis(niz, n);
		if (simetricna(niz, n) == true)
			cout << "Matrica je simetricna." << endl;
		else
			cout << "Matrica nije simetricna." << endl;
	}
	else
		cout << "Broj redaka nije paran, tako da matrica ne moze biti izracunata i time nije simetricna." << endl;


	system("PAUSE");
	return 0;
}