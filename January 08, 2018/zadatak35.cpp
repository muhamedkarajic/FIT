#include <iostream>
using namespace std;

const int var = 7;

void unos(char niz[var])
{
	for (int i = 0; i < var; i++)
	{
		do
		{
			cout << "niz[" << i << "] = ";
			cin >> niz[i];
		} while (niz[i] < 97 || niz[i] > 122);
	}
}

void ispis(char niz[var])
{
	for (int i = 0; i < var; i++)
	{
		cout << niz[i] << " ";
	}
	cout << endl;
}


char posljednje(char niz[var])
{
	char max = niz[0];
	for (int i = 1; i < var; i++)
		if (niz[i] > max)
			max = niz[i];
	return max;
}

void velikiVokali(char niz[var])
{
	for (int i = 0; i < var; i++)
		if (niz[i] == 'a' || niz[i] == 'e' || niz[i] == 'i' || niz[i] == 'o' || niz[i] == 'u')
			niz[i] = niz[i] - 32;
}

void zamjeni(char niz[var])
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
	
	cout << "Posljednji karakter je: " << posljednje(niz) << endl;

	velikiVokali(niz);
	ispis(niz);

	zamjeni(niz);
	ispis(niz);

	system("PAUSE");
	return 0;
}