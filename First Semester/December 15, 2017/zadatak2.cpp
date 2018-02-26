/*
Zadatak 2:
Dat je niz od 6 karaktera. Napišite program koji će omogućiti korisniku da unese 6 velikih slova 
(obavezno spriječiti unos  karaktera koji nisu velika slova), te provjeriti i ispisati ono slovo  
(među članovima niza) koje se u pojavljuje zadnje u abecednom poretku. 
Kreirajte zasebne funkcije za: unos elemenata, ispis elemenata i funkciju koja će pronaći i 
vratiti ono slovo koje se pojavljuje za zadnje u abecednom poretku. 


Npr. ako se u nizu nalaze sljedeći elementi: K, U, C, A, F, B 
funkcija treba da vrati slovo U jer od svih elemenata niza U se 
u abecednom poretku  pojavljuje zadnje.
*/

#include <iostream>
using namespace std;

char unos(char niz[], int var)
{
	//ZADNJE SLOVO, POŠTO JE OBAVEZNO UNIJETI BAREM 1 KARAKTER, U NAJGOREM SLUČAJU VRAĆA SLOVO A, AKO SU SVI UNOSI JEDNAKI A
	char zadnje = 'A';
	for (int i = 0; i < var; i++)
	{
		//UNOS KARAKTERA OBAVEZNO IZMEĐU A - Z UKLJUČUJUCI GRANIČNE VRIJEDNOSTI
		do
		{
			cout << "niz[" << i << "] = ";
			cin >> niz[i];
		} while (!(niz[i] >= 'A' && niz[i] <= 'Z'));

		//PROVJERA DA LI JE A MANJE OD UNESENOG NIZA KOJI MORA BITI IZMEĐU A I Z
		if (zadnje<niz[i])
		{
			zadnje = niz[i];
		}

		//ISPIS SVIH VARIJABLI DO SADA
		system("CLS");
		for (int y = 0; y <= i; y++)
		{
			cout << "niz[" << y << "] = " << niz[y] << endl;
		}
	}

	//ZADNJA VARIJABLA POVRATAK
	return zadnje;
}

/*void ispis(char niz[], int var)
{
	for (int i = 0; i < var; i++)
	{
		cout << "Unesi niz[" << i << "] = " << niz[i] << endl;
	}
}*/

int main()
{
	const int var = 6;
	char niz[6];

	cout << "Zadnje slovo po abc-di je: " << unos(niz, var) << endl;
	//ispis(niz, var);





	system("PAUSE>0");
	return 0;
}