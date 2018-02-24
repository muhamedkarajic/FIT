#include <iostream>
#include <iomanip>
using namespace std;

void unos(int niz[], int var)
{
	for (int i = 0; i < var; i++)
	{
		cout << "Unesi niz[" << i << "] = ";
		cin >> niz[i];
	}
}

void ispis(int niz[], int var)
{
	for (int i = 0; i < var; i++)
	{
		cout << setw(5) << niz[i] << " " << endl;
	}
}





int main()
{
	const int var = 10;
	int niz[var];

	unos(niz,var);
	ispis(niz, var);

	system("PAUSE");
	return 0;
}