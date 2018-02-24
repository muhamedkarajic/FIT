#include <iostream>
using namespace std;

const int var = 7;


void unos(int niz[var])
{
	for (int i = 0; i < var; i++)
	{
		cout << "niz[" << i << "] = ";
		cin >> niz[i];
	}
}

float suma(int niz[var])
{
	float sum = 0;

	for (int i = 0; i < var; i++)
		sum += 1 / (double)niz[i];

	return sum;
}

int main()
{
	int niz[var];
	unos(niz);
	cout << "Suma: " << suma(niz) << endl;



	system("PAUSE");
	return 0;
}