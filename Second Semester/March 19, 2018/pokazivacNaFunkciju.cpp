#include <iostream>
using namespace std;

int funkcija()
{
	return 10;
}

int saberi(int a, int b)
{
	return a+b;
}

int oduzmi(int a, int b)
{
	return a - b;
}

int matOperacije(int(*p)(int, int), int a, int b)//prima pokazivac na funkciju, a, b parametre
{
	return p(a, b);//odlazi na adresu i vrsi kalkulaciju
}

int main()
{
	cout << "Vrijednost funkcije: " << funkcija() << endl;
	cout << "Adresa funkcije: " << funkcija << endl;
	cout << endl;


	int(*p)() = nullptr;
	p = funkcija;

	cout << "Pokazivac na funkciju, vrijednost, p(): " << p() << endl;
	cout << "Pokazivac na funkciju, adresa, p: " << p << endl;
	cout << "Pokazivac na funkciju, adresa, funkcija: " << &funkcija << endl; //&funkcija ili funkcija - isto je
	cout << endl;


	int(*x)(int, int) = saberi;

	cout << "Pokazivac na funkciju, vrijednost: " << x(5,10) << endl;
	cout << "Pokazivac na saberi funkciju, adresa, x: " << x << endl;
	cout << "Pokazivac na saberi funkciju, adresa, saberi: " << saberi << endl; //&saberi ili saberi - isto je
	cout << endl;

	x = oduzmi;

	cout << "Pokazivac na funkciju, vrijednost: " << x(5, 10) << endl;
	cout << "Pokazivac na oduzmi funkciju, adresa, x: " << x << endl;
	cout << "Pokazivac na oduzmi funkciju, adresa, oduzmi: " << oduzmi << endl;
	cout << endl;

	cout << "Math Operacija, saberi: " << matOperacije(saberi, 50,20) << endl;
	cout << "Math Operacija, oduzmi: " << matOperacije(oduzmi, 50, 20) << endl;
	cout << endl;



	system("PAUSE");
	return 0;
}