#include <iostream>
using namespace std;

struct Student
{
	char ime[30];
	int godinaRodjenja;
};

void ispisPok(Student *pok)
{
	cout << "IspisPok" << endl;
	cout << pok->ime << " - " << pok->godinaRodjenja << endl;
}
void ispisObj(Student ja)
{
	cout << "IspisJa" << endl;
	cout << ja.ime << " - " << ja.godinaRodjenja << endl;
}

int main()
{
	Student ja;

	Student *pok = &ja;

	strcpy_s(pok->ime, "Muhamed Karajic");
	pok->godinaRodjenja = 1996;

	ispisPok(pok);
	ispisObj(ja);

	system("PAUSE");
	return 0;
}