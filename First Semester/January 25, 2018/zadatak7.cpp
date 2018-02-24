/*
Deklarisati kvadratnu matricu cijelih brojeva proizvoljnih dimenzija, te implementirati sljedeće funkcije:
•	Funkciju za unos i formiranje elemenata matrice prema sljedećem obrascu: 
elemente neparnih redova matrice (1., 3., 5. itd.) čine minimalno trocifreni brojevi koje unosi korisnik programa 
(u slučaju unosa bilo kojeg broja koji ne zadovoljava postavljeni uslov, ponoviti unos); 
elementi parnih redova matrice se formiraju na osnovu elemenata iz prethodnog reda u istoj koloni matrice 
i to na način da je svaki novokreirani element matrice zapravo element s obrnutim redoslijedom cifri elementa iznad njega. 
•	Za određivanje broja s obrnutim redoslijedom cifri kreirati zasebnu funkciju obratno, te je pozvati u funkciji unos. 
•	Takvu matricu proslijediti zasebnoj funkciji max koja će formirati novi jednodimenzionalni niz čije članove čine 
najveći članovi matrice po redovima te ispisati ove članove.
•	Formirati posebnu funkciju iznad_dijagonala koja će ispisati broj elemenata matrice koji se nalaze 
iznad glavne i sporedne dijagonale. 

Ove elemente unutar funkcije spremati u niz čija veličina zavisi od dimenzije matrice. 

Veličina niza treba biti fiksna i mora odgovarati točnom broju elemenata. 
Kreirati kratki testni program koji demonstrira funcionalnost kreiranih funkcija.
Primjer matrice dimenzija 4x4 i očekivanih rezultata je dat ispod. Elementi iznad obje dijagonale  su: 123, 30452.

2163	123		30452	671
3612	321		25403	176
7331	6113	741232	798
1337	3116	232147	897

Funkcija max će ispisati sljedeće brojeve: 30452, 25403, 741232, 232147 jer su to najveći brojevi po redovima. 
*/

#include <iostream>
#include <iomanip>
using namespace std;

const int var = 4;

int obrnuti(int broj)
{
	int brojac = 3;
	int kopija = broj / 1000;
	while (kopija > 0)
	{
		kopija /= 10;
		brojac++;
	}

	while (brojac>0)
	{
		kopija += broj % 10;
		kopija *= 10;
		broj /= 10;
		brojac--;
	}
	return kopija/10;
}

void unos(int  niz[][var])
{
	for (int i = 1; i < var; i+=2)
	{
		for (int j = 0; j < var; j++)
		{
			do
			{
				cout << "niz[" << i << "][" << j << "] = ";
				cin >> niz[i][j];
			} while (niz[i][j] < 100);

			niz[i - 1][j] = obrnuti(niz[i][j]);
		}
	}
}

void ispis(int niz[][var])
{
	for (int i = 0; i < var; i++)
	{
		for (int j = 0; j < var; j++)
		{
			cout << setw(7) << niz[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void max(int niz[][var], int skupBrojeva[])
{
	int max;
	for (int i = 0; i < var; i++)
	{
		max = 0;
		for (int j = 0; j < var; j++)
		{
			if (niz[i][j] > max)
				max = niz[i][j];
		}
		skupBrojeva[i] = max;
	}
}

void ispisNizaJ(int niz[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << setw(7) << niz[i] << " ";
	}
	cout << endl;
}

void iznad_dijagonala(int niz[][var], int sporedna[], char izbor)
{
	int duzina = var - 1;
	int brojac = 0;
	for (int i = 0; i < var; i++)
	{
		for (int j = 0; j < var; j++)
		{
			if ((i<j && izbor == 'g') || (i + j<duzina && izbor == 's'))
			{
				sporedna[brojac++] = niz[i][j];
			}
		}
	}
}

int main()
{
	int niz[var][var];
	int skupBrojeva[var];
	
	//int diagonala = (var*var - var) / 2;
	//(4*4-4)/2=6

	int sporedna[6];
	char izbor;

	unos(niz);
	system("CLS");
	ispis(niz);
	
	max(niz, skupBrojeva);

	ispisNizaJ(skupBrojeva, var);

	do
	{
		cout << "Unesi izbor g ili s";
		cin >> izbor;
	} while (izbor != 'g' && izbor != 's');

	iznad_dijagonala(niz, sporedna, izbor);

	cout << endl;

	ispisNizaJ(sporedna, 6);
	

	system("PAUSE");
	return 0;
}

