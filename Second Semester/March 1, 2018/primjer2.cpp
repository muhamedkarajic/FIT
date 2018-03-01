/*
Za kraj ovog materijala, samostalno pokušajte napisati program koji će korištenjem
rekurzije omogućiti konverziju unsenog broja u njegov binarni ekvivalent. Također,
korištenjem bitset-a možemo izvršiti provjeru ispravnosti rada rekurzivne funkcije.
*/

#include <iostream>
using namespace std;

void binarniBroj(int broj)
{
	if (broj <= 1)
	{
		cout << broj;
		return;
	}
	int bit = broj % 2;
	broj /= 2;
	binarniBroj(broj);
	cout << bit;
}

int decimalniBroj(int broj, int bit)
{
	if (broj == 1)
		return bit;
	else
		return (bit * (broj % 10)) + decimalniBroj(broj / 10, bit * 2);
}

int main()
{
	int broj;
	cout << "Unesi neki broj: ";
	cin >> broj;
	binarniBroj(broj);
	cout << endl;

	cout << "Unesi decimal number: ";
	int binaryNumberInput;
	cin >> binaryNumberInput;
	cout << binaryNumberInput << " = " << decimalniBroj(binaryNumberInput, 1) << endl;


	system("PAUSE");
	return 0;
}