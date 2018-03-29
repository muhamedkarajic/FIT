#include <iostream>
using namespace std;


float podjeli(float a, float b)
{
	return a / b;
}

int main()
{
	float(*pFunkcija)(float, float) = podjeli;
	cout << "podjeli: " << podjeli << endl;
	cout << "podjeli(3344.23, 191.42): " << podjeli(3344.23, 191.42) << endl;
	cout << "pFunkcija: " << pFunkcija << endl;
	cout << "*pFunkcija: " << *pFunkcija << endl;
	cout << "pFunkcija(3344.23, 191.42): " << pFunkcija(3344.23, 191.42) << endl;
	cout << "*pFunckija(3344.23, 191.42): " << "nije moguce ispisati" << endl;

	system("PAUSE");
	return 0;
}