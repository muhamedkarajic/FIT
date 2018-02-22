#include <iostream>
#include <cmath>
using namespace std;

int Sifriranje(int broj)
{
	int kopija = broj;
	int brojac = 0;

	while (kopija > 0)
	{
		brojac++;
		kopija /= 10;
	}

	int podjeliti = pow(10, brojac-1);
	cout << "Broj: " << broj << " Podjeliti: " << podjeliti << endl;
	while (broj>0)
	{
		if ((broj / podjeliti) % 2 == 0)
			kopija += 1;

		else
			kopija += broj / podjeliti;
		
		broj %= podjeliti;
		podjeliti /= 10;
		kopija *= 10;
	}
	return kopija/10;
}



int main()
{
	int broj;
	cout << "Unesi neki broj: ";
	cin >> broj;
	cout << broj / 100 << endl;

	cout << "Sifrovani broj: " << Sifriranje(broj) << endl;

	


	system("PAUSE");
	return 0;
}