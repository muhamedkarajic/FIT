/*
Koristeći rekurziju, napisati program koji od korisnika traži da unese broj čija
vrijednost mora biti u opsegu od 1 do 10. Unesenu vrijednost predati funkciji koja treba
da se izvršava onoliko puta kolika je vrijednost predanog argumenta (ako korisnik unese
broj 5, funkcija treba da 5 puta pozove sama sebe). Pri svakom pozivu funkcija treba da
ispiše trenutnu vrijednost predanog argumenta.
*/

#include <iostream>
using namespace std;

void rekurzija(int broj)
{
	if (broj == 0)
		return;
	cout << broj-- << endl;
	rekurzija(broj);
}


int main()
{
	int broj;
	cout << "Unesi neki broj: ";
	cin >> broj;

	rekurzija(broj);


	system("PAUSE");
	return 0;
}