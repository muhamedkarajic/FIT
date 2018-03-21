//narednu liniju code-a ignorisite, osim u slucaju da vam bude predstavljala smetnje u radu
#include <iostream>
using namespace std;
#pragma warning(disable:4996)

enum Opstina { Opstina1, Opstina2, Opstina3, Opstina4 };
const char * OpstineChar[] = { "Opstina1", "Opstina2", "Opstina3", "Opstina4" };
enum Kandidati { Kandidat1, Kandidat2, Kandidat3, Kandidat4 };
const char * KandidatiChar[] = { "Kandidat1", "Kandidat2", "Kandidat3", "Kandidat4" };

struct Datum {
	int _dan, _mjesec, _godina;
	void Unos(int d, int m, int g) { _dan = d; _mjesec = m; _godina = g; }
	void Ispis() { cout << _dan << "/" << _mjesec << "/" << _godina << endl; }
	bool Provjera(const Datum &OD, const Datum &DO)
	{
		int ukupno = _godina * 356 + _mjesec * 30 + _dan;
		int tempOD = OD._godina * 356 + OD._mjesec * 30 + OD._dan;
		int tempDO = DO._godina * 356 + DO._mjesec * 30 + DO._dan;
		if (tempOD <= ukupno && tempDO >= ukupno)
		{
			Ispis();
			return true;
		}
		return false;
	}
};
struct Osoba {
	Datum _datumRodjenja;
	char * _imePrezime;
	char _JMBG[14];
	Opstina _Prebivaliste;
	void unos(Datum d, const char * ip, const char jmbg[], Opstina p) {
		_datumRodjenja = d;
		_imePrezime = new char[strlen(ip) + 1];
		strcpy(_imePrezime, ip);
		strcpy(_JMBG, jmbg);
		_Prebivaliste = p;
	}
	void Dealociraj() { delete[] _imePrezime; _imePrezime = nullptr; }
	void Info() {
		_datumRodjenja.Ispis();
		cout << _imePrezime << " " << _JMBG << " " <<
			OpstineChar[_Prebivaliste] << endl;
	}
};
struct Glas {
	Osoba * _glasac;
	Kandidati * _glasZa;
	void Unos(Osoba &o,const Kandidati &k) {
		_glasac = new Osoba();
		_glasac->unos(o._datumRodjenja, o._imePrezime, o._JMBG, o._Prebivaliste);
		_glasZa = new Kandidati(k);
	}
	void Ispis() {
		_glasac->Info();
		cout << KandidatiChar[*_glasZa] << endl;
	}
	void Dealociraj() { _glasac->Dealociraj(); }
};
struct Izbori2016 {
	Opstina * _glasackoMjesto;
	Glas * _glasovi[1000];
	int _doSadaGlasalo;
	void Unos(const Opstina& ops)
	{
		_glasackoMjesto = new Opstina(ops);
		_doSadaGlasalo = 0;
		for (int i = 0; i < 1000; i++)
		{
			_glasovi[i] = nullptr;
		}
	}

	void DodajGlas(Glas& gl) {
		
		_glasovi[_doSadaGlasalo] = new Glas();
		_glasovi[_doSadaGlasalo++]->Unos(*gl._glasac, *gl._glasZa);
	}
	void Ispis() {
		cout << OpstineChar[*_glasackoMjesto] << endl;
		for (int i = 0; i < _doSadaGlasalo; i++)
		{
			_glasovi[i]->Ispis();
		}
	}

	int BrojGlasacaPoRodjenju(const Datum &OD, const Datum &DO)
	{
		int sum = 0;
		for (int i = 0; i < _doSadaGlasalo; i++)
		{
			if (_glasovi[i]->_glasac->_datumRodjenja.Provjera(OD,DO))
				sum++;
		}
		return sum;
	}

	void Dealociraj() {

		delete _glasackoMjesto;
		_glasackoMjesto = nullptr;

		for (int i = 0; i < 1000; i++)
		{
			delete _glasovi[i];
			_glasovi[i] = nullptr;
		}
	}
	


	/*
	1. Unos - na osnovu vrijednosti primljenih parametara, inicijalizovati vrijednosti atributa strukture.
	2. DodajGlas - funkcija treba da omoguci dodavanje informacija o novom glasu i tom prilikom onemoguciti: da ista osoba glasa vise puta, glasanje osobama mladjim od 18 godina (uzeti u obzir samo mjesec i godinu rodjenja), glasanje osobama iz drugih opstina. U zavisnosti od uspjesnosti operacije funkcija vraca true ili false
	3. Ispis - u zavisnosti od postignutog uspjeha funkcija treba ispisati listu kandidata sortiranu opadajucim redoslijedom, a uz svakog kandidata je potrebno ispisati i osvojeni procenat glasova.
	Funkcija vraca opstinu u kojoj je pobjednicki kandidat ostvario najveci broj glasova, a ukoliko je pobjednicki kandidat ostvario podjednak broj glasova u vise opstina, funkcija vraca prvu koja se nalazi u nizu na koji pokazuje pokazivac izbornaMjesta
	4. BrojGlasacaPoRodjenju - funkcija vraca broj glasaca koji su do tog momenta glasali, a koji su rodjeni u parametrima definisanom periodu (parametri su tipa datum, period OD i DO)
	*/
};
/*
1. UpisiUBinarniFajl - objekat koji je primljen kao parametar upisuje u binarni fajl. Naziv fajla treba biti identican nazivu opstine u kojoj se odrzavaju izbori
2. UcitajIzBinarnogFajla - u objekat koji je primljen kao parametar ucitava sadrzaj binarnog fajla (naziv fajla je takodjer proslijedjen kao parametar)
3. PretragaRekurzivno - rekurzivna funkcija koja treba da vrati broj glasova koje je na izborima ostvario odredjeni kandidat (kandidat se proslijedjuje kao parametar)
*/
int PretragaRekurzivno(Izbori2016 o, int i)
{
	if (i == o._doSadaGlasalo)
		return 0;
	else if (*o._glasovi[i]->_glasZa == Kandidat1)
		return 1 + PretragaRekurzivno(o, i + 1);
	return PretragaRekurzivno(o,i+1);
}


void main() {
	/*
	1. BROJ I VRSTA PARAMETARA MORAJU BITI IDENTICNI KAO U PRIMJERIMA. U SUPROTNOM SE RAD NEĆE BODOVATI
	2. STAVITE KOMENTAR NA DIJELOVE CODE-A KOJE NE BUDETE IMPLEMENTIRALI
	3. KREIRAJTE .DOC FAJL SA VAŠIM BROJEM INDEKSA ( NPR. IB130030.DOC BEZ IMENA I PREZIMENA), TE NA KRAJU ISPITA U NJEGA KOPIRAJTE RJEŠENJA VAŠIH ZADATAKA. NE PREDAVATI .TXT ILI .CPP FAJLOVE
	4. TOKOM IZRADE ISPITA NIJE DOZVOLJENO KORIŠTENJE HELP-A
	5. TOKOM IZRADE ISPITA MOGU BITI POKRENUTA SAMO TRI PROGRAMA: PDF READER (ISPITNI ZADACI), MS VISUAL STUDIO, MS WORD (U KOJI ĆETE KOPIRATI VAŠA RJEŠENJA)
	6. BEZ OBZIRA NA TO DA LI SU ISPITNI ZADACI URAĐENI, SVI STUDENTI KOJI SU PRISTUPILI ISPITU MORAJU PREDATI SVOJ RAD
	*/

	Datum datumGlasac1, datumGlasac2, datumGlasac3, datumGlasac4, datumIzbora;
	datumIzbora.Unos(14, 7, 2016);
	datumGlasac1.Unos(18, 5, 1990);
	datumGlasac2.Unos(5, 3, 1982);
	datumGlasac3.Unos(12, 8, 1958);
	datumGlasac4.Unos(22, 6, 2000);

	Osoba a, b, c, d, e;
	a.unos(datumGlasac1, "Denis Music", "1111111111111", Opstina1);
	b.unos(datumGlasac2, "Jasmin Azemovic", "1111111111112", Opstina1);
	c.unos(datumGlasac3, "Indira Hamulic", "1111111111113", Opstina1);
	d.unos(datumGlasac4, "Adel Handzic", "1111111111114", Opstina2);
	e.unos(datumGlasac4, "Zanin Vejzovic", "1111111111115", Opstina1);


	Glas g1, g2, g3, g4, g5;
	g1.Unos(a, Kandidat1);
	g2.Unos(b, Kandidat1);
	g3.Unos(c, Kandidat2);
	g4.Unos(d, Kandidat1);
	g5.Unos(e, Kandidat2);

	Izbori2016 izbori, izbori_FromFile;
	izbori.Unos(Opstina1);
 	izbori.DodajGlas(g1);
	izbori.DodajGlas(g2);
	izbori.DodajGlas(g3);
	izbori.DodajGlas(g4);
	izbori.DodajGlas(g5);
	izbori.Ispis();
	Datum OD, DO;
	OD.Unos(18, 5, 1990);
	DO.Unos(17, 7, 2000);
	cout << "Kandidati sa datumima koji su u intervalu: " << endl;
	cout << "Glasaca u starost od 18 - 30 godina->" << izbori.BrojGlasacaPoRodjenju(OD, DO) << endl;

	cout << "Broj glasova za Kandidat1->" << PretragaRekurzivno(izbori, Kandidat1) << endl;
	system("PAUSE");
	//UpisiUBinarniFajl(izbori);
	//UcitajIzBinarnogFajla(izbori_FromFile, "Opstina1");
	//izbori_FromFile.Ispis();
}