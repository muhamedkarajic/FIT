#include <iostream>
using namespace std;

/*
Zadatak1: Napišite program koji će računati sumu članova niza kojeg sačinjava 8 
cijelobrojnih vrijednosti koji unosi korisnik preko tastature.


- pseudo referenca

Elementi niza imaju iste osobine koje su iste:
-tip,
-ime,
-iste operacije se vrše nad podacima,
*/

int sumaNiza(int niz[], int var)
{
	int suma = 0;

	for (int i = 0; i < var; i++)
	{
		cout << "niza[" << i << "] = ";
		cin >> niz[i];
		suma += niz[i];
	}

	return suma;
}

int main()
{
	const int var = 8;
	int niz[var];

	cout << sumaNiza(niz, var) << endl;

	system("PAUSE");
	return 0;
}