/*
Napisati program koji će omogućiti:
•	Unos 2D niza od 10x10 elemanata vodeći računa da su svi elementi dvocifreni (ukoliko unos nekog elementa ne zadovoljava uslov, ponavljati unos tog elementa dok se ne zadovolji uslov) – Koristiti funkciju unos
•	Izvršiti transpoziciju niza tako što će se zamjeniti redovi i kolone – Koristiti funkciju transpose, a zatim na osnovu izmijenjenog 2D niza:
	•	Izračunati aritmetičku sredinu svih prostih brojeva ispod sporedne dijagonale – Koristiti dvije funkcije: aritmeticka i prost_broj (pozivati će se iz funkcije aritmeticka)
	•	Napisati funkciju simpatican koja će provjeriti da li su brojevi iznad sporedne dijagonale simpatični*.
*/

#include <iostream>
using namespace std;


const int var = 5;

void unos(int niz[][var])
{
	for (int i = 0; i < var; i++)
	{
		for (int j = 0; j < var; j++)
		{
			cout << "Unesi niz[" << i << "][" << j << "] = ";
			cin >> niz[i][j];

			if (niz[i][j] < 10 || niz[i][j] > 99)
				j--;
		}
	}
}

void ispis(int niz[][var])
{
	for (int i = 0; i < var; i++)
	{
		for (int j = 0; j < var; j++)
		{
			cout << niz[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void transpose(int niz[][var])
{
	int temp;
	int brojac = 0;
	for (int i = 0; i<var; i++) {
		for (int j = 0; i!=j; j++) {
				temp = niz[i][j];
				niz[i][j] = niz[j][i];
				niz[j][i] = temp;
				brojac++;
		}
	}
	cout << "Brojac: " << brojac << endl;
}

int main()
{
	int niz[var][var] = {
							10,11,12,13,14,
							20,21,22,23,24,
							30,31,32,33,34,
							40,41,42,43,44,
							50,51,52,53,54
						};
	
	ispis(niz);
	transpose(niz);
	cout << endl;
	ispis(niz);

	system("PAUSE");
	return 0;
}