#include <iostream>
using namespace std;

/*
Zadatak2: Napišite program koji će računati sumu članova niza s neparnim indeksom. 
Niz sačinjava 7 cijelobrojnih vrijednosti koje se unose s tastature.
*/

void unosNiza(int niz[], int var)
{
	for (int i = 0; i < var; i++)
	{
		cout << "niz[" << i << "] = ";
		cin >> niz[i];
	}
}

int sumaNeparnogNiza(int niz[], int var)
{
	int suma = 0;


	for (int i = 1; i < var; i+=2)
	{
		suma += niz[i];
	}
	
	return suma;
}

int main()
{
	const int var = 7;
	int niz[var];

	unosNiza(niz, var);

	cout << "Suma na neparnim pozicijama: " << sumaNeparnogNiza(niz, var) << endl;

	system("PAUSE");
	return 0;
}