/*
Kreirajte niz objekata ucenik (o broju objekata odlučuje korisnik) sa sljedećim obilježjima:
•	ime, //neka ime i prezime pokazivači na char
•	prezime,
•	spol,
•	ocjene (najmanje 5);
•	matični broj (13 znamenki)

Kreirajte:
•	fukciju za u za unos obilježja jednog objekta;
•	funkciju za ispis obilježja jednog objekta;
•	funkciju koja će pronaći i vratiti objekt/ucenika koji ima najduže prezime;
•	funkciju koja pronalazi sve ucenike koji u svom imenu imaju kombnaciju slova „mir“; ispisati sva obilježja pronađenih učenika uz pomoć funkcije ispis;
•	funkciju čija je zadaća da izračuna prosječnu ocjenu učenika;
•	funkciju koja će sortirati učenike prema prosjeku (silazno, od učenika s najvišim prosjekom do učenika s najmanjim prosjekom);
•	fukciju koja će u imenu svakog učenika zamijeniti mala slova velikim i obrnuto;
•	funkciju koja će prebrojati za svakog učenika koliko ima vokala u prezimenu;
•	funkciju koja će omogućiti pretragu objekata/učenika po imenu;
•	funkciju koja će omogućiti pretragu objekata/učenika po prezimenu;
•	funkciju koja će pronaći sve učenika čiji matični broj počinje brojem 3;
•	dealocirati sve dinamički kreirane objekte.
*/
#include <iostream>
using namespace std;

struct ucenik
{
	char *ime;
	char *prezime;
	char spol;
	int ocjene[5];
	char matricniBroj[15];
	double prosjecna;


	void unos()
	{
		char niz[15];

		cout << "ime: ";
		cin.getline(niz,15);
		ime = new char[strlen(niz)+1];
		strcpy_s(ime, strlen(niz) + 1, niz);

		cout << "prezime: ";
		cin.getline(niz, 15);
		prezime = new char[strlen(niz) + 1];
		strcpy_s(prezime, strlen(niz) + 1, niz);

		cout << "spol: ";
		cin >> spol;

		for (int i = 0; i < 5; i++)
		{
			cout << "ocjena " << i + 1 << ": ";
			cin >> ocjene[i];
		}
		cin.ignore();

		cin.getline(matricniBroj, 15);
	}

	void ispis()
	{
		cout << "ime: " << ime << endl;
		cout << "prezime: " << prezime << endl;
		cout << "spol: " << spol << endl;

		for (int i = 0; i < 5; i++)
			cout << "ocjena " << i + 1 << ": " << ocjene[i] << endl;
		
		cout << "matricni: " << matricniBroj << endl;
		cout << endl;
	}
};

ucenik *najduzePrezime(ucenik *niz, int n)
{
	ucenik *prezime = niz;

	for (int i = 0; i < n; i++)
		if (strlen(prezime->prezime) < strlen(niz[i].prezime))
			prezime = &niz[i];

	return prezime;
}

void pretraziImena(ucenik *niz, int n)
{
	for (int i = 0; i < n; i++)
		if (strstr(niz[i].ime, "mir"))
			niz[i].ispis();
}

void prosjecnaOcjena(ucenik &niz)
{
	int sum = 0;
	for (int i = 0; i < 5; i++)
		sum += niz.ocjene[i];
	niz.prosjecna = sum / 5.0;
}

int vokaliPrezimena(ucenik niz)
{
	int vokali = 0;
	int vel = strlen(niz.prezime);
	for (int i = 0; i < vel; i++)
		if (toupper(niz.ime[i]) == 'A' || toupper(niz.ime[i]) == 'E' || toupper(niz.ime[i]) == 'I' || toupper(niz.ime[i]) == 'O' || toupper(niz.ime[i]) == 'U')
			vokali++;
	return vokali;
}

void pretragaImena(ucenik *niz, int n)
{

	char temp[15];
	cout << "Unesi ime s kojim zelite pretrazivati: ";
	cin.getline(temp, 15);

	for (int i = 0; i < n; i++)
		if (strcmp(niz[i].ime, temp)==0)
			niz[i].ispis();
}

void pretragaPrezimena(ucenik *niz, int n)
{

	char temp[15];
	cout << "Unesi prezime s kojim zelite pretrazivati: ";
	cin.getline(temp, 15);

	for (int i = 0; i < n; i++)
		if (strcmp(niz[i].prezime, temp) == 0)
			niz[i].ispis();
}

void matricni(ucenik *niz, int n)
{
	for (int i = 0; i < n; i++)
		if (niz[i].matricniBroj[0] == '3')
			niz[i].ispis();
}


void sortiranjeUcenika(ucenik *niz, int n)
{
	ucenik temp;
	bool sortirano = false;
	while (sortirano != true)
	{
		sortirano = true;
		for (int i = 0; i < n-1; i++)
		{
			if (niz[i].prosjecna < niz[i + 1].prosjecna)
			{
				temp = niz[i];
				niz[i] = niz[i+1];
				niz[i + 1] = temp;
				sortirano = false;
			}
		}
		n--;
	}
}

void malaVelika(ucenik *niz, int n)
{
	for (int i = 0; i < n; i++)
	{
		int duzinaIme = strlen(niz[i].ime) + 1;
		for (int j = 0; j < duzinaIme; j++)
			if (isupper(niz[i].ime[j]))
				niz[i].ime[j] = tolower(niz[i].ime[j]);
			else if(islower(niz[i].ime[j]))
				niz[i].ime[j] = toupper(niz[i].ime[j]);
	}
}

void dealociraj(ucenik *&niz, int n)
{
	for (int i = 0; i < n; i++)
	{
		delete[]niz[i].ime;
		niz[i].ime = nullptr;
		delete[]niz[i].prezime;
		niz[i].prezime = nullptr;
		
	}
	delete[]niz;
	niz = nullptr;
}


int main()
{

	int n;
	cout << "n = ";
	cin >> n;
	cin.ignore();

	ucenik *niz = new ucenik[n];

	for (int i = 0; i < n; i++)
		niz[i].unos();
	system("CLS");

	for (int i = 0; i < n; i++)
		niz[i].ispis();

	ucenik *najduzimPrezimenom = najduzePrezime(niz, n);

	cout << "Najduzim prezimenom je : " << najduzimPrezimenom->ime << " " << najduzimPrezimenom->prezime << endl;


	cout << " - - - - - - - - - - -" << endl;
	pretraziImena(niz, n);
	cout << " - - - - - - - - - - -" << endl;


	prosjecnaOcjena(niz[0]);
	cout << "prosjecna ocjena ucenika broj 1: " << niz[0].prosjecna << endl;

	for (int i = 0; i < n; i++)
		prosjecnaOcjena(niz[i]);
	cout << endl;

	sortiranjeUcenika(niz, n);

	
	for (int i = 0; i < n; i++)
		cout << niz[i].ime << ": " << niz[i].prosjecna << endl;
	cout << endl;


	malaVelika(niz, n);


	for (int i = 0; i < n; i++)
		cout << niz[i].ime << " " << niz[i].prezime << endl;
	cout << endl;

	cout << "Vokali imena " << niz[0].ime << ": " << vokaliPrezimena(niz[0]) << endl;

	pretragaImena(niz, n);
	pretragaPrezimena(niz, n);

	cout << "Maticni broj sa 3: " << endl;
	matricni(niz, n);

	dealociraj(niz, n);

	system("PAUSE");
	return 0;
}