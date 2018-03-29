#include <iostream>

using namespace std;

void unos(int **matrica, int x)
{
	for (size_t i = 0; i < x; i++)
	{
		for (size_t j = 0; j < x; j++)
		{
			cout << "[" << i << "][" << j << "] = ";
			cin >> matrica[i][j];
		}
	}
}

void ispis(int **matrica, int x)
{
	for (size_t i = 0; i < x; i++)
	{
		for (size_t j = 0; j < x; j++)
		{
			cout << matrica[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}
void zbirMatrica(int **matricaA, int **matricaB, int **matricaC, int x)
{
	for (size_t i = 0; i < x; i++)
		for (size_t j = 0; j < x; j++)
			matricaC[i][j] = matricaA[i][j] + matricaB[i][j];
}

void dealokacijaMatrice(int **&matrica, int x)
{
	for (size_t i = 0; i < x; i++)
	{
		delete[] matrica[i];
		matrica[i] = nullptr;
	}
		
	delete[] matrica;
	matrica = nullptr;
}


int main()
{
	int x;
	cout << "kvadratna matrica[][] x = ";
	cin >> x;

	int **A = new int*[x];
	int **B = new int*[x];
	int **C = new int*[x];
	
	for (size_t i = 0; i < x; i++)
	{
		B[i] = new int[x];
		C[i] = new int[x];
		A[i] = new int[x];
	}

	cout << "Unos A: " << endl;
	unos(A, x);

	cout << "Unos B: " << endl;
	unos(B, x);

	zbirMatrica(A, B, C, x);

	system("CLS");

	cout << "Ispis A: " << endl;
	ispis(A, x);

	cout << "Ispis B: " << endl;
	ispis(B, x);
	
	cout << "Ispis C: " << endl;
	ispis(C, x);


	//dealokacija
	dealokacijaMatrice(A, x);
	dealokacijaMatrice(B, x);
	dealokacijaMatrice(C, x);

	system("PAUSE");
	return 0;
}