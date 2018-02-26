#include <iostream>
using namespace std;

struct Datum
{
	int dan;
	int mjesec;
	int godina;
};

struct Student
{
	char ime[10];
	char prezime[10];
	int godina = 0;
	Datum datumR;
	void unos()
	{
		cout << "Ime: ";
		cin.getline(ime, 10);
		cout << "Prezime: ";
		cin.getline(prezime, 10);
		cout << "Godina: ";
		cin >> godina;
		cin.ignore();

		cout << "Unesi datum rodjenja(dd mm gggg): ";
		cin >> datumR.dan >> datumR.mjesec >> datumR.godina;
		cin.ignore();
	}
	void ispis()
	{
		cout << "Ime: " << ime << endl;
		cout << "Prezime: " << prezime << endl;
		cout << "Godina: " << godina << endl;
		cout << "Datum rodjenja: " << datumR.dan << "/" << datumR.mjesec << "/" << datumR.godina << endl;
	}
};


int main()
{
	const int velicina = 3;
	Student aplikanti[velicina];
	
	for (int i = 0; i < velicina; i++)
	{
		cout << i + 1 << ". APLIKANT: " << endl;
		aplikanti[i].unos();
		cout << endl;
	}
	system("CLS");

	for (int i = 0; i < velicina; i++)
	{
		cout << i + 1 << ". APLIKANT: " << endl;
		aplikanti[i].ispis();
		cout << endl;
	}

	system("PAUSE");
	return 0;
}