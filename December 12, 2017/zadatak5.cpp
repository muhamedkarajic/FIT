#include <iostream>
#include <string>
using namespace std;

/*
Napišite program koji će:
-omogućiti unos niza 7 realinih brojeva pomocu funkcije: void unos(float[], int);

Uraditi nakon toga sljedeće:
- izračunati sumu kubova svih elemenata s neparnim indeksima uz pomoć funkcije float sumaKubova(float[], int);
- pronaci najmanji pozitivni broj u nizu uz pomoć funkcije float najmanjiPoz(float[], int);
- pronai najveći negativni broj u nizu uz pomoć funkcije float najveciNeg(float[], int);

*/


void poruka(string naslov)
{
	cout << "\n> > > > >" << "\t" << naslov << "\t" << "< < < < <\n" << endl;
}

void unos(float niz[], int var)
{
	for (int i = 0; i < var; i++)
	{
		cout << "niz[" << i << "] = ";
		cin >> niz[i];
	}
}

float sumaKubova(float niz[], int var)
{
	float suma = 1.0;
	for (int i = 0; i < var; i++)
	{
		cout << "niz[" << "] = " << niz[i] << " na trecu iznosi: " << niz[i] * niz[i] * niz[i] << endl;
		suma += niz[i] * niz[i] * niz[i];
	}
	return suma;
}

float najmanjiPoz(float niz[], int var)
{
	float najmanji = FLT_MAX;
	for (int i = 1; i < var; i++)
	{
		if (niz[i] > 0 && niz[i] < najmanji)
		{
			najmanji = niz[i];
		}
	}

	
	return najmanji;
}


int main()
{
	const int var = 7;
	float niz[var];
	
	poruka("UNOS");
	unos(niz, var);



	poruka("NAJMANJI POZITIVNI BROJ:");
	if (!(najmanjiPoz(niz, var) > 0))
	{
		cout << "Nema niza manjeg od nule." << endl;
	}
	else
	{
		cout << najmanjiPoz(niz, var) << endl;
	}
	




	system("PAUSE>0");
	return 0;
}