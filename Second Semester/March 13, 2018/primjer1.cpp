#include <iostream>
using namespace std;

int main()
{
	int varijabla = 5;
	int *pointer;

	pointer = &varijabla;

	cout << "ISPIS:" << endl;
	cout << "varijabla: " << varijabla << endl;
	cout << "&varijabla: " << &varijabla << endl;
	cout << "pointer: " << pointer << endl;
	cout << "*pointer: " << *pointer << endl;
	system("PAUSE>0");
	system("CLS");


	cout << "ISPIS \"*pointer++\":" << endl;
	*pointer++;
	cout << "pointer: " << pointer << endl;
	cout << "*pointer: " << *pointer << endl;
	system("PAUSE>0");
	system("CLS");

	cout << "ISPIS \"*pointer--\":" << endl;
	pointer--;
	cout << "pointer: " << pointer << endl;
	cout << "*pointer: " << *pointer << endl;
	system("PAUSE>0");
	system("CLS");

	cout << "ISPIS \"(*pointer)++\":" << endl;
	(*pointer)++;
	cout << "pointer: " << pointer << endl;
	cout << "*pointer: " << *pointer << endl;
	system("PAUSE>0");
	system("CLS");

	cout << "ISPIS \"(*pointer)--\":" << endl;
	(*pointer)--;
	cout << "pointer: " << pointer << endl;
	cout << "*pointer: " << *pointer << endl;
	system("PAUSE>0");
	system("CLS");

	int *p = new int;
	*p = 5;
	cout << "p: " << p << endl;
	cout << "*p: " << *p << endl;
	delete p;

	const int len = 3;
	int *niz = new int[len];
	for (int i = 0; i < len; i++)
	{
		cout << "Unesi niz " << i << " : ";
		cin >> niz[i];
	}

	system("PAUSE>0");
	system("CLS");

	cout << "ISPIS NIZA:" << endl;
	for (int i = 0; i < len; i++)
		cout << "niz " << i << " : " << niz[i] << endl;

	delete[] niz;

	int **dniz = new int*[len];

	for (int i = 0; i < len; i++)
	{
		dniz[i] = new int[len];
	}

	for (int i = 0; i < len; i++)
		for (int j = 0; j < len; j++)
		{

			cout << "Unesi dniz[" << i << "][" << j << "] = ";
			cin >> dniz[i][j];
		}

	cout << "dniz ispis" << endl;
	for (int i = 0; i < len; i++)
		for (int j = 0; j < len; j++)
		{

			cout << "dniz[" << i << "][" << j << "] = " << dniz[i][j] << endl;
		}

	for (int i = 0; i < len; i++)
	{
		delete[] dniz[i];
	}

	delete[] dniz;


	system("PAUSE>0");
	return 0;
}