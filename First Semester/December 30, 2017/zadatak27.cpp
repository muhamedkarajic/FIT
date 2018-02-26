#include <iostream>
using namespace std;

void unos(char niz[], int var)
{
	cout << "Unesi obavezno slova:" << endl;
	for (int i = 0; i < var; i++)
		do
		{
			cout << "niz[" << i << "] = ";
			cin >> niz[i];
		} while ((niz[i] < 97 || niz[i] > 122) && (niz[i] < 65 || niz[i] > 90));


}

char zadnje(char niz[], int var)
{
	int zadnje = niz[0];
	for (int i = 1; i < var; i++)
		if (niz[i] < 97 && niz[i]+32 > zadnje)
				zadnje = niz[i]+32;

		else
			if (zadnje < niz[i])
				zadnje = niz[i];

	return zadnje;
}

int main()
{
	const int var = 7;
	char niz[var];

	unos(niz, var);
	cout << "Zadnje slovo u ovom nizu: " << zadnje(niz, var) << endl;


	system("PAUSE");
	return 0;
}