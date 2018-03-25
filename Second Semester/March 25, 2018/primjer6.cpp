#include <iostream>
using namespace std;

void dinamickiPok()
{
	float broj;
	float *pokazivacBroj = new float(3.65);//&broj;
	cout << *pokazivacBroj << endl;
	delete pokazivacBroj;
	pokazivacBroj = 0;
}

int unos(int *niz, int n)
{
	int brojac = 0;
	for (size_t i = 0; i < n; i++)
	{
		cout << "Unesi niz[" << i << "] = ";
		cin >> niz[i];
		if (niz[i] < 0)
			brojac++;
	}
	return brojac;
}

void unosNovog(const int *niz, int *nizNovi,const int vel)
{
	int j = 0;
	for (size_t i = 0; i < vel; i++)
		if (niz[i] < 0)
			nizNovi[j++] = niz[i];
}

void ispis(const int *niz, const int n)
{
	for (size_t i = 0; i < n; i++)
		cout << niz[i] << " ";
	cout << endl;
}

int main()
{
	//Kreirati dinamicki niz od onoliko cjelobrojnih elemenata koliko zeli korisnik
	int n;
	cout << "Koliko zelite elemenata unijeti: ";
	cin >> n;
	cin.ignore();
	
	if (n <= 0)
		return 0;

	int *niz = new int[n];

	//Omoguciti inicijalizaciju clanova niza unosom s tastature
	//Utvrditi koliko elemenata niza je manje od 0
	int manjeOdNula = unos(niz, n);

	//Kreirati novi niz ciji ce elementi biti elementi prvog niza koji zadovoljavaju prethodni uvjet (manji su od 0)
	
	int *nizNovi = new int[manjeOdNula];
	unosNovog(niz, nizNovi, n);

	system("CLS");

	cout << "Niz: ";
	ispis(niz, n);
	
	cout << "Brojevi manji od nula: ";
	ispis(nizNovi, manjeOdNula);

	delete[] niz;
	delete[] nizNovi;

	system("PAUSE");
	return 0;
}