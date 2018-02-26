#include <iostream>
using namespace std;

void unos(char niz[], int var)
{
	cout << "UNOS:" << endl;
	for (int i = 0; i < var; i++)
	{
		cout << "niz[" << i << "] = ";
		cin >> niz[i];
	}
}
int slova(char niz[], int var)
{
	int brojac = 0;

	for (int i = 0; i < var; i++)
		if (niz[i] >= 97 && niz[i]<=122 || niz[i] >= 65 && niz[i] <= 90)
			brojac++;

	return brojac;
}

int ostalo(char niz[], int var)
{
	int brojac = 0;

	for (int i = 0; i < var; i++)
		if (!(niz[i] >= 97 && niz[i] <= 122 || niz[i] >= 65 && niz[i] <= 90))
			brojac++;

	return brojac;
}

int main()
{
	const int var = 7;
	char niz[var];

	unos(niz, var);

	cout << "Slova ima ukupno: " << slova(niz, var) << endl;
	cout << "Ostlai znakova ima ukupno: " << ostalo(niz, var) << endl;
	system("PAUSE");
	return 0;
}