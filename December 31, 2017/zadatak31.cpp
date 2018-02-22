#include <iostream>
using namespace std;

void unos(char niz[], int var)
{
	for (int i = 0; i < var; i++)
	{
		cout << "Unesi niz[" << i << "] = ";
		cin >> niz[i];
	}
}

void promjena(char niz[], int var)
{
	for (int i = 0; i < var; i++)
		if (!(niz[i] >= 65 && niz[i] <= 90 || niz[i] >= 97 && niz[i] <= 122))
			niz[i] = 'a';
}

int prebroj(char niz[], int var)
{
	int brojac = 0;

	for (int i = 0; i < var; i++)
		if (niz[i] == 'a')
			brojac++;

	return brojac;
}

int ostalo(char niz[], int var)
{
	int brojac = 0;
	for (int i = 0; i < var; i++)
		if (niz[i] != 'a')
			brojac++;

	return brojac;
}


int main()
{
	const int var = 7;
	char niz[var];

	unos(niz, var);
	promjena(niz, var);
	
	cout 
		<< "Ponavljanje slova \'a\': " << prebroj(niz, var) << endl
		<< "Ponavljanje ostalih elemenata: " << ostalo(niz, var) << endl;








	system("PAUSE");
	return 0;

}