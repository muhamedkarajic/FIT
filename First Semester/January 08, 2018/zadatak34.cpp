#include <iostream>
using namespace std;

const int var = 5;

void ispis(int niz[][var])
{
	for (int i = 0; i < var; i++)
	{
		for (int j = 0; j < var; j++)
		{
			cout << niz[i][j] << " ";
		}
		cout << endl;
	}
}

int sredina(int niz[][var])
{
	int suma = 0;
	for (int i = 0; i < var; i++)
	{
		for (int j = 0; j < var; j++)
		{
			if (j == i)
			{
				suma += niz[i][j];
			}
		}
	}
	return suma;
}

void promjena(int niz[][var])
{
	for (int i = 0; i < var; i++)
	{
		for (int j = 0; j < var; j++)
		{
			if (niz[i][j] == 1)
				niz[i][j] == 0;
			else
				niz[i][j] == 1;
		}
	}
}

int main()
{
	int niz[var][var] = { 0,1,1,1,1,
		1,0,1,1,1,
		1,1,0,1,1,
		1,1,1,0,1,
		1,1,1,1,0 };

	ispis(niz);

	cout << "Suma sredine: " << sredina(niz) << endl;

	cout << endl;

	promjena(niz);

	ispis(niz);


	system("PAUSE");
	return 0;
}