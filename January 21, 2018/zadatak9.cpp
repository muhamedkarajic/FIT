/*
Napisati funkciju koja kao parametare prima dva niza char recenica[200] i char rijec[10] odnosno rečenicu 
(niz od najviše 200 karaktera) i riječ (niz od najviše 10 karaktera) te u nizu recenica[200] pretrazuje i 
pronalazi sekvencu karaktera unesenih u niz rijec[10]. Radi jednostavnosti rjesenja podrazumjeva se da i 
recenica i rijec koja se pretrazuje zavrsavaju tackom.

Poslije pronalaska trazene rijeci, pomenutu rijec treba zamijeniti karakterima 
„FIT“ (Pomoc: Treba voditi racuna koliko karaktera ima rijec koja je pronadjena i zamjenjena)

Npr. ako je data rečenica u nizu recenica[200]:
"Ja studiram na fakultetu jer zelim biti expert."
i rijec[10]:
„fakultet“,
funkcija je treba pronaci rijec „fakultet“ u recenici i pretvoriti je u „FIT“:
" Ja studiram na FITu jer zelim biti expert." (ima ukupno manje slova a zadrzan je samo po jedan space izmedju rijeci)
Obavezno u main funkciji omoguciti unos recenice, zatim trazene rijeci i ispisati novu recenicu poslije zamjene.
*/

#include <iostream>
using namespace std;

bool testRijeci(char recenica[], char rijec[], int position)
{
	for (int i = 0; rijec[i+1]!='.'; i++)
	{
		if (recenica[i+ position] != rijec[i])
			return false;
		
	}
	return true;
}

void promjeni(char recenica[], char rijec[], int pozicija)
{
	const int var = 4;
	char drugo[var] = "FIT";

	for (int i = 0; rijec[i] != '.'; i++)
	{
		if ((recenica[i + pozicija] == rijec[i]) && i<3)
			recenica[i+pozicija] = drugo[i];
		else
			recenica[i+pozicija] = '-';

	}
}

void ispis(char recenica[])
{
	for (int i = 0; recenica[i] != '.'; i++)
	{
		if (recenica[i] != '-')
			cout << recenica[i];
	}
	cout << "." << endl;
}

void ispis2(char recenica[])
{
	for (int i = 0; recenica[i] != '.'; i++)
	{
		cout << recenica[i];
	}
	cout << "." << endl;
}

void sredi(char recenica[])
{
	int pomocna;
	bool sortirano = false;
	while (sortirano != true)
	{
		sortirano = true;
		for (int i = 0; recenica[i-1] != '.'; i++)
		{
			if (recenica[i] == '-')
			{
				recenica[i] = recenica[i + 1];
				recenica[i + 1] = '-';
				sortirano = false;
			}
		}
	}
}

void zamjeni(char recenica[], int n, char rijec[], int z)
{
	for (int i = 0; recenica[i+1] != '.'; i++)
	{
		if (recenica[i] == rijec[0])
		{
			if (testRijeci(recenica, rijec, i) == true)
				promjeni(recenica, rijec, i);
		}
	}
}

int main()
{
	char recenica[200] = {"Ja studiram na fakultetu jer zelim biti expert."};
	char rijec[10] = { "fakultet." };

	zamjeni(recenica, 200, rijec, 10);

	ispis(recenica);
	ispis2(recenica);

	sredi(recenica);
	ispis(recenica);
	ispis2(recenica);


	system("PAUSE");
	return 0;
}