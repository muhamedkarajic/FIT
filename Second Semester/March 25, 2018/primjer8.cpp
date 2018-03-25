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

void dealokacijaMatrice(int **matrica, const int x)
{
	for (int i = 0; i<x; i++)
		delete[] matrica[i];

	delete[] matrica;
	matrica = NULL;
}

int main()
{
	int red = 5, kolona = 4;
	int **matrica = new int *[red];

	for (size_t i = 0; i < red; i++)
		matrica[i] = new int[kolona];
	
	unos(matrica, red, kolona);
	
	system("CLS");
	ispis(matrica, red, kolona);
	
	dealokacijaMatrice(matrica, red);

	system("PAUSE");
	return 0;
}