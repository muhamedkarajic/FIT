#include <iostream>
using namespace std;

void Funkcija1(int broj)
{
	cout << "Funkcija1: " << broj << endl;
}

void Funkcija2(int broj)
{
	cout << "Funkcija2: " << broj << endl;
}

void Poziv(void(*pok)(int), int broj)
{
	pok(broj);
}

int main()
{
	Poziv(Funkcija1, 10);
	Poziv(Funkcija2, 20);

	system("PAUSE");
	return 0;
}