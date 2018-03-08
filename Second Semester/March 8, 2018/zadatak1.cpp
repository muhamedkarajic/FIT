/*Decimalni broj pomocu rekurzije pretvoriti u binaran.*/

#include <iostream>
using namespace std;

int binarnaRekurzija(int broj)
{
	if (broj < 1)
		return 0;
	return broj%2+10*binarnaRekurzija(broj / 2);
}

int binarno(int broj)
{
	int bin = 0, ostatak, stepen = 1;
	while (broj>0)
	{
		ostatak = broj % 2;
		bin = bin + ostatak * stepen;
		stepen = stepen = stepen * 10;
		broj = broj / 2;
	}
}

int main()
{
	cout << binarnaRekurzija(7) << endl;

	system("PAUSE");
	return 0;
}