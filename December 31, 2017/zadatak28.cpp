#include <iostream>
using namespace std;

bool znamenka(int broj)
{
	while (broj > 0)
		if (broj%10==5)
			return true;
		else
			broj /= 10;

	return false;
}

int main()
{
	int broj;
	
	cout << "Unesi neki broj: ";
	cin >> broj;

	if (znamenka(broj) == true)
		cout << "Broj sadrzi znamenku 5." << endl;
	else
		cout << "Broj ne sadrzi znamenku 5." << endl;

	system("PAUSE");
	return 0;
}