/*
Zadatak 3: 

Dat je niz prirodnih brojeva od 12 elemenata. 
Napišite program koji će prebrojati koliko je elemenata niza djeljivo s tri (3). 
Kreirajte zasebne funkcije za unos elemenata niza i za provjeru dijeljivosti.
*/


#include <iostream>
using namespace std;

int unos(int niz[], int var)
{
	int brojac = 0;
	for (int i = 0; i < var; i++)
	{

		do
		{
			cout << "niz[" << i << "] = ";
			cin >> niz[i];
		} while (niz[i]<0);

		if (niz[i]%3==0)
		{
			brojac++;
		}

		
		system("CLS");
		for (int y = 0; y <= i; y++)
		{
			cout << "niz[" << y << "] = " << niz[y] << endl;
		}
	}
	
	return brojac;
}

int main()
{
	const int var = 12;
	int niz[var];

	cout << "Varijable koje su djeljive sa tri, u nizu su " << unos(niz, var) << " puta sadrzane." << endl;







	system("PAUSE");
	return 0;
}