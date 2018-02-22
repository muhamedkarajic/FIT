#include <iostream>
#include <iomanip>
using namespace std;


const int var = 3;

void nastavakPrograma()
{
	cout << endl;
	//cout << "Pritisni tipku za nastavak programa." << endl;
	//system("CLS");
}

void unos(int niz[][var])
{
	cout << "UNOS:" << endl;
	system("color 7");
	for (int i = 0; i < var; i++)
	{
		for (int j = 0; j < var; j++)
		{
			cout << "niz[" << i << "][" << j << "] = ";
			cin >> niz[i][j];
		}
	}
	nastavakPrograma();
}
void ispis(int niz[][var])
{
	cout << "ISPIS:" << endl;
	system("color F");
	for (int i = 0; i < var; i++)
	{
		for (int j = 0; j < var; j++)
		{
			cout << setw(5) << niz[i][j] << " ";
		}
		cout << endl;
	}
	nastavakPrograma();
}

int suma(int niz[][var])
{
	int suma = 0;
	system("color F");
	for (int i = 0; i < var; i++)
	{
		for (int j = 0; j < var; j++)
		{
			suma += niz[i][j];
		}
	}
	nastavakPrograma();
	return suma;
}

int sumaGlavnaDijagonala(int niz[][var])
{
	int suma = 0;
	system("color 8");
	for (int i = 0; i < var; i++)
	{
		for (int j = 0; j < var; j++)
		{
			if (i==j)
			{
				suma += niz[i][j];
			}
		}
	}
	nastavakPrograma();
	return suma;
}

int sumaSporedneDijagonala(int niz[][var])
{
	int suma = 0;
	system("color F");
	for (int i = 0; i < var; i++)
	{
		for (int j = 0; j < var; j++)
		{
			if (j == var-1-i)
			{
				suma += niz[i][j];
			}
		}
	}
	nastavakPrograma();
	return suma;
}

int sumaIspodGlavneDijagonale(int niz[][var])
{
	int suma = 0;
	system("color 8");
	for (int i = 0; i < var; i++)
	{
		for (int j = 0; j < var; j++)
		{
			if (i+j > var - 1)
			{
				suma += niz[i][j];
			}
		}
	}
	nastavakPrograma();
	return suma;
}

int sumaIznadGlavneDijagonale(int niz[][var])
{
	int suma = 0;
	system("color F");
	for (int i = 0; i < var; i++)
	{
		for (int j = 0; j < var; j++)
		{
			if (i + j < var - 1)
			{
				suma += niz[i][j];
			}
		}
	}
	nastavakPrograma();
	return suma;
}

int sumaRedaka(int niz[][var], int i)
{
	int suma = 0;
	system("color F");
	for (int j = 0; j < var; j++)
	{
		suma += niz[i][j];
	}
	nastavakPrograma();
	return suma;
}

int sumaKolone(int niz[][var], int j)
{
	int suma = 0;
	system("color F");
	for (int i = 0; i < var; i++)
	{
		suma += niz[i][j];
	}
	nastavakPrograma();
	return suma;
}

int main()
{
	int niz[var][var];

	unos(niz);
	ispis(niz);
	cout << "SUMA:" << suma(niz) << endl;
	cout << "Suma glavne dijagonale: " << sumaGlavnaDijagonala(niz) << endl;
	cout << "Suma sporedne dijagonale: " << sumaSporedneDijagonala(niz) << endl;
	cout << "Suma ispod glavne dijagonale: " << sumaIspodGlavneDijagonale(niz) << endl;
	cout << "Suma iznad glavne dijagonale: " << sumaIznadGlavneDijagonale(niz) << endl;
	nastavakPrograma();

	int redak;
	do
	{
		cout << "Unesi redak: ";
		cin >> redak;
	} while (redak<0 || redak>=var);
	cout << "Suma redaka " << redak << ": " << sumaRedaka(niz, redak) << endl;



	int kolona;
	do
	{
		cout << "Unesi kolonu: ";
		cin >> kolona;
	} while (kolona<0 || kolona >= var);
	cout << "Suma kolona " << kolona << ": " << sumaKolone(niz, kolona) << endl;


	system("PAUSE>0");
	return 0;
}