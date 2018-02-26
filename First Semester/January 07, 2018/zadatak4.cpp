#include <iostream>
#include <iomanip>
using namespace std;

/*
Zadatak 2: Napišite program u kojem ćete deklarirati matricu 3x4. 
Omogućite korisniku da  unese 
- vrijednosti članova niza s tastature, 
- te da izabere red 
- i kolonu čiju sumu želi izračunati. 
Za izračunavanje sume reda, sume kolone, unos  i ispis elemenata upotrijebite funkcije.
*/

const int red = 3, kolona = 4;

void unos(int niz[][kolona])
{
	for (int i = 0; i < red; i++)
	{
		for (int j = 0; j < kolona; j++)
		{
			cout << "niz[" << i << "][" << j << "] = ";
			cin >> niz[i][j];
		}
	}
	cout << endl;
}

void ispis(int niz[][kolona])
{
	for (int i = 0; i < red; i++)
	{
		for (int j = 0; j < kolona; j++)
		{
			cout << setw(5) << niz[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

int redSuma(int niz[][kolona])
{
	int suma = 0, k;
	
	cout << "Unesi red kojeg zelis izracunati: ";
	cin >> k;

	for (int i = 0; i < red; i++)
		suma += niz[i][k];

	return suma;
}

int kolonaSuma(int niz[][kolona])
{
	int suma = 0, r;

	cout << "Unesi kolonu koju zelis izracunati: ";
	cin >> r;

	for (int i = 0; i < kolona; i++)
		suma += niz[r][i];

	return suma;
}

int main()
{
	int niz[red][kolona];
	unos(niz);
	ispis(niz);

	int sumaReda = redSuma(niz);
	cout << "Suma tog reda je: " << sumaReda << endl;

	int sumaKolone = kolonaSuma(niz);
	cout << "Suma kolone je: " << sumaKolone << endl;

	system("PAUSE");
	return 0;
}