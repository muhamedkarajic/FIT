/*
Kreirajte objekte k1,k2,k3,k4 te im dodjelite obiljezija tako da:
	- se centar kruznice k1 nalazi u prvom kvadratu, k2 u drugom, k3 u trecem, a k4 u cevtvrtom
	- preko tastature unijeti vrijednost polumjera (r) kruznice k1
	- osigurati da je vrijednost polumjera kruznice k2 jednaka polumjeru rkuznice k1
	- osigurati da polumjer kruznice k3 bude dvotruko veci od polumjera kruznice k2
	- osigurati da polumjer kruznice k4 bude zbir polumjera kruznice k2 i k3
*/


#include <iostream>
using namespace std;

struct kruznica
{
	//podaci - atributi ili obiljezija
	float x;
	float y;
	float poluprecnik;

	//metode (funckije)
	void unos()
	{
		cout << "Unesi x: ";
		cin >> x;
		cout << "Unesi y: ";
		cin >> y;
	}
	void ispis()
	{
		cout << "x = " << x << endl;
		cout << "y = " << y << endl;
		cout << "poluprecnik = " << poluprecnik << endl << endl;
	}
};

int main()
{
	kruznica k1,k2,k3,k4;
	
	do
	{
		cout << "Unesi k1:" << endl;
		k1.unos();
		cout << "Unesi poluprecnik: ";
		cin >> k1.poluprecnik;
	} while (k1.x <= 0 || k1.y <= 0 || k1.poluprecnik<=0);
	
	do
	{
		cout << "Unesi k2: " << endl;
		k2.unos();
	} while (k2.x >= 0 || k2.y <=0);
	k2.poluprecnik = k1.poluprecnik;

	do
	{
		cout << "Unesi k3: " << endl;
		k3.unos();
	} while (k3.x > 0 || k3.y > 0);
	k3.poluprecnik = 2*k2.poluprecnik;

	do
	{
		cout << "Unesi k4: " << endl;
		k4.unos();
	} while (k4.x <= 0 || k4.y >= 0);
	k4.poluprecnik = k2.poluprecnik+k3.poluprecnik;
	
	system("CLS");

	k1.ispis();
	k2.ispis();
	k3.ispis();
	k4.ispis();

	system("PAUSE");
	return 0;
}