/*
Poštujući sve faze procesa programiranje, napisati program će odrediti i ispisati zadnje tri cifre broja x^n. 
Unos brojeva x i n vršiti u glavnoj funkciji uz uslov 10<x<100 i 2<n<10, a funkciju za određivanje zadnje 
tri cifre napraviti zasebno.
Primjer izlaza:
Unesite brojeve x i n: 64 i 5
Zadnje tri cifre broja su: 824
*/

#include <iostream>
#include <iomanip>
using namespace std;

int Cifre(int n)
{
	if (n>999)
		return n % 1000;
	else
		return n;
}

int main()
{
	int x, n;

	do
	{
		cout << "Unesi x = ";
		cin >> x;
	} while (x<10 || x>99);
	
	do
	{
		cout << "Unesi n = ";
		cin >> n;
	} while (n<2 || n>9);

	cout << "Zadne tri cifre su: " << Cifre(pow(x, n)) << endl;

	system("PAUSE");
	return 0;
}