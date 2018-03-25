#include <iostream>
using namespace std;

struct radnik
{
	int ib;
	char ime[10];
	char prezime[10];
	double dohodak[3];
	int staz;
	char spol[10];
};

void unos(radnik *niz, int n)
{
	for (size_t i = 0; i < n; i++)
	{
		cout << i + 1 << ". radnik: " << endl;


		cout << "ib: ";
		cin >> niz[i].ib;
		cin.ignore();

		cout << "ime: ";
		cin.getline(niz[i].ime, 10);

		cout << "prezime: ";
		cin.getline(niz[i].prezime, 10);

		cout << "Dohodci za mjesece: " << endl;
		for (size_t j = 0; j < 3; j++)
		{
			cout << j + 1 << ": ";
			cin >> niz[i].dohodak[j];
			cin.ignore();
		}

		cout << "staz: ";
		cin >> niz[i].staz;
		cin.ignore();

		cout << "spol: ";
		cin.getline(niz[i].spol, 10);
	}
	system("CLS");
}

void ispis(radnik *niz)
{
	cout << "ib: " << niz->ib << endl;
	cout << "ime i prezime: " << niz->ime << " " << niz->prezime << endl;
	cout << "- - - - - - - - -" << endl;
	cout << "Dohodci za mjesece: " << endl;
	for (size_t i = 0; i < 3; i++)
		cout << i + 1 << ": " << niz->dohodak[i] << endl;
	cout << "- - - - - - - - -" << endl;
	cout << "staz: " << niz->staz << endl;
	cout << "spol: " << niz->spol << endl;
	cout << endl;
}

int prebroj_zene(radnik *niz, int n)
{
	int brojac = 0;
	for (size_t i = 0; i < n; i++)
		if (strcmp(niz[i].spol, "zensko") == 0)
			brojac++;
	return brojac;
}

void kopiraj_zene(radnik *niz, radnik *noviNiz, int n)
{
	int j = 0;
	for (int i = 0; i < n; i++)
		if (strcmp(niz[i].spol, "zensko") == 0)
			noviNiz[j++] = niz[i];
}

radnik *najduze_ime(radnik *niz, int n)
{
	radnik *najduzeIme = niz;
	
	for (size_t i = 1; i < n; i++)
		if (strlen(najduzeIme->ime) < strlen(niz[i].ime))
			najduzeIme = niz + i;

	return najduzeIme;
}

void pretraga_po_imenu(radnik *niz, const char *ime, int n)
{
	for (size_t i = 0; i < n; i++)
		if (strcmp(niz[i].ime, ime) == 0)
			ispis(&niz[i]);
}

double prihodi(radnik *niz, int n, int IB)
{
	for (size_t i = 0; i < n; i++)
	{
		if (niz[i].ib == IB)
		{
			int temp = 0;
			for (size_t j = 0; j < 3; j++)
				temp += niz[i].dohodak[j];
			return (niz[i].staz * 0.06) + temp;
		}
	}
	return 0;
}

int main()
{
	//kreirati dinamicki niz objekata od tipa radnik od onoliko clanova koliko zeli korisnik
	int n = 2;
	//cout << "koliko zelis radnika: ";
	//cin >> n;
	//cin.ignore();

	radnik *niz = new radnik[n];

	//kreirati funkciju za unos obiljezija za sve objekte void unos(radnik *, int);
	unos(niz, n);
	//kreirati funkciju za ispis obiljezija za jedan objekat void ispis(radnik *);
	for (size_t i = 0; i < n; i++)
		ispis(&niz[i]);

	//kreirati funkciju koja ce prebrojati koliko radnika su zene int prebroj_zene(radnik*, int);
	int x = prebroj_zene(niz, n);
	cout << "Ukupno dama u ovoj firmi ima: " << x << endl;

	//kreirati novi niz u dinamickoj memoriji
	radnik *noviNiz = new radnik[x];

	//kreirati funkciju u kojoj cete kopirati sve zene u novonapravljenoi niz, kopirati sve zene void kopiraj_zene(radnik*, radnik*, int);
	kopiraj_zene(niz, noviNiz, n);

	for (size_t i = 0; i < x; i++)
		cout << noviNiz[i].ime << " " << noviNiz[i].prezime << endl;

	//kreirati funkciju koja ce vratiti radnika sa najduzim prezimenom radnik *najduze_ime(radnik*,int);
	cout << "Najduze ime je: " << najduze_ime(niz, n)->ime << endl;

	//kreirati funkciju koja ce vrsiti pretragu po imenu, te ispisati sva obiljezija radnika za koje je utvrdjeno da imaju trazeno ime: void pretraga_po_imenu(radnik*, char *, int)
	
	cout << "Funkcija pretraga_po_imenu" << endl;
	pretraga_po_imenu(niz, "Muhamed", n);
	
	//kreirati funkciju koja ce izracunati godisnje prihode za odabranog radnika double prihodi(radnik *, int, int);
	double prihodiVar = prihodi(niz, n, 1);

	if (prihodiVar != 0)
		cout << "Prihodi ukupni iznose: " << prihodiVar << endl;
	else
		cout << "Sa takvim IDom nije pronadjen ni jedan radnik." << endl;

	//dealokacija
	delete[]niz;
	niz = NULL;

	delete[]noviNiz;
	noviNiz = NULL;

	system("PAUSE");
	return 0;
}