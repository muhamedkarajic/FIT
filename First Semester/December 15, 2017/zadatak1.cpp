/*
Zadatak 1: 
Dat je cjelobrojni niz od 8 elemenata. Napišite program koji će omogućiti korisniku da unese vrijednosti članova niza, 
te provjeriti i ispisati koliko je članova niza veće od 10. Kreirajte zasebne funkcije za unos elemenata niza, 
za ispis elemenata niza i za provjeru koliko je elemenata niza veće od zadane vrijednosti.
*/
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

void naslov(string poruka)
{
	cout << ">>> " << poruka << " <<<" << endl;

}

void razmak()
{
	//cout << endl << "- - - - - - - - - - -" << endl;
	cout << endl;

}

void unos(int niz[], int var)
{
	naslov("UNOS");
	for (int i = 0; i < var; i++)
	{
		cout << "niz[" << i << "] = ";
		cin >> niz[i];
	}
	razmak();
}

void ispis(int niz[], int var)
{
	naslov("ISPIS");
	for (int i = 0; i < var; i++)
	{
		cout << "niz[" << i << "] = " << niz[i] << endl;
	}
	razmak();
}

int provjeri(int niz[], int var)
{
	int brojac = 0;
	for (int i = 0; i < var; i++)
	{
		if (niz[i] > 10)
		{
			brojac += 1;
			cout << "niz[" << i << "] = " << niz[i] << endl;
		}
	}
	return brojac;
}

int main()
{
	const int var = 8;
	int niz[var];
	unos(niz, var);
	ispis(niz, var);

	naslov("Brojevi veci od deset su: ");
	int provjera = provjeri(niz, var);
	cout << "UKUPNO: " << provjera << endl;


	system("PAUSE>0");
	return 0;
}