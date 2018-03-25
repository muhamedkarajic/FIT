#include <iostream>
using namespace std;

int Saberi(int a, int b) {
	return a + b;
}

int Oduzmi(int a, int b) {
	return a - b;
}

int main()
{
	int(*pok)(int, int) = nullptr;

	char x;
	cout << "Odaberi sabiranje ili oduzimanje: ";
	cin >> x;
	cin.ignore();
	
	if (x == '+') {
		cout << "5 + 4 = ";
		pok = Saberi; }
	else {
		cout << "5 - 4 =  ";
		pok = Oduzmi; }
	
	cout << pok(5, 4) << endl;
	
	system("PAUSE");
	return 0;
}