#include <iostream>
using namespace std;

void unos(int *niz, int vel)
{
	for (size_t i = 0; i < vel; i++)
		cin >> niz[i];
	system("CLS");
}

void ispis(int *niz, int vel)
{
	for (size_t i = 0; i < vel; i++)
		cout << niz[i] << " ";
	cout << endl;
}

int *najveci(int *niz, int vel)
{
	int *temp = niz;

	for (size_t i = 0; i < vel; i++)
		if (*temp < niz[i])
			temp = &niz[i];
	
	return temp;
}

int main()
{

	int n;
	cout << "Koliko zelite elemenata u nizu: ";
	cin >> n;

	int *niz = new int[n];

	//omoguciti unos elemenata niza- funkcija prima pokazivac 
	void(*pokNaFunkciju)(int *, int) = unos;
	pokNaFunkciju(niz, n);

	//omoguciti ispis elemenata niza- funkcija prima pokazivac 
	pokNaFunkciju = ispis;
	pokNaFunkciju(niz, n);
	
	
	//pronaci adresu elementa koji je najveci u nizu -funkcija treba vratiti pokazivac
	//kreirati pokazivac/e na funkciju i preko njega pozvati predhodno definisane funkcije
	int*(*najveciPok)(int *, int) = najveci;
	cout << "Najveci broj: " << *najveciPok(niz, n) << endl;
	

	//ne zaboraviti dealocirati dinamicki kreirane objekte
	delete[]niz;
	niz = NULL;

	system("PAUSE");
	return 0;
}