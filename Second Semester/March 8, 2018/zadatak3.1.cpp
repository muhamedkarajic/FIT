/*
Napisite program koji ce omoguciti unos rednog broja, prezime i ime za 3 ucenika, te broj opravdanih i neopravdanih sati.
- Ispisati redni broj, ime i prezime, te broj opravdanih i neopravdanih sati za svakog ucenika.
- Izračunati i ispisati ukupan broj opravdanih i neopravdanih sati ( za sve učenike),
- te izracunati ime i prezime učenika s najmanjim broje neopravdanih
- i ime i prezime ucenika s najvecnim brojem opravdanih sati.

Koristite funkcije.

Rijesite zadatka u dvrije varijante:
varijanta 1 - kreirati tri pojedinacna objekta tipa ucenik + odgovarajuce funkcije
varijanta 2 - kreirati niz objekata tipa niz + odgovarajuce funkcije
*/

//biblioteke
#include <iostream>
using namespace std;

//strukture
struct ucenik
{
	int redniBroj, opravdani, neopravdani;
	char ime[10];
	char prezime[10];
};

//deklaracija funkcija
void linija();
void unos(ucenik &);
void ispis(ucenik);
void suma(ucenik [], int);
ucenik Uzornik(ucenik[], int);
ucenik Bolestan(ucenik[], int);

int main()
{
	const int len = 3;
	ucenik u[len];
	//u1 = u2 = u3 = {}; // - ne treba jer se salje po referenci i unos cemo uraditi ipak je dobra praksa

	for (int i = 0; i < len; i++)
		unos(u[i]);

	system("CLS");
	for (int i = 0; i < len; i++)
		ispis(u[i]);

	suma(u,len);
	linija();

	cout << "Uzornik: " << endl;
	ispis(Uzornik(u,len));

	cout << "Bolestan" << endl;
	ispis(Bolestan(u, len));

	system("PAUSE");
	return 0;
}



//definicija funkcija
void linija()
{
	cout << "- - - - - - - - - - - - - - -\n" << endl;
}

void unos(ucenik &u)
{
	cout << "Unesi redni broj: ";
	cin >> u.redniBroj;
	cin.ignore();
	cout << "Unesi ime: ";
	cin.getline(u.ime, 10);

	cout << "Unesi prezime: ";
	cin.getline(u.prezime, 10);

	cout << "Broj opravdanih sati: ";
	cin >> u.opravdani;

	cout << "Broj neopravdanih sati: ";
	cin >> u.neopravdani;

	cout << endl;
}

void ispis(ucenik u)
{
	cout << "Redni broj: " << u.redniBroj << endl;
	cout << "Ime: " << u.ime << endl;
	cout << "Prezime: " << u.prezime << endl;
	cout << "Opravdanih sati: " << u.opravdani << endl;
	cout << "Neopravdanih sati: " << u.neopravdani << endl;
	linija();
}

void suma(ucenik u[], int len)
{
	int sumaOpravdani = 0;
	int sumaNeopravdani = 0;

	for (int i = 0; i < len; i++)
	{
		sumaOpravdani += u[i].opravdani;
		sumaNeopravdani += u[i].neopravdani;
	}

	cout << "SUMA SVIH UCENIKA: " << endl;
	cout << "Ukupran broj opravdanih: " << sumaOpravdani << endl;
	cout << "Ukupran broj neopravdanih: " << sumaNeopravdani << endl;
}
ucenik Uzornik(ucenik u[], int len)
{
	int min = u[0].neopravdani;
	int index = 0;
	for (int i = 1; i < len; i++)
	{
		if (min > u[i].neopravdani)
		{
			min = u[i].neopravdani;
			index = i;
		}
	}
	return u[index];
}

ucenik Bolestan(ucenik u[], int len)
{
	int min = u[0].opravdani;
	int index = 0;
	for (int i = 1; i < len; i++)
	{
		if (min < u[i].opravdani)
		{
			min = u[i].opravdani;
			index = i;
		}
	}
	return u[index];
}
