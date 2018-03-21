#include <iostream>
using namespace std;

struct Student
{
	char imePrezime[30];
	char index[10];
	int godinaStudija;
};

void Unos(Student *pok)
{
	//vrsi inicijalizaciju svih vrijednosti atributa studenta na koje pokazuje pokazivac pok
	cout << "Unesi ime i prezime: ";
	cin.getline(pok->imePrezime, 29);

	cout << "Unesi index: ";
	cin.getline(pok->index,9);
	
	cout << "Unesi godinu studija: ";
	cin >> pok->godinaStudija;
	cin.ignore();
}

Student *getPokazivac(Student *pok, int max)
{
	//1. Na samom pocetku funkcija ispisuje ime i prezime svakog studenta koji se nalazi u nizu kojeg pokazuje pokazivac pok
	cout << "Imena i prezimena svih studenata: " << endl;
	for (int i = 0; i < max; i++)
		cout << i << ". " << pok[i].imePrezime << endl;
	cout << endl;

	//2. korisnik unosi redni broj jednog od studenta cije je ime i prezime ispisano, na kojeg zeli kreirati pokazivac
	int x;
	cout << "Unesi redni broj jednog od studenata: ";
	cin >> x;
	cin.ignore();

	//3. ukoliko je redni broj validan tj. ukoliko ne premasuje gornju i dojnju granicu niza, funkcija vraca pokazivac na odabranog studenta 
	if (x >= 0 && x < max)
		return &pok[x];

	//4. ukoliko redni broj premasuje granice niza, funkcija vraca NULL
	return NULL;
}

void Pretraga(Student *pok, int max)
{
	//1. korisnik unosi broj indeksa studenta cije podatke prezentuje
	char indeks[10];
	cout << "Unesi broj indeksa kojeg zelis da pretrazis: ";
	cin.getline(indeks,9);

	//2. funkcija vrsi pretragu, te ukoliko pronadje studenta sa unesenim brojem indeksa ispisuje sve njegove podatke
	for (int i = 0; i < max; i++)
		if (strcmp(pok[i].index, indeks) == 0)
		{
			cout << "Ime: " << pok[i].imePrezime << " \nGodina: " << pok[i].godinaStudija << " \Index: " << pok[i].index << "." << endl << endl;
			return;
		}
	//3. ukoliko student se unesenim brojem indeksa ne postoji funckija treba da ispise odgovarajucu poruku
	cout << "Student sa tim indeksom nije pronadjen." << endl;
}

int main()
{
	//korisniku omoguciti da odredi koliko objekata tipa student zeli kreirati, objekte kreirati u dinamickoj memoriji
	cout << "Koliko studenata zelite unijeti: ";
	int max;
	cin >> max;
	cin.ignore();

	//korisniku omoguciti da inicijalizuje vrijednosti atributa svakog studenta
	Student * studenti = new Student[max];
	for (int i = 0; i < max; i++)
		Unos(studenti+i);

	//korisniku omoguciti pretragu studenata
	Pretraga(studenti, max);

	//kreirati pokazivac koji ce biti inicijalizovan vrijednoscu koje vrati funkcija getPokazivac. 
	Student *vraceniPok= getPokazivac(studenti, max);

	//Ukoliko je moguće, preko kreiranog pokazivaca ispisati podatke o tom studentu7
	cout << vraceniPok->imePrezime << " Godina: " << vraceniPok->godinaStudija << " Index:" << vraceniPok->index << endl;

	//dealokacija
	delete[]studenti;
	studenti = NULL;
	vraceniPok = NULL;

	system("PAUSE");
	return 0;
}