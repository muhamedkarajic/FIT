#include <iostream>
#include <cmath>
using namespace std;
/*

Napisati program, poštujući sve faze procesa programiranja, koji na osnovu ulaznih vrijednosti x i n izračunava vrijednost sljedećeg izraza:


*/





int fib(int n)
{
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	
	int fibinaci = 1;
	int predhodni = 0;
	int suma = 0;
	for (int i = 2; i <= n; i++)
	{
		suma = fibinaci + predhodni;
		predhodni = fibinaci;
		fibinaci = suma;
	}

	return fibinaci;
}

double sumaUkupna(int n, int x)
{
	double suma = 0;

	for (int i = 0; i <=n; i++)
	{
		suma += (fib(i) + x) / pow((x + i), i+1);
	}

	return suma;
}


int main()
{
	int n;
	float x;

	do
	{
		cout << "Unesi n: ";
		cin >> n;
	} while (n<0);

	cout << "Unesi x: ";
	cin >> x;
	
	cout << "Ukupna suma: " << sumaUkupna(n, x) << endl;


	system("PAUSE");
	return 0;
}