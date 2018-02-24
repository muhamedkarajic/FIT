#include <iostream>
using namespace std;


const int var = 7;

void unos(float niz[var])
{
	for (int i = 0; i < var; i++)
	{
		cout << "niz[" << i << "] = ";
		cin >> niz[i];
	}
}

int najmanji(float niz[var])
{
	int najmanjiBroj = niz[0], najmanjiIndeks = 0;
	for (int i = 1; i < var; i++)
	{
		if (najmanjiBroj > niz[i])
		{
			najmanjiBroj = niz[i];
			najmanjiIndeks = i;
		}
	}
	return najmanjiIndeks;
}

float najveciBroj(float niz[var])
{
	float najveciBroj = niz[0];
	for (int i = 1; i < var; i++)
	{
		if (najveciBroj < niz[i])
		{
			najveciBroj = niz[i];
		}
	}
	return najveciBroj;
}


int main()
{
	float niz[var];
	unos(niz);
	cout << "Najmanji indeks: " << najmanji(niz) << endl;
	cout << "Najveci broj u nizu: " << najveciBroj(niz) << endl;



	system("PAUSE");
	return 0;
}