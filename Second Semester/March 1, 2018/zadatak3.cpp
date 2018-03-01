/*
Koristeći rekurziju, napisati program koji od korisnika traži da unese neko
slovo. Nakon unosa, program treba da ispiše sva slova koja se nalaze između unesenog i
Pored oznake slova, program treba da ispiše i njima pripadajući ASCII kod.
Također, potrebno je ispisati odgovarajuću poruku u slučaju da korisnik unese znak koji
ima ASCII vrijednost manju od slova 'A'.
*/

#include <iostream>
using namespace std;

void ispisSlova(char slovo)
{
	if (slovo < 'A')
	{
		cout << "Ovo slovo ima manju vrijednost od slova A program se prekida..." << endl;
		return;
	}
	
	if (slovo == 'A')
		return;
	
	ispisSlova(--slovo);
	cout << slovo << " - " << int(slovo) << endl;
}

int main()
{
	ispisSlova('5');



	system("PAUSE");
	return 0;
}