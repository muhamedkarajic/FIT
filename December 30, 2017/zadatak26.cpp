#include <iostream>
using namespace std;

void unos(char niz[], int var)
{
	cout << "Unesi slova engleske abc-de obavezno mala:" << endl;
	for (int i = 0; i < var; i++)
	{
		do
		{
			cout << "niz[" << i << "] = ";
			cin >> niz[i];
		} while (niz[i] < 97 || niz[i] > 122);
	}
}

int vokali(char niz[], int var)
{
	int brojac = 0;
	for (int i = 0; i < var; i++)
	{
		if (niz[i] == 'a' || niz[i] == 'e' || niz[i] == 'i' || niz[i] == 'o' || niz[i] == 'u')
		{
			brojac++;
		}
	}
	return brojac;
}

void velika(char niz[], int var)
{
	for (int i = 0; i < niz[i]; i++)
	{
		niz[i] = int(niz[i]) - 32;
	}
}

void ispis(char niz[], int var)
{
	for (int i = 0; i < var; i++)
	{
		cout << niz[i] << " ";
	}
	cout << endl;
}

int main()
{
	const int var = 7;
	char niz[var];
	unos(niz, var);
	cout << "Ukupno vokala ima: " << vokali(niz, var) << endl;
	velika(niz, var);
	ispis(niz, var);

	system("PAUSE");
	return 0;
}