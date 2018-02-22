#include <iostream>
using namespace std;

/*
Zadatak 3: 
Dat je dvodimenzionalni niz (matrica 3x4) OcjeneStudenata. 
Svaki red predstavlja studenta, a svaka kolona predstavlja ocjenu koju je student postigao na ispitima. 
Definirajte i upotrijebite:

o funkciju koja će omogući unos ocjena za sve studente; 
o funkciju za ispis svih ocjena; 
o funkciju koja će naći najmanju ocjenu; 
o funkciju koja naći najveću ocjenu; 
o funkciju koja će izračunati prosječnu ocjenu za svakog studenta.
*/

const int red = 3, kolona = 4;
//3 studenta, 4 predmeta

void unos(int niz[kolona])
{
	for (int i = 0; i < kolona; i++)
		do
		{
			cin >> niz[i];
		} while (niz[i] < 5 || niz[i] > 10);
}

void ispis(int niz[][kolona])
{
	for (int j = 0; j < red; j++)
	{
		for (int i = 0; i < kolona; i++)
		{
			cout << niz[j][i] << " ";
		}
		cout << endl;
	}
}

int najmanja(int niz[][kolona])
{
	int min = niz[0][0];

	for (int i = 0; i < red; i++)
		for (int j = 0; j < kolona; j++)
			if (min > niz[i][j])
				min = niz[i][j];

	return min;
}

int najveca(int niz[][kolona])
{
	int max = niz[0][0];

	for (int i = 0; i < red; i++)
		for (int j = 0; j < kolona; j++)
			if (max < niz[i][j])
				max = niz[i][j];

	return max;
}

float prosjek(int niz[kolona])
{
	int suma = 0;

	for (int i = 0; i < kolona; i++)
			suma += niz[i];

	return (float)suma / kolona;
}


int main()
{
	int niz[red][kolona];

	cout << "NAPOMENA: OCJENE MORAJU BITI OD 5 DO 10." << endl;
	for (int i = 0; i < red; i++)
	{
		cout << "Ocijene " << i + 1 << ". studenta: ";
		unos(niz[i]);
	}
	
	ispis(niz);

	cout << "Najmanja ocjena je : " << najmanja(niz) << endl;
	cout << "Najveca ocjena je: " << najveca(niz) << endl;

	for (int i = 0; i < red; i++)
		cout << "Prosjek " << i+1 << ". studenta je: " << prosjek(niz[i]) << endl;

	system("PAUSE");
	return 0;
}