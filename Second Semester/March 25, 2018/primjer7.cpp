#include <iostream>
using namespace std;

void unos(int **matrica, const int x, const int y)
{
	for (size_t i = 0; i < x; i++)
		for (size_t j = 0; j < y; j++)
		{
			cout << "matrica[" << i << "][" << j << "] = ";
			cin >> matrica[i][j];
		}
}

void ispis(	int **matrica, const int x, const int y)
{
	for (size_t i = 0; i < x; i++)
	{
		for (size_t j = 0; j < y; j++)
		{
			cout << matrica[i][j] << " ";
		}
		cout << endl;
	}
}

void zamjeni(int **matrica, const int x, const int y)
{
	for (size_t i = 0; i < x; i++)
		for (size_t j = 0; j < y; j++)
			matrica[i][j] *= 2;
}

void dealokacijaMatrice(int **matrica, const int x)
{
	for (int i = 0; i<x; i++)
		delete[] matrica[i];

	delete[] matrica;
}

int main()
{
	//Kreirati matricu od onoliko cjelobrojnih elemenata koliko zeli koristnik
	int x;
	int y;

	cout << "Unesi x = ";
	cin >> x;

	cout << "Unesi y = ";
	cin >> y;

	int **matrica = new int *[x];
	for (size_t i = 0; i < x; i++)
		matrica[i] = new int[y];

	//Omoguciti inicijalizaciju clanova niza unosom sa tastature
	unos(matrica, x, y);
	system("CLS");

	//Ispisati elemente niza
	ispis(matrica, x, y);

	cout << "Pritisni tipku da bi se ispisale duple vrijednosti." << endl;
	system("PAUSE>0");
	//Zamjeniti vrijednosti niza dvostruko vecim
	zamjeni(matrica, x, y);
	system("CLS");

	//Ispisati izmjenene elemente matrice
	ispis(matrica, x, y);

	//dealokacija
	dealokacijaMatrice(matrica, x);

	system("PAUSE");
	return 0;
}