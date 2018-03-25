/*
Napišite program u kojem ćete:
•	Deklarirati tri varijable (a, b, c) i dodijelite im vrijednosti po izboru korisnika;
•	Deklarirajte niz pokazivača veličine 5 - neka prva tri elementa niza pokazuju na varijable a, b, c
•	Ispišite vrijednosti varijabli a, b, c  koristeći prva tri elementa niza.
*/
#include <iostream>
using namespace std;

void ispis(int **niz)
{
	for (int i = 0; niz[i] != nullptr; i++)
		cout << *niz[i] << endl;
}

int main()
{
	int const vel = 5;
	int a = 5, b = 7, c = 2;

	int *niz[vel] = {};

	niz[0] = &a;
	niz[1] = &b;
	niz[2] = &c;

	ispis(niz);

	system("PAUSE");
	return 0;
}