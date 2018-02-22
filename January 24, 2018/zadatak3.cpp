/*
Napisati program koji će omogućiti:
•	Unos 2D niza od 10x10 elemanata vodeći računa da su svi elementi dvocifreni 
(ukoliko unos nekog elementa ne zadovoljava uslov, ponavljati unos tog elementa dok se ne zadovolji uslov) 
– Koristiti funkciju unos
•	Izvršiti transpoziciju niza tako što će se zamjeniti redovi i kolone 
– Koristiti funkciju transpose, a zatim na osnovu izmijenjenog 2D niza:
•	Izračunati aritmetičku sredinu svih prostih brojeva ispod sporedne dijagonale 
– Koristiti dvije funkcije: aritmeticka i prost_broj (pozivati će se iz funkcije aritmeticka)
•	Napisati funkciju simpatican koja će provjeriti da li su brojevi iznad sporedne dijagonale simpatični*.
Obavezno koristiti navedene funkcije, a parametre i eventualne povratne vrijednosti definisati prema potrebi. 

U main() funkciji napisati testni program koji će omogućiti izvršenje svih funkcija navedenim redoslijedom.
*/


#include <iostream>
using namespace std;

const int var = 3;

void unos(int niz[][var])
{
	for (int i = 0; i < var; i++)
	{
		for (int j = 0; j < var; j++)
		{
			cout << "niz[" << i << "][" << j << "] = ";
			cin >> niz[i][j];
			if (niz[i][j] < 10 || niz[i][j] > 99)
			{
				system("CLS");
				cout << "OBAVEZNO DVOCIFREN!" << endl;
				--j;
			}
		}
		cout << endl;
	}
	system("CLS");
}

void transponovana(int niz[][var])
{
	int pomocna;
	for (int i = 0; i < var; i++)
	{
		for (int j = 0; i != j; j++)
		{
			pomocna = niz[i][j];
			niz[i][j] = niz[j][i];
			niz[j][i] = pomocna;
		}
	}
}


void ispis(int niz[][var])
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

bool prost(int n)
{
	if (n == 2 || n == 3 || n == 5 || n == 7)
		return true;

	else if (n % 2 == 0 || n % 3 == 0 || n % 5 == 0 || n % 7 == 0)
	{
		return false;
	}
	int duzina = sqrt(n);
	for (int i = 5; i <= duzina; i+=6)
	{
		if (n%i==0)
		{
			return false;
		}
	}
	return true;
}

double aritmeticka(int niz[][var])
{
	int uslov = var - 1;
	int suma=0, brojac=0;
	for (int i = 0; i < var; i++)
	{
		for (int j = 0; j < var; j++)
		{
			if (i+j > uslov && prost(niz[i][j]) == true)
			{
				suma += niz[i][j];
				brojac++;
				cout << niz[i][j] << endl;
			}
		}
	}
	if (brojac!=0)
	{
		return suma / double(brojac);
	}
	else
	{
		return 0;
	}
}

bool simpatican(int n)
{
	int kvadrat = n * n;
	int nZbir;
	int kvadratZbir = 0;
	while (kvadrat > 0)
	{
		kvadratZbir = kvadrat % 10;
		kvadrat /= 10;
	}
	
	while (n > 0)
	{
		nZbir = n % 10;
		n /= 10;
	}

	if (nZbir*2 == kvadratZbir)
		return true;

	return false;
}

void simpaticanTest(int niz[][var])
{
	int uslov = var - 1;
	for (int i = 0; i < var; i++)
	{
		for (int j = 0; j < var; j++)
		{
			if (i + j < uslov && simpatican(niz[i][j]) == true)
				cout << niz[i][j] << endl;
		}
	}
}

int main()
{
	int niz[var][var];

	unos(niz);
	ispis(niz);

	cout << endl;
	
	transponovana(niz);
	ispis(niz);

	cout << "Aritmetricka sredina prostih brojeva ovih je: " << aritmeticka(niz) << endl;;

	simpaticanTest(niz);

	system("PAUSE");
	return 0;
}