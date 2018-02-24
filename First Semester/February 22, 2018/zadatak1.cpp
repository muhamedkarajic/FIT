/*
Napisati program koji omogucava unos karaktera sve dok  se ne popuni niz od 30 elemenata, prema sljedecim pravilima:
-elementi niza mogu samo biti velika slova i brojevi,
-svaki naredni element u nizu treba da bude abcedno poslije prethodnog, odnosno, u slučaju broja, dalje od nule na brojnoj osi
(voditi računa da se međusobno porede samo slova i samo brojevi)
-ukupna suma ASCII kodova ne smije biti veca od 1000
*/
//SUMA JE UVIJEK VECA OD 1000!!!
#include <iostream>
using namespace std;

const int var = 30;

bool unos(char niz[var])
{
	char slovoZadnje = 'A';
	char brojZadnji = '0';
	slovoZadnje--;
	brojZadnji--;

	int suma = 0;

	for (int i = 0; i < var; i++)
	{
		do
		{
			cout << "Unesi niz[" << i << "] = ";
			cin >> niz[i];
		} while ((niz[i] < 65 || niz[i] > 90 || slovoZadnje >= niz[i]) && (niz[i] < 48 || niz[i] > 57 || brojZadnji >= niz[i]));

		if (niz[i] >= 65)
			slovoZadnje = niz[i];
		else
			brojZadnji = niz[i];

		suma += int(niz[i]);
	}
	cout << endl;

	cout << suma << endl;

	if (suma > 1000)
		return true;
	else
		return false;
}

void ispis(char niz[var])
{
	for (int i = 0; i < var; i++)
		cout << niz[i] << " ";

	cout << endl;
}

int main()
{
	char niz[var];
	do
	{
		cout << "UKUPNA SUMA MORA BITI VECA OD 1000" << endl;
	} while (unos(niz) == false);
	ispis(niz);



	system("PAUSE");
	return 0;
}