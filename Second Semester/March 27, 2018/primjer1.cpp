#include <iostream>
using namespace std;

enum class KoristeniClan { eChar, eInt, eFloat, eDouble};

struct EnumracijeUnije
{
	KoristeniClan koristeni;
	union
	{
		char C;
		int X;
		float Y;
		double Z;
	};
};

void Unos(EnumracijeUnije &obj)
{
	int unos;
	cout << "Odaberite tip podataka koji unosite: ";
	cin >> unos;
	obj.koristeni = (KoristeniClan)unos;
	switch (obj.koristeni)
	{
	case KoristeniClan::eChar:
		cout << "Unesi neki karakter: ";
		cin >> obj.C;
		break;

	case KoristeniClan::eInt:
		cout << "Unesi neki cijeli broj: ";
		cin >> obj.X;
		break;

	case KoristeniClan::eFloat:
		cout << "Unesi neki float: ";
		cin >> obj.Y;
		break;
	case KoristeniClan::eDouble:
		cout << "Unesi neki dounle: ";
		cin >> obj.Z;
		break;
	default:
		cout << "Niste unijeli odgovarajuci broj." << endl;
		break;
	}
}

void Ispis(EnumracijeUnije &obj)
{
	switch (obj.koristeni)
	{
	case KoristeniClan::eChar:
		cout << "karakter: " << obj.C << endl;
		break;

	case KoristeniClan::eInt:
		cout << "broj: " << obj.X << endl;
		break;

	case KoristeniClan::eFloat:
		cout << "float: " << obj.Y << endl;
		break;
	case KoristeniClan::eDouble:
		cout << "double: " << obj.Z << endl;
		break;
	}
}

int main()
{
	EnumracijeUnije obj;
	Unos(obj);
	Ispis(obj);

	system("PAUSE");
	return 0;
}