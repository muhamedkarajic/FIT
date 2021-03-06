#include <iostream>
#include <iomanip>
using namespace std;

//Kreirati stukturu obuca koja ima sljedece obiljezija velicina, boja, model:
struct obuca
{
	int velicina;
	char *boja;
	char *model;
};

//Omoguciti unos elemenata
void velikaSlova(char *str, int n)
{
	for (int i = 0; i < n; i++)
	{
		str[i] = toupper(str[i]);
	}
}

void unos(obuca *obj)
{
	cout << "velicina: ";
	cin >> obj->velicina;
	cin.ignore();

	cout << "boja: ";
	obj->boja = new char[10];
	cin.getline(obj->boja, 10);
	velikaSlova(obj->boja, strlen(obj->boja));


	cout << "model: ";
	obj->model = new char[15];
	cin.getline(obj->model, 15);
	velikaSlova(obj->model, strlen(obj->model));

}

//Omoguciti ispis elemenata
void ispisCrte(int l)
{

	cout << "+";
	for (size_t i = 0; i < l * 2; i++)
		cout << "-+";
	cout << "-+-+-+-+" << endl;
}

void ispis(obuca *obj, int n)
{
	int l = 15;
	ispisCrte(l);
	cout << "| " << setw(l) << "MODEL" << setw(l / 2) << " | " << setw(l / 2) << "VEL" << setw(l / 2) << " | " << setw(l) << "BOJA" << setw(l + 1) << "|" << endl;
	for (size_t i = 0; i < n; i++)
	{
		ispisCrte(l);
		cout << "| " << setw(l) << obj[i].model << setw(l / 2) << " | " << setw(l / 2) << obj[i].velicina << setw(l / 2) << " | " << setw(l) << obj[i].boja << setw(l + 1) << "|" << endl;
	}
	ispisCrte(l);
}

//Utvrditi koliko je objekata tipa obuca za obiljezija model ima vrijednost sandale
int utvrdiModel(obuca *obj, int n)
{
	int brojac = 0;
	for (size_t i = 0; i < n; i++)
		if (strcmp(obj[i].model, "SANDALE") == 0)
			brojac++;
	return brojac;
}

//Ispisati adrese svih objekata za koje prethodnom funkcijom utvrdite da su sandale
void adreseSandala(obuca *obj, int n)
{
	cout << "Adrese sandala: " << endl;
	for (size_t i = 0; i < n; i++)
		if (strcmp(obj[i].model, "SANDALE") == 0)
			cout << obj << endl;
}

void unosSandala(obuca *obj, obuca *objSandale, int n)
{
	int index = 0;
	for (size_t i = 0; i < n; i++)
		if (strcmp(obj[i].model, "SANDALE") == 0)
			objSandale[index++] = obj[i];
}



//Ne zaboravite dealocirati memeoriju
void dealokacijaMemorije(obuca *&obj, int n)
{
	delete[]obj;
	obj = nullptr;
}

int main()
{
	//Kreirati dinamicki niz objekata tipa obuca
	int x = 3;
	obuca *obj = new obuca[x];
	obuca *objSandale = nullptr;


	for (size_t i = 0; i < x; i++)
		unos(&obj[i]);

	system("CLS");
	ispis(obj, x);

	int sandala = utvrdiModel(obj, x);

	if (sandala != 0)
	{
		cout << "Ukupno ima " << sandala << " sandala." << endl;
		adreseSandala(obj, x);
		objSandale = new obuca[sandala];
		unosSandala(obj, objSandale, sandala);
	}
	else
		cout << "Nema modela sandale u izboru. " << endl;


	ispis(objSandale, sandala);


	if (objSandale != nullptr)
		dealokacijaMemorije(objSandale, sandala);

	dealokacijaMemorije(obj, x);

	system("PAUSE");
	return 0;
}