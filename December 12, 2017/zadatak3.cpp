#include <iostream>
using namespace std;

/*
Zadatak2: Dat je realan niz od 6 elemenata. Napišite program koji će omogućiti korisniku da unese vrijednosti članova niza,
te provjeriti i ispisati koliko je članova niza veće od vrijednosti koju također unosi korinik preko tastature.
*/

void unosNiza(int niz[], int var)
{
	for (int i = 0; i < var; i++)
	{
		cout << "niz[" << i << "] = ";
		cin >> niz[i];
	}
}

int brojac(int niz[], int var, int broj)
{
	int suma = 0;
	for (int i = 0; i < var; i++)
		if (niz[i] > broj)
			suma++;
	return suma;
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