#include <iostream>
#include <iomanip>
using namespace std;

/*
Napisite program koji ce omoguciti kreiranje matrice 4x4. Uz pomoc funkcije:
void unos(int[][4]); omoguciti unos samo parnih elemenata u matricu;
void zamijeniR(int[][4], int , int); zamjena mjesta izabanim retcima, izbor redaka vrsi korisnik
void zamjeniRiK(int[][4], int, int); zamjeniti mjesta izabranom retku i koloni; izbor retka i kolone vrsi korisnik;
void ispis(int[][4]); ispisite elemente matrice.
*/


const int var = 4;

void unos(int niz[][var])
{
	for (int i = 0; i < var; i++)
		for (int j = 0; j < var; j++)
		{
			cout << "niz[" << i << "] = ";
			cin >> niz[i][j];
			if (niz[i][j] % 2 != 0)
				j--;
		}
}

void zamijeniR(int niz[][var], int redak1, int redak2)
{
	int pomocna;
	for (int j = 0; j < var; j++)
	{
		pomocna = niz[redak1][j];
		niz[redak1][j] = niz[redak2][j];
		niz[redak2][j] = pomocna;
	}
}

void zamjeniRiK(int niz[][var], int red, int kolona)
{
	int pomocna;
	for (int j = 0; j < var; j++)
	{
		pomocna = niz[red][j];
		niz[red][j] = niz[j][kolona];
		niz[j][kolona] = pomocna;
	}
}


void ispis(int niz[][var])
{
	for (int i = 0; i < var; i++)
	{
		for (int j = 0; j < var; j++)
		{
			cout << setw(5) <<  niz[i][j] << " ";
		}
		cout << endl;
	}
}

int main()
{
	int niz[var][var];
	unos(niz);
	int redak1, redak2;

	system("CLS");
	
	ispis(niz);

	cout << "Unesi redak1, redak2: " << endl;
	do
	{
		cin >> redak1;
		cin >> redak2;
	} while (redak1 < 0 || redak1 > 3 || redak2 < 0 || redak2 > 3);

	cout << " = = = = = = = = = = = = = = = = " << endl;
	zamijeniR(niz,redak1,redak2);
	ispis(niz);


	
	cout << " - - - - - - - - - - - - - - - - - - - " << endl;
	zamjeniRiK(niz, redak1, redak2);

	ispis(niz);


	system("PAUSE");
	return 0;
}