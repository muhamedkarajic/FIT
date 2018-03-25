#include <iostream>
using namespace std;

void unos(int **matrica, int red, int kolona)
{
	for (size_t i = 0; i < red; i++)
	{
		for (size_t j = 0; j < kolona; j++)
		{
			cout << "[" << i << "][" << j << "] = ";
			cin >> matrica[i][j];
		}
	}
	system("CLS");
}

void ispis(int **matrica, int red, int kolona)
{
	for (size_t i = 0; i < red; i++)
	{
		for (size_t j = 0; j < kolona; j++)
		{
			cout << matrica[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void ispisZbir(int **matrica, int **drugaMatrica, int red, int kolona)
{
	for (size_t i = 0; i < red; i++)
	{
		for (size_t j = 0; j < kolona; j++)
		{
			cout << matrica[i][j] + drugaMatrica[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void dealokacijaMatrice(int **matrica, int red)
{
	for (size_t i = 0; i < red; i++)
		delete matrica[i];

	delete[] matrica;
	matrica = NULL;
}

int main()
{
	//Napisite program u kojem cete deklarisati 2 dinamicka dvodimenzionalna niza, 
	//o velicini matrice odlucuje korisnik,
	//kreirati funkcije za: unos, ispis, sumu elemenata matrice

	int red = 5, kolona = 2;
	
	int **matrica = new int *[red];
	int **drugaMatrica = new int *[red];

	for (size_t i = 0; i < red; i++)
	{
		matrica[i] = new int[kolona];
		drugaMatrica[i] = new int[kolona];
	}

	cout << "Unos matrice: " << endl;
	unos(matrica, red, kolona);
	cout << "Unos druge matrice: " << endl;
	unos(drugaMatrica, red, kolona);

	cout << "Ispis matrice: " << endl;
	ispis(matrica, red, kolona);

	cout << "Ispis druge matrice: " << endl;
	ispis(drugaMatrica, red, kolona);

	cout << "Ispis zbira matrica: " << endl;
	ispisZbir(matrica, drugaMatrica, red, kolona);

	//dealokacija
	dealokacijaMatrice(matrica, red);
	dealokacijaMatrice(drugaMatrica, red);
    
	system("PAUSE");
	return 0;
}