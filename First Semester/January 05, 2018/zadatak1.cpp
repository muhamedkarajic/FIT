/*
Napisati program koji će korisniku omogućiti unos pozitivnih neparnih
cijelih brojeva za koje će se ispitivati da li im je prva cifra parna (npr. 4993 ili 4999).
Ukoliko je zadovoljen uslov broj se smješta u niz od 10 elemenata. Unos se ponavlja dok se ne popuni niz od 10 elemenata koji
zadovoljavaju uslov unosa. Unos se prekida ukoliko korisnik unese vrijednost 0 te se i izvršenje program završava uz poruku
„Forsirani prekid“. Zatim se za sve elementi niza ispituje da li je broj prost i da li ima samo jednu parnu cifru.
Ako  broj nije prost i ako ima više od jedne parne cifre, broj se izbacuje iz niza tako što se njegova vrijednost mijenja sa 0.
Na kraju niz sortirati od najvećeg ka najmanjem broju te ga ispisati.
Koristiti odvojene funkcije za provjeru da li je broj prost, za sortiranje i ispis niza.
*/


#include <iostream>
#include <cmath>

using namespace std;
const int var = 10;

bool parnaCifra(int broj)
{
	while (broj > 0)
	{
		if (broj / 10 == 0 && broj % 10 % 2 == 0)
			return true;
		
		broj /= 10;
	}
	return false;
}
bool unos(int niz[])
{
	int broj;
	cout << "PRVA CIFRA MORA BITI PARNA:" << endl;
	for (int i = 0; i < var; i++)
	{
		do
		{
			cout << "Unesi broj: ";
			cin >> broj;
			if (broj == 0)
				return false;
		} while (parnaCifra(broj) == false);
		niz[i] = broj;
	}
	
	cout << endl;
	return true;
}

void ispis(int niz[])
{
	for (int i = 0; i < var; i++)
	{
		cout << niz[i] << " ";
	}
	cout << endl;
}

bool prost(int broj)
{
	if (broj==2 || broj == 3 || broj == 5 || broj == 7)
	{
		return true;
	}
	else if (broj % 2 == 0 || broj % 3 == 0 || broj % 5 == 0 || broj % 7 == 0)
	{
		return false;
	}
	else
	{
		int korijen = sqrt(broj);
		for (int i = 5; i < korijen; i+=6)
		{
			if (broj%i == 0)
			{
				return false;
			}
		}
	}
}

bool parneCifreProvjera(int broj)
{
	int brojac = 0;
	while (broj > 0)
	{
		if (broj % 10 %2 == 0)
		{
			brojac++;
			if (brojac > 1)
			{
				return true;
			}
		}
		broj /= 10;
	}
	return false;
}

void sort(int niz[])
{
	bool sortirano = false;
	int duzina = var-1;
	while (sortirano == false)
	{
		for (int i = 0; i < duzina; i++)
		{
			sortirano = true;
			if (niz[i] > niz[i + 1])
			{
				int temp = niz[i];
				niz[i] = niz[i + 1];
				niz[i + 1] = temp;
				sortirano = false;
			}
		}
		duzina--;
	}
		
}

int main()
{
	int niz[var];//421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491,
	if (unos(niz) == true)
	{
		system("CLS");
		ispis(niz);
		
		for (int i = 0; i < var; i++)
			if (prost(niz[i]) == false || parneCifreProvjera(niz[i]) == true)
				niz[i] = 0;

		cout << endl;
		ispis(niz);
		sort(niz);
		ispis(niz);
	}


	

	system("PAUSE");
	return 0;
}