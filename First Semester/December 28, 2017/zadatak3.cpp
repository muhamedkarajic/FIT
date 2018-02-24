#include <iostream>
using namespace std;

void ispis(int niz[][4], int var)
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

int aritmetricka(int broj)
{

	int brojac = 0;
	int kopija = broj;


	while (broj > 0)
	{
		brojac++;
		broj /= 10;
	}
	

	if (brojac%2!=0)
	{
		brojac = brojac / 2;
		brojac--;
		while (brojac > 0)
		{
			kopija /= 10;
			brojac--;
		}
		return (kopija % 10+(kopija/10)%10)/2.0+0.5;
	}
	else
	{
		brojac = brojac / 2;
		while (brojac > 0)
		{
			kopija /= 10;
			brojac--;
		}
		return kopija % 10;
	}
	
	

}

void unos(int niz[][4], int var)
{
	for (int i = 0; i < var; i+=2)//red
	{
		for (int j = 0; j < var; j++)//kolona
		{
			do
			{
				cout << "Unesi niz[" << i << "][" << j << "] = ";
				cin >> niz[i][j];
			} while (niz[i][j] < 100);
		}
	}
	
	for (int i = 1; i < var; i += 2)//red
	{
		for (int j = 0; j < var; j++)//kolona
		{
			niz[i][j] = aritmetricka(niz[i - 1][j]);
		}
	}





}


int main()
{
	const int var = 4;
	int niz[var][var];
	int number = 321472;
	number /= 100;
	cout << "number: " << (number % 10 + (number / 10) % 10) / 2.0 + 0.5 << endl;


	unos(niz, var);



	ispis(niz, var);

	system("PAUSE");
	return 0;
}