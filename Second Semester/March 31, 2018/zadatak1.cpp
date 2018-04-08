/*
Napišite program u kojem ćete:

U funkciji main deklarirati dvodimenzionalni niz u dinamičkoj memoriji. 
Omogućiti korisniku da unese dimenzije niza.

Dodijelite vrijednosti svakom neparnom elementu (1,3,5,7, …) 
uz pomoć funkcije random(), a svakom parnom elementu u nizu (2,4,6, …) 
dodijelite upola manju vrijednost u odnosu na prethodni element 
(dakle, 2. element treba imati upola manju vrijednost od 1. elementa). 

Ispišite vrijednosti elemenata niza. 
Ne zaboravite dealocirati memoriju.
*/

#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

void random(int *niz, int n)
{
	int randomNumber;
	srand(time(NULL));
	for (int i = 0; i < n; i += 2)
	{
		randomNumber = rand() % 100 + 1;

		niz[i] = randomNumber;
		niz[i + 1] = randomNumber / 2;

		if (niz[i] % 2 == 0)
			niz[i] += 1;

		if (niz[i + 1] % 2 != 0)
			niz[i + 1] += 1;
	}
}

void ispis(int *niz, int n)
{
	for (int i = 0; i < n; i++)
		cout << niz[i] << " ";
	cout << endl;
}

void dealokacija(int *&niz, int n)
{
	delete[] niz;
	niz = nullptr;
}

int main()
{

	int n;
	cout << "n = ";
	cin >> n;
	cin.ignore();

	int *niz = new int[n];

	random(niz, n);
	ispis(niz, n);
	dealokacija(niz, n);

	system("PAUSE");
	return 0;
}