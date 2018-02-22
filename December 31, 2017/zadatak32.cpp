#include <iostream>
using namespace std;

int povrat(int broj)//10010
{
	int starter = 1;
	int dekadni = 0;
	while (broj > 0)
	{
		if (broj%10==1)
			dekadni += starter;
		
		starter *= 2;
		broj /= 10;
	}
	return dekadni;
}



int main()
{
	int broj;
	cout << "Unesi neki binarni broj: ";
	cin >> broj;

	cout << "Dekadni broj ovog broja je: " << povrat(broj) << endl;


	system("PAUSE");
	return 0;
}