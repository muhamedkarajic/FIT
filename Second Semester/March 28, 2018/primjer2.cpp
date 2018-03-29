//Napisite program za zbrajanje dviju matrice
#include <iostream>
using namespace std;

//Omoguciit unos vrijednosti elemata matrice sa tastature
void unosMatrice(int **matrica, const int x)
{
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < x; j++)
		{
			cout << "[" << i << "][" << j << "] = ";
			cin >> matrica[i][j];
		}
		cout << endl;
	}
}

void ispisMatrice(int **matrica, const int x)
{
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < x; j++)
		{
			cout << matrica[i][j] << " ";
		}
		cout << endl;
	}
}

//Kreirati trecu matricu ciji ce elementi biti suma elemenata matrice A i B
void sumaMatrica(int **matricaA, int **matricaB, int **matricaC, const int x)
{
	for (int i = 0; i < x; i++)
		for (int j = 0; j < x; j++)
			matricaC[i][j] = matricaA[i][j] + matricaB[i][j];
}

//Dealokacija
void dealocirajMatricu(int **&matrica, int x)
{
	for (int i = 0; i < x; i++)
		delete[]matrica[i];
	delete[] matrica;
	matrica = nullptr;
}

int main()
{
	//Omoguciit unos zeljene velicine matrica (broj redova i kolona istih dimenzija)
	int x;
	cout << "velicina kvadratne matrice x = ";
	cin >> x;

	//Matrice
	int **MatricaA = new int*[x];
	int **MatricaB = new int*[x];
	int **MatricaC = new int*[x];

	for (int i = 0; i < x; i++)
	{
		MatricaA[i] = new int[x];
		MatricaB[i] = new int[x];
		MatricaC[i] = new int[x];
	}
	unosMatrice(MatricaA, x);
	unosMatrice(MatricaB, x);
	system("CLS");
	sumaMatrica(MatricaA, MatricaB, MatricaC, x);
	
	cout << "MatricaA: " << endl;
	ispisMatrice(MatricaA, x);

	cout << "MatricaB: " << endl;
	ispisMatrice(MatricaB, x);

	cout << "MatricaC: " << endl;
	ispisMatrice(MatricaC, x);

	dealocirajMatricu(MatricaA, x);
	dealocirajMatricu(MatricaB, x);
	dealocirajMatricu(MatricaC, x);

	system("PAUSE");
	return 0;
}