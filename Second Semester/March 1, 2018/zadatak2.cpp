/*
Koristeći rekurziju, napisati program koji korisniku omogućava da unese
željeni tekst. Uslov za završetak programa je da uneseni tekst sadrži najmanje jednu
tačku (.). Nakon unosa, program treba obrnutim redoslijedom ispisati sve znakove koji
su uneseni do prvog znaka tačke.
*/

#include <iostream>
using namespace std;

void prikaziUnazad()
{
	char text;
	cin >> text;
	if (text == '.')
		return;
	prikaziUnazad();
	cout << text;
}

int main()
{
	prikaziUnazad();

	system("PAUSE");
	return 0;
}