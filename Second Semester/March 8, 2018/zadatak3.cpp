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

#include <iostream>
using namespace std;



struct ucenik
{
	int redniBroj,opravdani, neopravdani;
	char ime[10];
	char prezime[10];
};

void unos(ucenik &);
void ispis(ucenik);
void suma(ucenik, ucenik, ucenik);
ucenik Uzornik(ucenik, ucenik, ucenik);

int main()
{
	ucenik u1, u2, u3;
	//u1 = u2 = u3 = {}; // - ne treba jer se salje po referenci i unos cemo uraditi ipak je dobra praksa
	
	unos(u1);
	unos(u3);
	unos(u2);

	system("CLS");

	ispis(u1);
	ispis(u2);
	ispis(u3);
	
	suma(u1, u2, u3);
	
	ispis(Uzornik(u1, u2, u3));

	//cout << "Uzoran ucenik je: " << ispis(Uzornik(u1, u2, u3)) << endl;


	
	
	system("PAUSE");
	return 0;
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
	cout << "- - - - - - - - - - - - " << endl;
	cout << endl;
}

void suma(ucenik u1, ucenik u2, ucenik u3)
{
	cout << "SUMA SVIH UCENIKA: " << endl;
	cout << "Ukupran broj opravdanih: " << u1.opravdani + u2.opravdani + u3.opravdani << endl;
	cout << "Ukupran broj neopravdanih: " << u1.neopravdani + u2.neopravdani + u3.neopravdani << endl;
}
ucenik Uzornik(ucenik u1, ucenik u2, ucenik u3)
{
	if (u1.neopravdani <= u2.neopravdani && u1.neopravdani <= u3.neopravdani)
		return u1;
	else if (u2.neopravdani <= u3.neopravdani)
		return u2;
	else
		return u3;
}
