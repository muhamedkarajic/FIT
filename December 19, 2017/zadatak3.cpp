#include <iostream>
using namespace std;
//Kopiraj svaki element jedne matrice (4x3) u drugu matricu (2x3);

int const kolona = 3, red = 4, red2 = 2;

void unos(int niz[][kolona])
{
	for (int i = 0; i < red; i++)
	{
		for (int j = 0; j < kolona; j++)
		{
			cout << "niz[" << i << "][" << j << "] = ";
			cin >> niz[i][j];
			if (niz[i][j]<1)
			{
				j--;
			}
		}
	}
}

void ispis1(int niz[][kolona])
{
	for (int i = 0; i < red; i++)
	{
		for (int j = 0; j < kolona; j++)
		{

			cout << niz[i][j] << " ";
		}
		cout << endl;
	}
}

void ispis2(int niz[][kolona])
{
	for (int i = 0; i < red2; i++)
	{
		for (int j = 0; j < kolona; j++)
		{
			cout << "niz[" << i << "][" << j << "] = " << niz[i][j] << " ";
		}
		cout << endl;
	}
}

int main()
{
	int matrica1[red][kolona] = {1,2,3,4,5,6,7,8,9,10,11,12};
	int matrica2[red2][kolona];

	ispis1(matrica1);

	int z = 0;
	int g = 0;
	for (int i = 0; i < red; i++)
	{
		for (int j = 0; j < kolona; j++)
		{
			if (!((i + j) % 2 == 0))
			{
				if (i*j>red*kolona/red2)
				{
					z = 0;
					g++;
				}
				matrica2[g][z] = matrica1[i][j];
				
				z++;
			}
		}
	}

	ispis2(matrica2);
	
	system("PAUSE");
	return 0;
}