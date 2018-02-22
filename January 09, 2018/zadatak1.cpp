#include <iostream>
using namespace std;

/*
Napisite program u kojem cete deklarirati i unijeti elemnte dva cijelobrojna niza od po 5 elemnata. 
Nakon toga kreirajte treci niz od 10 elemenata u koji cete smjestiti elemente iz predhodna dva niza ali u rastucem poretku.

Elementi treceg nia moraju biti poredani tako da je niz3[0]<niz[1]<niz[3]<...

Za svaki od zahtjeva zadataka kreirajte zasebnu funkciju.
*/


const int var = 5;
const int var2 = 10;

void unos(int niz[])
{
	for (int i = 0; i < var; i++)
	{
		cout << "niz[" << i << "] = ";
		cin >> niz[i];
	}
}

void ispis(int niz[], int var)
{
	for (int i = 0; i < var; i++)
	{
		cout << niz[i] << " ";
	}
}

void sortiranje(int niz[], int duzina)
{
	bool sortirano = false;
	int pomocna;
	int brojac = 0;
	int brojProlaza = 0;
	while (sortirano == false)
	{
		sortirano = true;
		for (int i = 0; i < duzina-1-brojac; i++)
		{
			if (niz[i+1]>niz[i])
			{
				pomocna = niz[i];
				niz[i] = niz[i + 1];
				niz[i + 1] = pomocna;
				sortirano = false;
			}
			brojProlaza++;
			brojac++;
		}
	brojac=0;
	}
	cout << endl;
	cout << "Broj prolaza: " << brojProlaza << endl;
}

void spajanje(int niz1[], int niz2[], int niz3[])
{
	for (int i = 0; i < var; i++)
	{
		niz3[i] = niz1[i];
	}
	int brojac = 0;
	for (int i = var; i < var2; i++)
	{
		niz3[i] = niz2[brojac++];
	}
}




int main()
{
	int niz1[] = { 1235,632,636,94827,46329 }, niz2[] = { 987,9823,872,574,742 }, niz3[var2];
	
	unos(niz1);
	unos(niz2);



	ispis(niz1, var);
	cout << endl;
	ispis(niz2, var);
	cout << endl;
	spajanje(niz1, niz2, niz3);


	ispis(niz3, var2);
	cout << endl;

	sortiranje(niz3, var2);

	ispis(niz3, var2);
	cout << endl;


	system("PAUSE");
	return 0;
}