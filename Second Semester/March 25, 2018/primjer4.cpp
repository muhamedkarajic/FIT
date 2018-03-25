#include <iostream>
using namespace std;

struct Student {
	char ime[30];
	int godinaRodjenja;
	Student *naredni;
};

int main()
{
	Student studenti[4];
	strcpy_s(studenti[0].ime, "First Person");
	studenti[0].godinaRodjenja = 1484;
	studenti[0].naredni = &studenti[1];

	strcpy_s(studenti[1].ime, "Second Person");
	studenti[1].godinaRodjenja = 1344;
	studenti[1].naredni = &studenti[2];

	strcpy_s(studenti[1].naredni->ime, "Third Person");
	studenti[1].naredni->godinaRodjenja = 2342;
	studenti[1].naredni->naredni = &studenti[3];

	strcpy_s(studenti[3].ime, "Forth Person");
	studenti[3].godinaRodjenja = 2345;
	studenti[3].naredni = &studenti[0];

	for (int i = 0; i < 4; i++)
	{
		cout << studenti[i].ime << endl;
		cout << studenti[i].godinaRodjenja << endl;
		cout << endl;
	}

	system("PAUSE");
	return 0;
}