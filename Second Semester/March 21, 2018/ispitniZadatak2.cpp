#include <iostream>
using namespace std;

//sve znamenke koje su vece od broja 5 i koje su parne...
int RekSumiraj(int broj, int &brojac)
{
	if (broj == 0)
		return 0;

	int ostatak = broj % 10;
	if (ostatak > 5 && ostatak % 2 == 0)
	{
		brojac++;
		return ostatak + RekSumiraj(broj / 10, brojac);

	}
	return RekSumiraj(broj/10, brojac);
}

int(*GetPokazivac())(int, int&)
{
	return RekSumiraj;
}

int main()
{
	int unos, brojac = 0;

	int(*pok)(int, int&) = GetPokazivac();

	cout << "Unesite neki pozitivan cijeli broj: ";
	cin >> unos;

	cout << "Suma iznosi: " << pok(unos, brojac) << endl;
	cout << "Brojac: " << brojac << endl;
	system("PAUSE");
	return 0;
}