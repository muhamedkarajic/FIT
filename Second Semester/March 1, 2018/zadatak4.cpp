/*
Napraviti program koji korisniku omogućava da unese neki broj. 
Nakon unosa, program treba da, koristeći rekurzivnu funkciju, izračuna sumu svih parnih
brojeva koji se nalaze između unesenog i broja 100. Prilikom izrade programa voditi
računa o tome da korisnik može unijeti broj koji je veći ili manji od broja 100.47
*/

#include <iostream>
using namespace std;

void ispisParnih(int broj)
{
	if (broj % 2 != 0)
		++broj;
	if (broj > 100)
		return;
	cout << broj << endl;
	ispisParnih(broj + 2);
}

int sumaParnih(int broj)
{
	if (broj % 2 != 0)
		++broj;
	if (broj > 100)
		return 0;
	return broj + sumaParnih(broj + 2);
}

int main()
{
	int broj;
	cout << "Unesi broj: ";
	cin >> broj;

	ispisParnih(broj);

	cout << "Suma je: " << sumaParnih(broj) << endl;
	system("PAUSE");
	return 0;
}