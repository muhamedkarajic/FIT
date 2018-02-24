/*
Zadatak 2
Napisati program koji će učitati prirodni broj n ≤ 10, a zatim n prirodnih trocifrenih brojeva koje 
treba pospremiti u odgovarajući niz.Taj niz brojeva treba sortirati uzlazno po srednjoj cifri. 
Nakon sortiranja treba ispisati dobiveni niz. Za sortiranje koristiti zasebnu funkciju kojoj se proslijeđuje nesortiran niz.
*/


#include <iostream>
using namespace std;

const int var = 7;

void unos(int niz[var])
{
	cout << "Unesi niz: ";
	for (int i = 0; i < var; i++)
	{
		do
		{
			cin >> niz[i];
		} while (niz[i] > 999 || niz[i] < 100);
	}
	system("CLS");
}

void ispis(int niz[var])
{
	for (int i = 0; i < var; i++)
	{
		cout << niz[i] << " ";
	}
	cout << endl;
}

int srednjaCifra(int n)
{
	return (n / 10) % 10;
}

void sortiranje(int niz[var])
{
	int duzina = var - 1;
	int pomocna; 
	bool sortirano = false;
	int brojac = 0;
	while (sortirano != true)
	{
		sortirano = true;
		for (int i = 0; i < duzina; i++)
		{
				brojac++;
			if (srednjaCifra(niz[i]) > srednjaCifra(niz[i + 1]))
			{
				pomocna = niz[i];
				niz[i] = niz[i + 1];
				niz[i + 1] = pomocna;
				sortirano = false;
			}
		}
		duzina--;
	}
	cout << "BROJAC: " << brojac << endl;
}

int main()
{
	int niz[var] = { 134, 847, 926, 492, 402, 837, 846 };

	//unos(niz);
	ispis(niz);

	sortiranje(niz);
	
	ispis(niz);
	system("PAUSE");
	return 0;

}