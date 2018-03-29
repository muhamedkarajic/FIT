#include <iostream>
using namespace std;

int provjera1()
{
	cout << "provjera1" << endl;
	return 1;
}

int provjera2()
{
	cout << "provjera2" << endl;
	return 2;
}

int(*getFuncPointer(int i))()
{
	if (i == 1)
		return provjera1;
	else
		return provjera2;
}


int main()
{
	const int var = 2;
	int(*nizPokNaFun[var])() = { nullptr };

	for (size_t i = 0; i < var; i++)
		nizPokNaFun[i] = getFuncPointer(i);

	for (size_t i = 0; i < var; i++)
		cout << (nizPokNaFun[i])() << endl;
		
	cout << endl;

	system("PAUSE");
	return 0;
}