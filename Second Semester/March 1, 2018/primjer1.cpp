/*
Rekurziji kao i svakoj drugoj funkciji je moguće proslijediti niz vrijednosti, pa je zbog
toga u nastavku prikazan program koji putem rekurzivne funkcije izračunava sumu
vrijednosti svih članova niza.
*/

#include <iostream>
using namespace std;

void ispisNiza(int niz[], int i)
{
	if (i == 0)
		return;
	ispisNiza(niz, --i);
	cout << niz[i] << endl;
}

int sumaNiza(int niz[], int i)
{
	if (i == 0)
		return niz[i];
	else
		return niz[i]+ sumaNiza(niz, i-1);
}

int main()
{
	const int i = 7;
	int niz[i] = { 1,2,3,4,5,6,7 };

	ispisNiza(niz, i);

	cout << "Suma: " << sumaNiza(niz, i-1) << endl;
    
	system("PAUSE");
	return 0;
}