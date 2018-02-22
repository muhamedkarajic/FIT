#include <iostream>
using namespace std;

const int var = 7;

void unos(char niz[])
{
	cout << "NAPOMENA SAMO MALA SLOVA!" << endl;
	for (int i = 0; i < var; i++)
		do
		{
			cout << "niz[" << i << "] = ";
			cin >> niz[i];
		} while (niz[i] < 97 || niz[i] > 122);
	system("CLS");
}

void ispis(char niz[])
{
	for (int i = 0; i < var; i++)
		cout << niz[i] << " ";
	cout << endl;
}

char posljedni(char niz[])
{
	int max = niz[0];
	
	for (int i = 1; i < var; i++)
		if (max < niz[i])
			max = niz[i];

	cout << endl;
	return max;
}

void VelikiVokali(char niz[])
{
	for (int i = 0; i < var; i++)
		if (niz[i] == 'a' || niz[i] == 'e' || niz[i] == 'i' || niz[i] == 'o' || niz[i] == 'u')
			niz[i] -= 32;
}

void zamjeni(char niz[])
{
	for (int i = 0; i < var; i++)
		if (niz[i] == 'k')
			niz[i] = 'z';
}

int main()
{
	char niz[var];
	unos(niz);
	ispis(niz);
	VelikiVokali(niz);
	zamjeni(niz);
	ispis(niz);

	system("PAUSE");
	return 0;
}