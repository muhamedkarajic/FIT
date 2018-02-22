#include <iostream>
#include <cmath>
using namespace std;

void ispis(int niz[], int var)
{
	for (int i = 0; i < var; i++)
	{
		cout << niz[i] << " ";
	}
}

void sortiraj(int niz[], int var)
{

	bool flag = false;
	int duzina = var - 1;
	while (flag != true)
	{
		flag = true;
		for (int i = 0; i < duzina; i++)
		{
			if (niz[i+1]>niz[i])
			{
				int temp = niz[i + 1];
				niz[i + 1] = niz[i];
				niz[i] = temp;
				flag = false;
			}
		}
	}







}

float medijan(int niz[],int var)
{
	if (var % 2 == 0)
		return (niz[var / 2] + niz[var / 2 - 1]) / 2.0;
	else
		return niz[var / 2];
}


int main()
{
	const int var = 4;
	int niz[var];
	int brojac = 0;

	
	for (int i = 100; i <= 999; i++)
	{
		if (pow(i % 10, 3) + pow(i /10%10, 3) + pow(i/100%10, 3) == i)
		{
			cout << i << endl;
			niz[brojac++] = i;
		}
	}

	ispis(niz, var);
	cout << endl;
	sortiraj(niz, var);
	cout << endl;
	ispis(niz, var);

	cout << "Aritmetricka sredina, odnosno medijan iznosi:" << medijan(niz, var) << endl;
	system("PAUSE");
	return 0;
}