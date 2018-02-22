#include <iostream>
using namespace std;

void unos(float niz[], int var)
{
	for (int i = 0; i < var; i++)
	{
		cout << "niz[" << i << "] = ";
		cin >> niz[i];
	}
}

int negativnih(float niz[], int var)
{
	int brojac = 0;
	for (int i = 0; i < var; i++)
		if (niz[i] < 0)
			brojac++;

	return brojac;
}

float prosjekpoz(float niz[], int var)
{
	int brojac = 0;
	float suma = 0;
	for (int i = 0; i < var; i++)
		if (niz[i] > 0)
		{
			suma += niz[i];
			brojac++;
		}

	return suma / brojac;
}

int main()
{
	const int var = 7;
	float niz[7];

	unos(niz, var);
	cout << "Ukupno negativnih brojeva ima: " << negativnih(niz, var) << endl;
	cout << "Prosjecna vrijednost pozitivnih brojeva iznosi: " << prosjekpoz(niz, var) << endl;
	
	system("PAUSE");
	return 0;
}