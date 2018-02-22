#include <iostream>
using namespace std;

void inicijaliziraj(int[], int, int);
float aritmetricka(int[], int);
int pronaci(int[], int, float);
float apsolutno(float);


/*
Broj sestocifreni rastavi na brojeve i napravi od njeganiz, 
nakon toga izračunaj aritmetričku sredinu i također pronađi 
najblizi broj aritmetričku sredinu.
*/
int main()
{
	int broj;

	const int velicina = 6;

	int niz[velicina];

	do
	{
		cout << "Unesi sestoznamenkasti broj: ";
		cin >> broj;
	} while (broj<99999);

	inicijaliziraj(niz, broj, velicina);

	for (int i = 0; i < velicina; i++)
	{
		cout << niz[i] << " ";
	}
	cout << endl;


	float aritmetrickaSredina = aritmetricka(niz, velicina);
	cout << "Aritmetricka sredina: " << aritmetrickaSredina << endl;

	cout << "Najblizi: " << pronaci(niz, velicina, aritmetrickaSredina) << endl;


	system("PAUSE");
	return 0;
}

void inicijaliziraj(int niz
	[], int broj, int velicina)
{
	for (int i = 0; i < velicina; i++)
	{
		niz[i] = broj % 10;
		broj /= 10;
	}
}

float aritmetricka(int niz[], int velicina)
{
	int suma = 0;
	for (int i = 0; i < velicina; i++)
	{
		suma += niz[i];
	}
	return float(suma)/velicina;
}

float apsolutno(float broj)
{
	if (broj < 0)
		broj = broj * -1;
	//cout << broj << endl;
	return broj;
}

int pronaci(int niz[], int velicina, float aritmetricka)
{
	float najblizi = apsolutno(float(aritmetricka - niz[0]));
	int povrat = niz[0];
	for (int i = 1; i < velicina; i++)
	{
		float apsolutniBroj = apsolutno(float(aritmetricka - niz[i]));

		if (najblizi > apsolutniBroj)
		{
			najblizi = apsolutniBroj;
			povrat = niz[i];
		}
	}
	return povrat;
}
